#include <Wire.h>
#include "ColorSens.h"

// Пины датчика
ColorSens colorSens1(4, 5, 6, 7, 8); 

// Массив для хранения RGB (3 байта)
byte rgbValues[3];

// Функция, которая вызывается, когда ESP32 запрашивает данные
void requestEvent() {
  Wire.write(rgbValues, 3); 
}


void setup() {
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  colorSens1.begin();
  
  // Инициализация I2C (Адрес 0x08)
  Wire.begin(0x04); 
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
  rgbValues[1] = colorSens1.getGreen(); // Добавь в класс метод getGreen() { return greenColor; }
  rgbValues[2] = colorSens1.getBlue();  // Добавь в класс метод getBlue() { return blueColor; }

  colorSens1.printData();
}

