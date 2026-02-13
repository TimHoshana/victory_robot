#pragma once
#include <Arduino.h>


//pins conections
extern const uint8_t qtrSensor[]; //pins for QRT sensors
extern const uint8_t qtrLed; //pin for QRT led emitter

//motors pins
extern const uint8_t M1_IN1;  // IN1 dricer pin for motor 1
extern const uint8_t M1_IN2 ; // IN2 dricer pin for motor 1
extern const uint8_t M2_IN1; // IN3 driver pin for motor 2
extern const uint8_t M2_IN2; // IN4 driver pin for motor 2

//color senser
extern const uint8_t colorSens1;
extern const uint8_t colorSens2;

//distance sensors
//front
extern const uint8_t trigF;
extern const uint8_t echoF;
//Left
extern const uint8_t trigL;
extern const uint8_t echoL;

//robot porameters
extern uint8_t speed;
extern uint8_t rotationPawer; //отнасительноя разнеца в градусах для поворота.
enum motorProportions : uint8_t {propLeft, propRight}; //отнасительноя разнеца в скоростях мотора.

//QTR-A8 calibration val;
extern uint16_t qrtMax[];;
extern uint16_t qrtMin[];