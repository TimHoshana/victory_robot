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
    uint8_t positive(int value) {
        return (value > 0) ? value : -value;
    }

    static Motor *motor1 = new Motor(M1_IN1, M1_IN2);
    static Motor *motor2 = new Motor(M2_IN2, M2_IN1);
public:
    static uint8_t motorSpeed = speed;
    static void setup(){
        motor1->setup();
        motor2->setup();
    }
    static void follow(int _speed, int deraction){
        int robotSpeed = map(_speed, -255, 255, -1, 1)*motorSpeed*map(positive(deraction), 0, 255, 1, 2);
        motor1->Go(robotSpeed + map(_speed, -255, 255, -1, 1)*deraction)
        motor2->Go(robotSpeed - map(_speed, -255, 255, -1, 1)*deraction)
    }
};