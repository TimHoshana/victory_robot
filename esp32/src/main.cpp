
#include <Arduino.h>
#include "configs.h"
#include "engines/motor.h"
#include "drivers/move.h"

Move move;

void setup() {
    move.setup();
};

void loop() {
    speed = 255;
    move.follow(100, 255);
}