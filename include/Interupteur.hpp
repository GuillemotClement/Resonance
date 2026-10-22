#pragma once 

#include <Arduino.h>

class Interupteur {
  public: 
    explicit Interupteur(int pin);

    void begin();
    bool isOn();

    private:
      int m_pin;
      bool m_lastReading = HIGH;
      bool m_stableState = HIGH;
      unsigned long m_lastChange = 0;
      static constexpr unsigned long DebounceMs = 30;
};