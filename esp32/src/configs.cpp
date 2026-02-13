#include "configs.h"

// QTR
const uint8_t qtrSensor[8] = {12, 14, 27, 26, 25, 33, 32, 13};//pins for QRT sensors
const uint8_t qtrLed = 21;//pin for QRT led emitter


// motors
const uint8_t M1_IN1 = 5;  // IN1 dricer pin for motor 1
const uint8_t M1_IN2 = 17; // IN2 dricer pin for motor 1
const uint8_t M2_IN1 = 18; // IN3 driver pin for motor 2
const uint8_t M2_IN2 = 19; // IN4 driver pin for motor 2

//Color senser
const uint8_t colorSens1 = 35;
const uint8_t colorSens2 = 34;

//distance sensors 
//Front
const uint8_t trigF = 2;
const uint8_t echoF = 4;
//Left
const uint8_t trigL = 15;
const uint8_t echoL = 21;


//robot porameters
uint8_t speed = 250; //отнасительноя разнеца в градусах для поворота.
uint8_t rotationPawer = 24; //отнасительноя разнеца в градусах для поворота.

// QTR calibration
uint16_t qrtMax[8] = {233, 1023, 1023, 705, 894, 625, 945, 187};
uint16_t qrtMin[8] = {4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095};

