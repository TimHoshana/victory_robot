#include "Arduino.h"

class Ultrasonic{
private:
  float timing = 0.0;
  uint8_t _trig_pin;
  uint8_t _echo_pin;
public:
  Ultrasonic(const uint8_t trig_pin, const uint8_t echo_pin);
  void setup();
  uint16_t distance();
};