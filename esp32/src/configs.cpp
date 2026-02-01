#include "configs.h"

// QTR
const uint8_t qtrSensor[8] = {12, 14, 27, 26, 25, 33, 32, 13};//pins for QRT sensors
const uint8_t qtrLed = 21;//pin for QRT led emitter


// motors
const uint8_t M1_IN1 = 5;  // IN1 dricer pin for motor 1
const uint8_t M1_IN2 = 17; // IN2 dricer pin for motor 1
const uint8_t M2_IN1 = 18; // IN3 driver pin for motor 2
const uint8_t M2_IN2 = 19; // IN4 driver pin for motor 2


//robot porameters
uint8_t speed = 150;

// QTR calibration
uint16_t qrtMax[8] = {173, 164, 166, 161, 171, 116, 113, 163};
uint16_t qrtMin[8] = {4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095};