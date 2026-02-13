#include <Arduino.h>
#include "obstacle.h"

Obstacle::Obstacle(Move *move, QTR *qtr) : FollowLine(move, qtr){
}

void Obstacle::setup(){
        sonicF->setup();
        sonicL->setup();
}
bool Obstacle::obstacleDietacted(){
        return stage != checkout;
}
void Obstacle::findDeraction(){
    FollowLine::findDeraction();
    sonicF->distanceCheck();
    sonicL->distanceCheck();
}


void Obstacle::obstaceAvoidance(short _speed){
    switch (stage)
    {
        case(checkout):
            if (sonicF->getDistanceMM() < 350)
              stage = gotoPosition;
            break;
        
        case(gotoPosition):
            if(sonicL->getDistanceMM() > 270  && sonicL->getDistanceMM() < 390){
              stage = detour;
              break;
            }
            else
              _move->follow(_speed, 255);
            break;
        
        case(detour):
            if(!lineThickness){
              stage = lineBack;
              break;
            }
            _move->follow(speed, 350-sonicL->getDistanceMM());
            break;
        case(lineBack):
            if (sonicL->getDistanceMM() > 800)
              stage = checkout;
            _move->follow(_speed, _deraction);
    }
}