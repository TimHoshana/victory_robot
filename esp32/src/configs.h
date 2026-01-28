#include <Arduino.h>


//pins conections
const uint8_t qtrSensor[] = {12, 14, 27, 26, 25, 33, 32, 13}; //pins for QRT sensors
const uint8_t qtrLed = 21; //pin for QRT led emitter
const uint16_t miN[] = {4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000};
const uint16_t maX[] = {1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023};

//robot porameters
static uint8_t speed;
enum motorProportions : uint8_t {propLeft, propRight}; //отнасительноя разнеца в скоростях мотора.