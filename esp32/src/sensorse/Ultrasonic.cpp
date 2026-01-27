#include "Ultrasonic.h"
Ultrasonic::Ultrasonic(const uint8_t trig_pin, const uint8_t echo_pin){
  _trig_pin = trig_pin;
  _echo_pin = echo_pin;
}
void Ultrasonic::setup(){
  pinMode(_echo_pin, INPUT);
  pinMode(_trig_pin, OUTPUT);
  
  digitalWrite(_trig_pin, LOW);
}
void Ultrasonic:: distanceCheck(){
    digitalWrite(_trig_pin, HIGH);
    digitalWrite(_trig_pin, LOW);
    timing = pulseIn(_echo_pin, HIGH);
    _distance_mm = (timing * 3.4) / 2;
}