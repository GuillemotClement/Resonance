#pragma once

#include <Arduino.h>

class Led 
{
  public:
    explicit Led(int pin);  

    void begin();
    void start();
    void stop();

  public:
    int m_pin;
};


