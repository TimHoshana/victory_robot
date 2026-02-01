#include <Arduino.h>
#include "move.h"

class FollowLine{
    private:
    uint16_t _deraction;
    uint16_t _linePosition;
    Move *_move;
    public:
    FollowLine(Move *move);
    void findDeraction();
    void follow();
};