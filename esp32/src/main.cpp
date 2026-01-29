#include <Arduino.h>
#include <array>
#include "configs.h"
#include "sensorse/QTR.h"


QTR Qtr(qtrSensor, qrtMax, qrtMin, qtrLed);

void setup()
{
  // configure the sensors
  Qtr.setup();
  Serial.begin(115200);
}

void loop()
{
  // read raw sensor values
  Qtr.lineDetaction();

  Qtr.linePosition();

  auto pos = Qtr.linePosition();

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(pos[i]);
    Serial.print('\t');
  }
  Serial.println();

  delay(200);
}