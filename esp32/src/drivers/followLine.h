#include <Arduino.h>

class FollowLine{
    private:
    uint16_t _deraction;
    uint16_t _linePosition;
    public:
    void findDeraction();
    void follow();
};