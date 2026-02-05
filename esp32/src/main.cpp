#include <Arduino.h>
#include <array>
#include "configs.h"
#include "sensorse/Ultrasonic.h"

Ultrasonic sonic1(2, 4); 
Ultrasonic sonic2(21, 15); 


void setup()
{
  Serial.begin(115200);
  sonic1.setup();
  sonic2.setup();
}

void loop()
{
  sonic1.distanceCheck();
  sonic2.distanceCheck();
  Serial.println(String(sonic2.getDistanceMM())+", ");
  delay(200);
}