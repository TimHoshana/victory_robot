#include <Arduino.h>
#include "configs.h"
#include "engines/motor.h"
#include "drivers/move.h"
#include "drivers/followLine.h"

// 🔹 ПРОТОТИПЫ ЗАДАЧ
void Task1code(void * parameter);
void Task2code(void * parameter);

Move move;
QTR *Qtr = new QTR(qtrSensor, qrtMax, qrtMin, qtrLed);
FollowLine followLine(&move, Qtr);

TaskHandle_t Task1;
TaskHandle_t Task2;



void setup() {
    
    pinMode(colorSens1, INPUT);
    pinMode(colorSens2, INPUT);
    Serial.begin(115200);

    move.setup();
    followLine.setup();

    

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
        Serial.print(", "+String(analogRead(colorSens1))+ " "+String(analogRead(colorSens2)));
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