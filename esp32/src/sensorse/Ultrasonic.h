#include "Arduino.h"

class Ultrasonic{
private:
  float timing = 0.0;
  uint8_t _trig_pin;
  uint8_t _echo_pin;
  uint16_t _distance_mm;
public:
  Ultrasonic(const uint8_t trig_pin, const uint8_t echo_pin);
  void setup();
  void distanceCheck();
  uint16_t getDistanceMM() { return _distance_mm; }
};