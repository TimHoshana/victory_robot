#include "ColorSens.h"



ColorSens::ColorSens(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t out) {
      S0 = s0; S1 = s1; S2 = s2; S3 = s3; sensorOut = out;
}

void ColorSens::contrastCheck(){
  maxColor = 0;
  minColor = 255;
  for(uint8_t i = 0; i < 2; i++){
    if(Colors[i] > Colors[maxColor]){
      maxColor = i;
    }
    if(Colors[i] < Colors[minColor]){
      minColor = i;
    }
  }
  contrast = constrain((Colors[maxColor]), 0, 255) - constrain(Colors[minColor], 0, 255);
}

color ColorSens::colorCheck(){
  if(contrast < 40){
    if(Colors[0] > 128){
      return white;
    } else{
      return bleck;
    }
  }
  else{
    if(maxColor ==  0){
      return red;
    }
    else{
      return green;
    }
  }
}

void ColorSens::begin() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);  // Масштабирование частоты 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}


void ColorSens::readData() {
  // Читаем КРАСНЫЙ
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  redColor = map(redFrequency, 23, 225, 255, 0);
  Colors[0] = constrain(abs(redColor), 0, 255);
  // Читаем ЗЕЛЕНЫЙ
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency, 24, 234, 255, 0);
  Colors[1] = constrain(abs(greenColor),0, 255);

  contrastCheck();
}


void ColorSens::printData() {
  Serial.print("R = "); Serial.print(redColor);
  Serial.print(" G = "); Serial.print(greenColor);
  Serial.print(" Contrast = " + String(colorCheck()));

  if(contrast < 40){
    if(Colors[0] > 128){
      Serial.println(" - White detected!");
      digitalWrite(9, LOW);
    } else{
      Serial.println(" - Bleck detected");
      digitalWrite(9, LOW);
    }
  }
  else{
    if(maxColor ==  0){
      Serial.println(" - RED detected!");
      digitalWrite(9, HIGH);}
    else{
      Serial.println(" - GREEN detected!");
      digitalWrite(9, HIGH);}
  }
}



