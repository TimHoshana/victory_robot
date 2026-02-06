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
    uint8_t shiLeft;
    uint8_t shiRight;
    uint8_t lineThickness;
    _qtr->lineDetaction();

    _qtr->linePosition();
  
    auto pos = _qtr->linePosition();
    

    for (uint8_t i = 0; i < 8; i++)
    {
        lineThickness += (pos[i] == 255);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
        shiftLeft += (pos[4-i] == 255)*(i+1);
        shiftRight += (pos[4+i] == 255)*(i+1);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
        if (pos[4-i] == 255)
        {
            shiLeft = i+1;
            break;
        }
    }
    for (uint8_t i = 0; i < 4; i++)
    {
        if (pos[4+i] == 255)
        {
            shiRight = i+1;
            break;
        }
    }
    if (lineThickness < 3)
    {
        Serial.println(String(shiLeft)+", "+String(shiRight)+", "+String(lineThickness)+", "+String((shiLeft- shiRight)*25));
        _deraction = (shiLeft- shiRight)*25;
    }
    else
    {
        Serial.println(String(shiftLeft)+", "+String(shiftRight)+", "+String(lineThickness)+", "+String((shiLeft- shiRight)*25));
        _deraction = (shiftLeft - shiftRight)/lineThickness;
    }

}

void FollowLine::follow(){
    _move->follow(15, -_deraction);
}