#include <Arduino.h>

enum colors : uint8_t {white, black, grey, red, green};

inline void fetchColorI2C(uint8_t ADRESS, colors &color){
    static unsigned long lastUpdate = 0;
    const long interval = 20; // Опрос каждые 20 мс (50 раз в секунду)
    
    if (millis() - lastUpdate >= interval) {
      lastUpdate = millis();
    
      // Запрашиваем 3 байта у Nano
      Wire.requestFrom((uint8_t)ADRESS, (uint8_t)1);
    
      if (Wire.available() == 1) {
        color = (colors)Wire.read();
        
      }
    }
}