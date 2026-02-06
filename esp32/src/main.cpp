
#include <Arduino.h>
#include "configs.h"
#include "engines/motor.h"
#include "drivers/move.h"
#include "drivers/followLine.h"

Move move;
QTR *Qtr = new QTR(qtrSensor, qrtMax, qrtMin, qtrLed);
FollowLine followLine(& move, Qtr);


void setup() {
    move.setup();
    followLine.setup(); 
    Serial.begin(115200);
};

void loop() {
    followLine.findDeraction();
    followLine.follow();
}