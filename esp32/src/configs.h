#include <Arduino.h>


//pins conections
const uint8_t qtrSensor[] = {12, 14, 27, 26, 25, 33, 32, 13}; //pins for QRT sensors
const uint8_t qtrLed = 21; //pin for QRT led emitter

//robot porameters
static uint8_t speed;
enum motorProportions : uint8_t {propLeft, propRight}; //отнасительноя разнеца в скоростях мотора.

//QTR-A8 calibration values
const uint16_t qrtMax[] = {153, 135, 128, 127, 143, 88, 104, 147};
const uint16_t qrtMin[] = {4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095};