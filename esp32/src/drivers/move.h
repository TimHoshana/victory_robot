#pragma once
#include <Arduino.h>
#include "configs.h"
#include "engines/motor.h"


class Move{
private:
    const uint8_t pos(int value) {
        return (value > 0) ? value : 0;
    }
public:
    
    Motor *motor1 = new Motor(M1_IN1, M1_IN2, 0, 1);
    Motor *motor2 = new Motor(M2_IN2, M2_IN1, 2, 3);
    uint8_t motorSpeed = speed;
    void setup(){
        motor1->setup();
        motor2->setup();
    }
    void follow(int _speed, int deraction){
        
        int robotSpeed = (motorSpeed*pos(uint8_t(_speed)-uint8_t(deraction))) / (255);
        int derSpeed = (_speed*deraction*motorSpeed) / 65025;
        motor1->Go(robotSpeed-2*derSpeed);
        motor2->Go(robotSpeed+2*derSpeed);
    }
    void go(int speed){
        motor1->Go(speed);
        motor2->Go(speed);
    }
}; 