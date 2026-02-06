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
    public:
    FollowLine(Move *move, QTR *qtr);
    void setup();
    void findDeraction();
    void follow();
};