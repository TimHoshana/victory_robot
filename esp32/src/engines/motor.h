#pragma once
#include <Arduino.h>

class Motor {
private:
    uint8_t IN1;
    uint8_t IN2;

    uint8_t channel1;
    uint8_t channel2;

public:
    Motor(uint8_t in1, uint8_t in2, uint8_t ch1, uint8_t ch2)
        : IN1(in1), IN2(in2), channel1(ch1), channel2(ch2) {}

    void setup() {
        ledcSetup(channel1, 20000, 8); // 20 kHz, 8 бит
        ledcSetup(channel2, 20000, 8);

        ledcAttachPin(IN1, channel1);
        ledcAttachPin(IN2, channel2);
    }

    void Go(int val) {
        
        val =  map(val, 255, -255, 180, -180)+(val>0 ? 1 : -1)*75;

        if (val > 0) {
            ledcWrite(channel1, 0);
            ledcWrite(channel2, val);
        }
        else if (val < 0) {
            ledcWrite(channel1, -val);
            ledcWrite(channel2, 0);
        }
        else {
            ledcWrite(channel1, 0);
            ledcWrite(channel2, 0);
        }
    }
};