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
    void colorCheck();
    void crossing(short speed, uint8_t lineThickness);
    void printData();
    bool cross(){
        return deraction != Forward;
    }
};  