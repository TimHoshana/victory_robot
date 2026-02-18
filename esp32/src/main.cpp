#include <Arduino.h>
#include <Wire.h>
#include "configs.h"
#include "engines/motor.h"
#include "drivers/move.h"
#include "drivers/followLine.h"
#include "sensorse/Ultrasonic.h"
#include "drivers/obstacle.h"

// 🔹 ПРОТОТИПЫ ЗАДАЧ
void Task1code(void * parameter);
void Task2code(void * parameter);

const uint8_t NANO_RIGHT_ADDR = 0x04;
const uint8_t NANO_LEFT_ADDR = 0x05;

Move move;
QTR *Qtr = new QTR(qtrSensor, qrtMax, qrtMin, qtrLed);

FollowLine followLine(&move, Qtr);
Obstacle obsticale(&move, Qtr);

TaskHandle_t Task1;
TaskHandle_t Task2;



void colorCheck(uint8_t ADRESS){
    static unsigned long lastUpdate = 0;
    const long interval = 20; // Опрос каждые 20 мс (50 раз в секунду)
    
    if (millis() - lastUpdate >= interval) {
      lastUpdate = millis();
    
      // Запрашиваем 3 байта у Nano
      Wire.requestFrom((uint8_t)ADRESS, 3);
    
      if (Wire.available() == 3) {
        uint8_t r = Wire.read();
        uint8_t g = Wire.read();
        uint8_t b = Wire.read();
    
        Serial.print(r == 0 ? "White" : r==1 ? "Blech" : r== 3 ? "Red" : "Green");
      }
    }
}




void setup() {
    Serial.begin(115200);

    move.setup();
    followLine.setup();
    obsticale.setup();
    // Инициализация I2C на ESP32 (SDA, SCL)
    // По умолчанию SDA - 21, SCL - 22. Можно изменить: Wire.begin(SDA_PIN, SCL_PIN);
    Wire.begin(); 
    Wire.setClock(400000); 
    
    Serial.println("I2C Master Ready. Reading from Nano...");


    xTaskCreatePinnedToCore(
        Task1code,
        "Task1",
        10000,
        NULL,
        1,
        &Task1,
        0
    );

    xTaskCreatePinnedToCore(
        Task2code,
        "Task2",
        10000,
        NULL,
        1,
        &Task2,
        1
    );
}

void Task1code(void * parameter) {
    for (;;) {
        if(!obsticale.obstacleDietacted()){
          followLine.findDeraction();
        }
        else
          obsticale.findDeraction();
        obsticale.distanceCheck();
        //followLine.printData();


        colorCheck(NANO_RIGHT_ADDR);
        colorCheck(NANO_LEFT_ADDR);
  // Здесь ESP32 может делать другую работу, цикл не заблокирован!
        vTaskDelay(1); //  очень желательно
    }
}   

void Task2code(void *parameter) {
    for (;;) {
        if(!obsticale.obstacleDietacted())
          followLine.follow(255);
        obsticale.obstaceAvoidance(255);
        vTaskDelay(1); //  очень желательно

    }
} 

void loop() {
    vTaskDelay(portMAX_DELAY);
}