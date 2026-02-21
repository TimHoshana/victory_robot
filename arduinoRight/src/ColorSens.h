#ifndef COLORSENS_H
#define COLORSENS_H

#include <Arduino.h>
#include "configs.h"

enum color : uint8_t {white, bleck, grey, red, green};

class ColorSens {
  private:
    uint8_t S0, S1, S2, S3, sensorOut, ledPin_;
    int redFrequency = 0, greenFrequency = 0, blueFrequency = 0;
    int redColor = 0, greenColor = 0, blueColor = 0;

    uint16_t Colors[3] = {2, 2, 2};
    uint8_t contrast;

    void contrastCheck();

    uint16_t maxColor;
    uint16_t minColor;

  public:
    
    ColorSens(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t out, uint8_t ledPin);
    
    void begin();
    void readData();
    color colorCheck();
    void printData();

    uint8_t getRed(){
      return redColor;
    }
    uint8_t getGreen(){
      return greenColor;
    }
    uint8_t getBlue(){
      return blueColor;
    }
};

#endif