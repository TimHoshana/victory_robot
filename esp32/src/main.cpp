
#include <Arduino.h>
#include "configs.h"
#include "drivers/move.h"
#include "drivers/followLine.h"

Move *move = new Move();
FollowLine follow(move);

void setup() {
    move->setup();
};

void loop() {
    follow.findDeraction();
}