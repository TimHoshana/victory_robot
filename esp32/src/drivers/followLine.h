#pragma once
#include <Arduino.h>
#include "move.h"
#include "configs.h"
#include "sensorse/QTR.h"

enum rotations : short{
    forword = 0,
    left = 255,
    right = -255
};

class FollowLine{
    protected:
    int _deraction;
    uint16_t _linePosition;
    Move *_move;
    QTR *_qtr;

    uint8_t shiftLeft;
    uint8_t shiftRight;
    uint8_t shiLeft;
    uint8_t shiRight;
    uint8_t lineThickness;

    void shiftCheck();
    
    public:
    rotations Shift;

    FollowLine(Move *move, QTR *qtr);
    void printData();
    void setup();
    void findDeraction();
    void follow(short speed);
};