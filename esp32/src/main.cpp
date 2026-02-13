#include <Arduino.h>
#include "configs.h"
#include "engines/motor.h"
#include "drivers/move.h"
#include "drivers/followLine.h"
#include "sensorse/Ultrasonic.h"

// 🔹 ПРОТОТИПЫ ЗАДАЧ
void Task1code(void * parameter);
void Task2code(void * parameter);

Move move;
QTR *Qtr = new QTR(qtrSensor, qrtMax, qrtMin, qtrLed);
FollowLine followLine(&move, Qtr);

TaskHandle_t Task1;
TaskHandle_t Task2;

Ultrasonic sonic1(2, 4); 
Ultrasonic sonic2(21, 15); 



void setup() {
    Serial.begin(115200);

    move.setup();
    followLine.setup();
    sonic1.setup();
    sonic2.setup();

    
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
        followLine.findDeraction();
        sonic1.distanceCheck();
        sonic2.distanceCheck();
        Serial.println("Front: "+String(sonic1.getDistanceMM())+" Left side: "+String(sonic2.getDistanceMM()));
        vTaskDelay(1); //  очень желательно
    }
}   

void Task2code(void *parameter) {
    for (;;) {
        followLine.follow();
        vTaskDelay(1); //  очень желательно
    }
}

void loop() {
    vTaskDelay(portMAX_DELAY);
}