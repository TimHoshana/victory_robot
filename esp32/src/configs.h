#include <Arduino.h>


//pins conections
const uint8_t qtrSensor[] = {12, 14, 27, 26, 25, 33, 32, 13}; //pins for QRT sensors
const uint8_t qtrLed = 21; //pin for QRT led emitter

//motors pins
const uint8_t M1_IN1 = 5;  // IN1 dricer pin for motor 1
const uint8_t M1_IN2 = 17; // IN2 dricer pin for motor 1
const uint8_t M2_IN1 = 18; // IN3 driver pin for motor 2
const uint8_t M2_IN2 = 19; // IN4 driver pin for motor 2


//robot porameters
static uint8_t speed;
enum motorProportions : uint8_t {propLeft, propRight}; //отнасительноя разнеца в скоростях мотора.

//QTR-A8 calibration values
static uint16_t qrtMax[] = {173, 164, 166, 161, 171, 116, 113, 163};
static uint16_t qrtMin[] = {4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095};