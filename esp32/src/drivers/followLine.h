#include <Arduino.h>
#include "move.h"
#include "configs.h"
#include "sensorse/QTR.h"

class FollowLine{
    private:
    int _deraction;
    uint16_t _linePosition;
    Move *_move;
    QTR *_qtr;

    uint8_t shiftLeft;
    uint8_t shiftRight;
    uint8_t shiLeft;
    uint8_t shiRight;
    uint8_t lineThickness;

    
    public:
    FollowLine(Move *move, QTR *qtr);
    void printData();
    void setup();
    void findDeraction();
    void follow();
};