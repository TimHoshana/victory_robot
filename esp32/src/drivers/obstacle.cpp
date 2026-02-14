#include <Arduino.h>
#include "obstacle.h"
#include "configs.h"

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
void Obstacle::distanceCheck(){
    sonicF->distanceCheck();
    sonicL->distanceCheck();
}


void Obstacle::obstaceAvoidance(short _speed){
    short dir = ((800-(sonicL->getDistanceMM()))/5);
    switch (stage)
    {
        case(checkout):
            if (sonicF->getDistanceMM() < 500)
              stage = gotoPosition;
            break;
        
        case(gotoPosition):
            if(sonicL->getDistanceMM() > 200  && sonicL->getDistanceMM() < 840){
              stage = detour;
              break;
            }
            else
              _move->follow(_speed, 255);
            break;
        
        case(detour):
            if(lineThickness>3){
              stage = lineBack;
              break;
            }
            _move->follow(_speed, (dir < -90 ? -90 : dir));
            break;

        case(lineBack): 
            if (sonicL->getDistanceMM() > 800)
              stage = checkout;
            _move->follow(_speed, abs(_deraction));
    }
    
    
}
void Obstacle::printSonicData(){
    Serial.print("Front "+String(sonicF->getDistanceMM()));
    Serial.print(" Left "+String(sonicL->getDistanceMM()));
    Serial.println();
    //Serial.println("   "+ String(dir < -90 ? -90 : dir)+" "+String(stage)+"    ");
}