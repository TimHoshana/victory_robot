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

    bool linPosetion[8] = {false, false, false, false, false, false, false, false};
    _qtr->lineDetaction();

    _qtr->linePosition();
  
    auto pos = _qtr->linePosition();
    

    for (uint8_t i = 0; i < 8; i++)
    {
        if(pos[i] == 255){
            lineThickness++;
            linPosetion[i] = true;
        }

    }
    for (uint8_t i = 0; i < 4; i++)
    {
        shiftLeft += (linPosetion[4-i])*(i+1);
        shiftRight += (linPosetion[4+i])*(i+1);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
        if (linPosetion[4-i])
        {
            shiLeft = i+1;
            break;
        }
    }
    for (uint8_t i = 0; i < 4; i++)
    {
        if (linPosetion[4+i])
        {
            shiRight = i+1;
            break;
        }
    }
    
    _deraction = lineThickness < 3 ? (shiLeft- shiRight)*20 : (shiftLeft - shiftRight)*25;

}

void FollowLine::follow(){
    _move->follow(15, -_deraction);
}