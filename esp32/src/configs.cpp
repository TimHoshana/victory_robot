#include "configs.h"

// QTR
const uint8_t qtrSensor[8] = {12, 14, 27, 26, 25, 33, 32, 13};
const uint8_t qtrLed = 21;

// motors
const uint8_t M1_IN1 = 5;
const uint8_t M1_IN2 = 17;
const uint8_t M2_IN1 = 18;
const uint8_t M2_IN2 = 19;

// robot
uint8_t speed = 150;

// QTR calibration
uint16_t qrtMax[8] = {173, 164, 166, 161, 171, 116, 113, 163};
uint16_t qrtMin[8] = {4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095};