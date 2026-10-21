#pragma once 

#include <Arduino.h>

class Buzzer{
  public:

    explicit Buzzer(int pin);
    void begin();
    void start();
    void stop();
    void startBluetoothAlert();
    void connectedBluetoothAlert();
    void lostConnectedBluetoothAlert();

  private:
    int m_pin;
};
