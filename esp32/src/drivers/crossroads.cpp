#include "crossroads.h"

Crossroads::Crossroads(Move *move){
    _move = move;
}

void Crossroads::begin(){
    Wire.begin(); 
    Wire.setClock(400000); 
}

void Crossroads::colorCheck(){
    static color lastLeftColor;
    static color lastRightColor;

    colorCheck(NANO_LEFT_ADDR, rightColor);
    colorCheck(NANO_RIGHT_ADDR, leftColor);
    if (leftColor == green && lastLeftColor == white)
        deraction = left;
    else if (leftColor == green && lastLeftColor == white)
        deraction = right;
    if((deraction == left || deraction == right) && 
       (leftColor != green || rightColor != green))
        deraction = forward;
    lastLeftColor = leftColor;
    lastRightColor = rightColor;
}