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
    void setup();
    bool obtacleDietacted();
    void obstaceAvoidance(short speed);
};