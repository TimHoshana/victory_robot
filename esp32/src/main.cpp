#include <Arduino.h>
#include <QTRSensors.h>
#include "configs.h"
#include "sensorse/qtr.h"


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

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(Qtr.linePosition()[i]);
    Serial.print('\t');
  }
  Serial.println();

  delay(250);
}