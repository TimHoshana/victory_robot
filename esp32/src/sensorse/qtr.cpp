#include "Arduino.h"
#include "QTR.h"

QTR::QTR(const uint8_t qtrSensors[], const uint16_t qrtMax_[], const uint16_t qrtMin_[], uint8_t qtrLed)
{
    for (uint8_t i = 0; i < SensorCount; i++) {
        _qtrSensor[i] = qtrSensors[i];
        _qrtMax[i] = qrtMax_[i];
        _qrtMin[i] = qrtMax_[i];
    }
    _qtrLed = qtrLed;
};

void QTR::setup(){
    qtr.setTypeAnalog();
    qtr.setSensorPins(_qtrSensor, SensorCount);
    qtr.setEmitterPin(_qtrLed);
}

void QTR::lineDetaction(){
  qtr.read(sensorValues);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
      _linePosition[i] = map(sensorValues[i], _qrtMin[i], _qrtMin[i], 255, 0);
  }
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(_linePosition[i]);
    Serial.print('\t');
  }
  Serial.println();
}

std::array<uint8_t, SensorCount> QTR::linePosition() const
{
    std::array<uint8_t, SensorCount> linePos;
    for (uint8_t i = 0; i < SensorCount; i++) {
        linePos[i] = _linePosition[i];
    }
    return linePos;
}