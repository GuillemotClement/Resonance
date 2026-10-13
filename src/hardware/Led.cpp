#include "Led.hpp"

Led::Led(int pin): m_pin(pin){}

void Led::begin()
{
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, LOW);
}

void Led::start()
{
  digitalWrite(m_pin, HIGH);
}

void Led::stop(){
  digitalWrite(m_pin, LOW);
}
