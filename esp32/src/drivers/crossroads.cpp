#include "crossroads.h"
#include <iostream>
#include <cmath> 

Crossroads::Crossroads(Move *move){
    _move = move;
}

void Crossroads::begin(){
    Wire.begin(); 
    Wire.setClock(400000); 
}

void Crossroads::colorCheck(uint8_t lineThickness){
    static colors lastLeftColor;
    static colors lastRightColor;
    static bool turn;
    static bool rightBecameGreen;
    static bool leftBecameGreen;
    if(turn){
        fetchColorI2C(NANO_RIGHT_ADDR, rightColor);
        turn = false;}
    else{
        fetchColorI2C(NANO_LEFT_ADDR, leftColor);
        turn = true;}

    rightBecameGreen = rightColor == green  && lastRightColor == white;
    leftBecameGreen = leftColor == green && lastLeftColor == white;
    Serial.print(deraction);
    if (leftColor == green && lineThickness > 3 && deraction == Forward){
        deraction = Left;
        crossDelay = millis() + delayPower;
    }
    else if (rightColor == green && lineThickness > 3 && deraction == Forward){
        deraction = Right;
        crossDelay = millis() + delayPower;
    }

    if (crossDelay < millis())
         deraction = Forward;

    if (leftColor == green && rightColor == green && lineThickness > 4){
        deraction = Turnback;
        crossDelay = millis() + (4*delayPower)/2;
    }
    lastLeftColor = leftColor;
    lastRightColor = rightColor;
}

void Crossroads::crossing(short speed, uint8_t lineThickness){
    static uint8_t lastLineThickness;
    switch (deraction)
    {
    case Left:
        _move->follow(speed, -crossRotatioonPower);
        break;
    case Right:
        _move->follow(speed, crossRotatioonPower);
        break;
    case Turnback:
        _move->follow(speed, 255);
    }  
    
    lastLineThickness = lineThickness;
}

void Crossroads::printData(){
    Serial.print("Left: ");
    Serial.print(leftColor == 0 ? "White " : leftColor==1 ? "Black " : leftColor== 3 ? "Red" : "Green ");
    Serial.print(" Right: ");
    Serial.print(rightColor == 0 ? "White" : rightColor==1 ? "Black " : rightColor== 3 ? "Red" : "Green ");
    Serial.print(" Deraction: ");
    Serial.println(deraction == Forward ? "Forward" : deraction == Left ? "Left" : deraction == Right ? "Right" : "Turnback");
}