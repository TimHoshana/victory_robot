#include "crossroads.h"

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
    
    if(turn){
        fetchColorI2C(NANO_LEFT_ADDR, rightColor);
        turn = false;}
    else{
        fetchColorI2C(NANO_RIGHT_ADDR, leftColor);
        turn = true;}

    bool rightBecameGreen = rightColor == green  && lastRightColor == white;
    bool leftBecameGreen = leftColor == green && lastLeftColor == white;
    Serial.print(rightBecameGreen);
    if (leftBecameGreen)
        deraction = Left;
    else if (rightBecameGreen)
        deraction = Right;
    if((deraction == Left || deraction == Right) && 
       (leftColor != green && rightColor != green))
        deraction = Turnback;

    
    if (deraction){
        if(deraction == Left && rightBecameGreen)
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