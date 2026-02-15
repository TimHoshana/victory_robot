#pragma once
#include <Arduino.h>
#include "followLine.h"
#include "sensorse/Ultrasonic.h"
#include "configs.h"

enum stages : uint8_t {checkout, gotoPosition, detour, lineBack};

class Obstacle : public FollowLine{
    private:
    Ultrasonic *sonicF = new Ultrasonic(trigF, echoF); 
    Ultrasonic *sonicL = new Ultrasonic(trigL, echoL); 
    stages stage = checkout;
    public:
    Obstacle(Move *move, QTR *qtr);
    
    void setup();
    void distanceCheck();
    void findDeraction();
    bool obstacleDietacted();
    void obstaceAvoidance(short _speed, uint16_t _stopDistance = stopDistance, uint16_t _rotationRadius = rotationRadius);
    void printSonicData();
};