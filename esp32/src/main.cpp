
#include <Arduino.h>
#include "configs.h"
#include "sensorse/motor.h"


Motor *motor1 = new Motor(M1_IN1, M1_IN2);
Motor *motor2 = new Motor(M2_IN2, M2_IN1);


void setup() {
    motor1->setup();
    motor2->setup();
};

void loop() {
    motor1->Go(20);
    motor2->Go(-20);
}