#include <Arduino.h>


//pins conections
const uint8_t qrtSensor[] = {13, 12, 14, 23, 26, 25, 25, 32}; //pins for QRT sensors




//robot porameters
static uint8_t speed;
enum motorProportions : uint8_t {propLeft, propRight};