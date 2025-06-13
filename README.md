# ESP32 com processador do algoritmo de filtragem e comunicação dos 3 eixos pela UART.

Este projeto demonstra como o ESP32 pode processar a lib especifica* para o MPU9250 e se comunicar com outro MCU usando protocolo UART e ou Bluetooth Low Energy (BLE).

## 🛠 Requisitos
- IDE Arduino configurada para ESP32
- Biblioteca BLE (`ESP32 BLE Arduino`)
- Biblioteca MPU9250 SparkFunMPU9250-DMP.h (https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library/blob/master/examples/MPU9250_Basic/MPU9250_Basic.ino)
- Placa ESP32
- Módulo MPU9250
- 
![Ligação sistema IMU com outro MCU](https://github.com/user-attachments/assets/86e27040-5016-4a91-9800-6b3e374b33e7)

  
## 📂 Estrutura
- `ESP32_IMU_SERIAL/`: código main
- `src/`: pasta da lib do MPU apenas o necessário!

## 🚀 Como usar
1. Abra o código em `ESP32_IMU_SERIAL.ino` e envie para um ESP32
2. Veja a comunicação via monitor serial.
3. Caso queira comunicação bluetooth e ver no celular por exemplo: #define HABILITAR_BLUETOOTH
4. Comente esta linha para desabilitar o Bluetooth e ele não será compilado no codigo main #define HABILITAR_BLUETOOTH  
5. Abra o código receptor no Arduino Due e veja os dados ja processados com filtros
6. App (sugestão) caso queria ver os dados em dispositivos android https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&pcampaignid=web_share

Alguns comandos da bilbioteca que podem ser uteis:


  // Use setGyroFSR() e setAccelFSR() para configurar
  // as faixas de escala completa do giroscópio e do acelerômetro.
  // As opções do giroscópio são +/- 250, 500, 1000 ou 2000 dps
  
  imu.setGyroFSR(2000); // Defina o giroscópio para 2000 dps
  
  
  // As opções de aceleração são +/- 2, 4, 8 ou 16 g
  imu.setAccelFSR(2); // Set accel to +/-2g

  // Nota: o FSR do magnetômetro do MPU-9250 é definido em
  // +/- 4912 uT (micro-tesla)


  // setLPF() pode ser usado para definir o filtro passa-baixa digital
  // do acelerômetro e do giroscópio.
  // Pode ser qualquer um dos seguintes: 188, 98, 42, 20, 10, 5
  // (os valores estão em Hz).
  imu.setLPF(5); // Defina a frequência de canto do LPF para 5 Hz

  // A taxa de amostragem do acel/giroscópio pode ser definida usando
  // setSampleRate. Os valores aceitáveis ​​variam de 4 Hz a 1 kHz
  imu.setSampleRate(10); // Set sample rate to 10Hz

  // Da mesma forma, a taxa de amostragem da bússola (magnetômetro) pode ser
  // definida usando a função setCompassSampleRate().
  // Este valor pode variar entre: 1-100Hz
  imu.setCompassSampleRate(10); // Defina a taxa de mag para 10 Hz


## 📄 Licença
Este projeto está licenciado sob a Licença MIT.
