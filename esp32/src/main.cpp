/*
Author  : Andrea Lombardo
Site    : https://www.lombardoandrea.com
Source  : https://github.com/AndreaLombardo/L298N/

Here you can see how to work in a common configuration without the needed of Enable pin. 

Make sure your module has a jumper in place.

When L298N has a jumper instead of Enable pin, the speed is always 255.

Wiring schema in file "L298N - Schema_without_EN_pin.png"
*/

// Include the library
#include <L298N.h>
#include <Arduino.h>

// Pin definition
const uint8_t IN1 = 5;
const uint8_t IN2 = 17;
const uint8_t IN3 = 18;
const uint8_t IN4 = 19;

// Create one motor instance

void setup() {
  // put your setup code here, to run once:
   pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void motorLoop(int val, uint8_t pinIn1, uint8_t pinIn2) {
  val = map(val, 0, 1023, -255, 255);
  if (val > 0){
    analogWrite(pinIn2, val);
    digitalWrite(pinIn1, 0);
  }
  else if (val < 0){
    analogWrite(pinIn2, 255+val);
    digitalWrite(pinIn1, 1);
  }
  else {
    digitalWrite(pinIn1, 0);
    digitalWrite(pinIn2, 0);
  }
}

void loop() {
  motorLoop(600, IN1, IN2); // Move motor 1 forward at speed 100
  motorLoop(5, IN3, IN4); // Move motor 2 backward at speed 150
}

