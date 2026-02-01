#include <Arduino.h>
#include "followLine.h"
FollowLine::FollowLine(Move *move){
    _move = move;
};

void FollowLine::findDeraction(){
    _move->follow(20, 50);
}