#include <Arduino.h>
#include "followLine.h"


FollowLine::FollowLine(Move *move, QTR *qtr){
    _move = move;
    _qtr = qtr;
};

void FollowLine::setup(){
    _qtr->setup();
}

void FollowLine::findDeraction(){
    uint8_t shiftLeft;
    uint8_t shiftRight;
    _qtr->lineDetaction();

    _qtr->linePosition();
  
    auto pos = _qtr->linePosition();
  
    for (uint8_t i = 0; i < 4; i++)
    {
        shiftLeft += (pos[4-i] == 255)*(i+1);
        shiftRight += (pos[4+i] == 255)*(i+1);
    }
    Serial.println(String(shiftLeft)+", "+String(shiftRight));
}