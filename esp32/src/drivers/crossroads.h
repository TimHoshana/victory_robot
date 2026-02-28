#include <Arduino.h>
#include "Wire.h"
#include "sensorse/colorReceiving.h"
#include "Move.h"
#include "config.h"
#include <iostream>
#include <cmath> 

enum  deractions : uint8_t {Forward, Left, Right, Turnback};

class Crossroads {
    private:
    Move *_move;
    deractions deraction;

    colors leftColor;
    colors rightColor;
    uint32_t crossDelay;

    
    public:
    Crossroads(Move *move);
    void begin();
    void colorCheck(uint8_t lineThickness);
    void crossing(short speed, uint8_t lineThickness);
    void printData();
    bool cross(){
        return deraction != Forward;
    }
    void printMode (){
        Serial.print("Left: ");
        Serial.print(leftColor == 0 ? "White " : leftColor==1 ? "Black " : leftColor== 3 ? "Red" : "Green ");
        Serial.print("Right: ");
        Serial.print(rightColor == 0 ? "White" : rightColor==1 ? "Black " : rightColor== 3 ? "Red" : "Green ");
    }
};  