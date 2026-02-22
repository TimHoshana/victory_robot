#include <Wire.h>
#include "ColorSens.h"
#include "configs.h"

const uint8_t LED_PIN = 9; // Пин для индикации работы (можешь использовать любой другой)


// Пины датчика
ColorSens colorSens1(S0, S1, S2, S3, sensorOut, LED_PIN);

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
  colorSens1.readData();
  
  // Сохраняем значения в массив для быстрой передачи
  // (Здесь используются публичные или геттер-методы, если они есть. 
  // В твоем классе переменные private, поэтому я предполагаю, что ты добавил геттеры или сделал их public)
  // Для примера запишем их в массив:
  rgbValues[0] = colorSens1.colorCheck();
  colorSens1.printData();
}

