#include <Arduino.h>
#include <QTRSensors.h>

class QTR{
    private:
    uint16_t _linePosition[8];
    public:
    static void calibration();
    void setup();
    void lineDetaction();
};