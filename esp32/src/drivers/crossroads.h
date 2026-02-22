#include <Arduino.h>
#include "sensorse/colorReceiving.h"
#include "config.h"

enum  deractions : uint8_t {forward, left, right, turnaround};
enum color : uint8_t {white, black, grey, red, green};


class Crossroads {
    private:
    Move *_move;
    QTR *_qtr;
    color leftColor;
    color rightColor;
    public:
    Crossroads(Move *move, QTR *qtr);
    void setup();
    void colorCheck();
    void follow(short speed);
};  