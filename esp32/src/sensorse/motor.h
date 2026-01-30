#include <arduino.h>

class Motor {
private:
    const uint8_t IN1;
    const uint8_t IN2;

    uint8_t positive(int value) {
        return (value > 0) ? value : -value;
    }
public:
    Motor(uint8_t in1, uint8_t in2)
        : IN1(in1), IN2(in2) {
    }
    void setup() {
        pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
    }
    void setSpeed(int val) {
        bool motorGo = (micros() % 8160 < 400 + (positive(val) * 28));
        if (motorGo && val > 0) {
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
        } else if (motorGo && val < 0) {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
        } else {
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
        }
    }
}