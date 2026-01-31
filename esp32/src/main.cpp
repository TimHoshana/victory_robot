
#include <Arduino.h>
#include "configs.h"
#include "engines/motor.h"
#include "drivers/move.h"

Move move;

void setup() {
    move.setup();
};

void loop() {
    move.follow(210, -10);
}