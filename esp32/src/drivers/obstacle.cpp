#include <Arduino.h>
#include "obstacle.h"

void Obstacle::setup(){
        sonicF->setup();
        sonicL->setup();
}
bool Obstacle::obtacleDietacted(){
        return stage != checkout;
}
void Obstacle::obstaceAvoidance(short _speed){
    switch (stage)
    {
        case(checkout):
            if (sonicF->getDistanceMM() < 350)
              stage = gotoPosition;
            break;
        
        case(gotoPosition):
            if(sonicL->getDistanceMM() > 2700  && sonicL->getDistanceMM() < 3900){
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