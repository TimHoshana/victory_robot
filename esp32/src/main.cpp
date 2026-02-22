#include <Arduino.h>
#include <Wire.h>
#include "configs.h"
#include "engines/motor.h"
#include "drivers/move.h"
#include "drivers/followLine.h"
#include "sensorse/Ultrasonic.h"
#include "drivers/obstacle.h"
#include "sensorse/colorReceiving.h"

// 🔹 ПРОТОТИПЫ ЗАДАЧ
void Task1code(void * parameter);
void Task2code(void * parameter);

Move move;
QTR *Qtr = new QTR(qtrSensor, qrtMax, qrtMin, qtrLed);

FollowLine followLine(&move, Qtr);
Obstacle obsticale(&move, Qtr);

TaskHandle_t Task1;
TaskHandle_t Task2;


uint8_t rightColor = 0;
uint8_t leftColor = 0;






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
    static bool turn;
    for (;;) {
        if(!obsticale.obstacleDietacted()){
          followLine.findDeraction();
        }
        else
          obsticale.findDeraction();
        obsticale.distanceCheck();
        //followLine.printData();


        if(turn){
            colorCheck(NANO_LEFT_ADDR, rightColor);
            turn = false;
        }
        else{
            colorCheck(NANO_RIGHT_ADDR, leftColor);
            turn = true;
        } 
        Serial.print(leftColor == 0 ? "White " : leftColor==1 ? "Black " : leftColor== 3 ? "Red" : "Green ");
        Serial.print(" Left: ");
        Serial.print(rightColor == 0 ? "White" : rightColor==1 ? "Black " : rightColor== 3 ? "Red" : "Green ");
        //Serial.println();
        followLine.printData();
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