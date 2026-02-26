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

void Crossroads::colorCheck(){
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
    Serial.print(rightBecameGreen);
    if (leftBecameGreen){
        deraction = Left;
        crossDelay = millis() + delayPower;
    }
    else if (rightBecameGreen){
        deraction = Right;
        crossDelay = millis() + delayPower;
    }

    if (crossDelay < millis() && deraction != Turnback)
         deraction = Forward;

    if (deraction){
        if(rightBecameGreen && rightBecameGreen)
            deraction = Turnback;
        else if(deraction == Right && leftBecameGreen)
            deraction = Turnback;   
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
        if (lineThickness && !lastLineThickness)
            deraction = Forward;
        break;
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