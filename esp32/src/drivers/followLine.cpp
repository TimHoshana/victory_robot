#include <Arduino.h>
#include "followLine.h"


FollowLine::FollowLine(Move *move, QTR *qtr){
    _move = move;
    _qtr = qtr;
};

void FollowLine::setup(){
    _qtr->setup();
}

void FollowLine::shiftCheck(bool Pos[8]){
    if (lineThickness != 0){
        if(false){
            Shift = forword;
        }
        else if (shiftLeft > shiftRight)
        {
            Shift = left;
        } else
        {
            Shift = right;
        } 
    }
}


void FollowLine::findDeraction(){
    

    bool linPosetion[8] = {false, false, false, false, false, false, false, false};
    _qtr->lineDetaction();

    _qtr->linePosition();
  
    auto pos = _qtr->linePosition();
    shiftLeft = 0;
    shiftRight = 0;
    shiLeft = 0;
    shiRight = 0;
    lineThickness = 0;
    

    for (uint8_t i = 0; i < 8; i++)
    {
        if(pos[i] == 255){
            lineThickness++;
            linPosetion[i] = true;
        } 

    }
    for (uint8_t i = 0; i < 4; i++)
    {
        shiftLeft += (linPosetion[3-i]);
        shiftRight += (linPosetion[4+i]);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
        if (linPosetion[3-i])
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
    shiftCheck(linPosetion);
    int shiftDeraction = (shiLeft - shiRight);
    _deraction = shiftDeraction*rotationPawer;
    //_deraction = lineThickness < 3 ? (shiLeft- shiRight)*25 : (shiftLeft - shiftRight)*25;
}

void FollowLine::printData(){

    for (uint8_t i = 0; i < 8; i++)
    {
        Serial.print(String(_qtr->linePosition()[i]==255) + " ");
    }
    Serial.println(":    " +String(shiftLeft) + " " + String(shiftRight) + ",  " + String(shiLeft) + " " + String(shiRight) 
    + " " + String(lineThickness) + " " + String(_deraction)+ " " + 
    String(Shift == forword ? "forword" : (Shift == left ? "left" : "right")));
}

void FollowLine::follow(short speed){     
    if(lineThickness != 0)
      _move->follow(speed, _deraction);
    else
      _move->follow(speed, Shift);
}