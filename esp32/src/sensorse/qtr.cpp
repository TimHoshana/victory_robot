#include "QTR.h"

QTR::QTR(const uint8_t qtrSensors[], const uint16_t qrtMax[], const uint16_t qrtMin[], uint8_t qtrLed)
{
    for (uint8_t i = 0; i < SensorCount; i++) {
        _qtrSensor[i] = qtrSensors[i];
        _qrtMax[i] = qrtMax[i];
        _qrtMin[i] = qrtMin[i];
    }
    _qtrLed = qtrLed;
}

void QTR::setup(){
    qtr.setTypeAnalog();
    qtr.setSensorPins(_qtrSensor, SensorCount);
    qtr.setEmitterPin(_qtrLed);
}

void QTR::lineDetaction(){
    qtr.read(sensorValues);
    for (uint8_t i = 0; i < SensorCount; i++)
    {
        _linePosition[i] = map(sensorValues[i], _qrtMax[i], _qrtMin[i], 255, 0);
    }
}

std::array<uint8_t, SensorCount> QTR::linePosition()
{
    std::array<uint8_t, SensorCount> linePos;
    for (uint8_t i = 0; i < SensorCount; i++) {
        linePos[i] = _linePosition[i];
    }
    return linePos;
}