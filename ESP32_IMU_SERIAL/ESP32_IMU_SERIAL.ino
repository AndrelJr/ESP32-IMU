// Codigo do ESP32 para envio dos eixos X,Y,Z para o DUE
// Data da criação: 31/08/2021
// Atualização 1.4
// Biblioteca usada https://github.com/AndrelJr/SparkFun_MPU-9250-DMP_Arduino_Library
// https://github.com/AndrelJr/ESP32-IMU/tree/main

#include "src/SparkFunMPU9250-DMP.h"

int flag = 0;


MPU9250_DMP imu;

void setup(){
  Serial.begin(115200); // DEBUG  (Saida no serial monitor para análise)

  Serial2.begin(9600, SERIAL_8N1, 16, 17);// UART Comunicação com o DUE a mesma taxa deve estar selecionada no MCU receptor!
  //Inicialização do modulo MPU9250.
  imu.begin(); 
  
  imu.dmpBegin(DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_GYRO_CAL,20); // Taxa de atualização de 20 Hz, vai até 200 HZ
  pinMode(2,OUTPUT);//Led indicador de atividade, fica alternando conforme o fluxo de dados.
}

void loop(){
  //FIFO
  FIFOIMU();
  
  flag = Serial2.read();//
  if(flag == 1){
  comunicacaoTX();//Função de envio para o Due
  digitalWrite(2, !digitalRead(2));
  }
  flag = 0;
  
  delay(1);//Delay para evitar travamentos
}


void FIFOIMU(void){
    if ( imu.fifoAvailable() ){
    // Use dmpUpdateFifo to update the ax, gx, mx, etc. values
    if ( imu.dmpUpdateFifo() == INV_SUCCESS){
      imu.computeEulerAngles();
    }
  }
}


void comunicacaoTX(void){
  //Função de comunicação  
  String VariavelX =  String(imu.roll, 2); //Rolamento //Se quiser simular use String(random(20));
  String VariavelY =  String(imu.pitch, 2);//Arfagem
  String VariavelZ =  String(imu.yaw, 2);  //Guinada
  
  Serial.println(VariavelX + "," + VariavelY + "," + VariavelZ + ","); //DEBUG Serial monitor
  Serial2.println(VariavelX + "," + VariavelY + "," + VariavelZ + "," "/");
}



