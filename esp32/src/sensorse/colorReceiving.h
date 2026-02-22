#include <Arduino.h>

void colorCheck(uint8_t ADRESS, uint8_t &color){
    static unsigned long lastUpdate = 0;
    const long interval = 20; // Опрос каждые 20 мс (50 раз в секунду)
    
    if (millis() - lastUpdate >= interval) {
      lastUpdate = millis();
    
      // Запрашиваем 3 байта у Nano
      Wire.requestFrom((uint8_t)ADRESS, 1);
    
      if (Wire.available() == 1) {
        color = Wire.read();
        
      }
    }
}