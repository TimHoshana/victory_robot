#include <Wire.h>
#include "ColorSens.h"
#include "configs.h"

const uint8_t LED_PIN = 9; // Пин для индикации работы (можешь использовать любой другой)


// Пины датчика
ColorSens colorSens1(S0, S1, S2, S3, sensorOut, LED_PIN);
const uint8_t colorRegisterDelay = 100;

// Массив для хранения RGB (3 байта)
byte rgbValues[3];


// Функция, которая вызывается, когда ESP32 запрашивает данные
void requestEvent() {
  Wire.write(rgbValues, 1); 
}


void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  colorSens1.begin();

  
  // Инициализация I2C (Адрес 0x08)
  Wire.begin(ADDRESS); 
  // Регистрация функции отправки данных
  Wire.onRequest(requestEvent); 
}


void loop() {
  static color lastColor;
  static uint32_t bleckDelay;
  static uint32_t colorDelayDate;
  static uint8_t bleckRegister;
  colorSens1.readData();
  
  // Сохраняем значения в массив для быстрой передачи
  // (Здесь используются публичные или геттер-методы, если они есть. 
  // В твоем классе переменные private, поэтому я предполагаю, что ты добавил геттеры или сделал их public)
  // Для примера запишем их в массив:
  color colorDetact = colorSens1.colorCheck();
  
  if(colorDetact == bleck){
    bleckRegister++;
  }
  else if(colorDetact == white){
    bleckRegister = 0;
  }
  Serial.print(bleckRegister);
  if(colorDetact == bleck && bleckRegister > 5){
    bleckDelay = millis() + colorRegisterDelay;
  }
  if(colorDetact == green){
      colorDelayDate = millis() + colorRegisterDelay;
  }

  if(colorDelayDate > millis()){
    rgbValues[0] = green;
    Serial.print("green");
  }
  else{
    rgbValues[0] = white;
  }
  colorSens1.printData();
  lastColor = colorDetact;
}

