#include <Arduino.h>
#include "Wire.h"
#include "sensorse/colorReceiving.h"
#include "Move.h"
#include "config.h"

enum  deractions : uint8_t {Forward, Left, Right, Turnback};

class Crossroads {
    private:
    Move *_move;
    deractions deraction;

    colors leftColor;
    colors rightColor;

    
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