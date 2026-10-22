#include "Interupteur.hpp"

Interupteur::Interupteur(int pin): m_pin(pin){}

void Interupteur::begin()
{
  pinMode(m_pin, INPUT_PULLUP);
}

bool Interupteur::isOn()
{
  const bool reading = digitalRead(m_pin);
  const unsigned long now = millis();


  if(reading != m_lastReading){
    m_lastReading = reading;
    m_lastChange = now;
  }

  if(now - m_lastChange >= DebounceMs){
    m_stableState = reading;
  }

  return m_stableState == LOW;
}