#include <Arduino.h>
#include "configs.h"

enum rotationDirection : uint16_t{
    forword,
    backward,
    left,
    right
};

class Motors{
    public:
    static uint8_t motorSpeed;
    static void setup();
    static void follow(uint8_t speed, uint16_t deraction);
};