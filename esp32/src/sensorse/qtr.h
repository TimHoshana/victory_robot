#include <Arduino.h>
#include <QTRSensors.h>
#include "configs.h"


const uint8_t SensorCount = 8;

class QTR {

    private:
    uint8_t _linePosition[SensorCount];
    uint8_t _qtrSensor[SensorCount];
    uint8_t _qtrLed;
    QTRSensors qtr;
    uint16_t sensorValues[SensorCount];
    public:

    static uint16_t _qrtMax[SensorCount];
    static uint16_t _qrtMin[SensorCount];

    QTR(const uint8_t qtrSensors[], const uint16_t qrtMax[], const uint16_t qrtMin[], uint8_t qtrLed) ;
    std::array<uint8_t, SensorCount> linePosition();
    void calibration();
    void setup();
    void lineDetaction();
};