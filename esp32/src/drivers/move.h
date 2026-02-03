#pragma once
#include <Arduino.h>
#include "configs.h"
#include "engines/motor.h"

enum rotationDirection : uint16_t{
    forword,
    backward,
    left,
    right
};

class Move{
private:
    const uint8_t pos(int value) {
        return (value > 0) ? value : 0;
    }
public:
    
    Motor *motor1 = new Motor(M1_IN1, M1_IN2);
    Motor *motor2 = new Motor(M2_IN2, M2_IN1);
    uint8_t motorSpeed = speed;
    void setup(){
        motor1->setup();
        motor2->setup();
    }
    void follow(int _speed, int deraction){
        
        int robotSpeed = (motorSpeed*pos(_speed-deraction)) / (255);
        int derSpeed = (_speed*deraction) / 255;
        motor1->Go(robotSpeed+derSpeed);
        motor2->Go(robotSpeed-derSpeed);
    }
}; 