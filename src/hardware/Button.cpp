#include "Button.hpp"

Button::Button(int pin) : m_pin(pin){}

void Button::begin()
{
  pinMode(m_pin, INPUT_PULLUP);

  m_lastReading = digitalRead(m_pin);
  m_stableState = m_lastReading;
  m_lastChange = millis();
}

bool Button::wasPressed()
{
  const bool reading = digitalRead(m_pin);
  const unsigned long now = millis();

  // le signal vient de changer: on commence par mesurer la stabilité
  if(reading != m_lastReading){
    m_lastReading = reading;
    m_lastChange = now;
  }

  // ignore si changements trop courts
  if(now - m_lastChange < DebounceMs){
    return false;
  }

  // le boutton a reellement changer d'etat 
  if(reading != m_stableState){
    m_stableState = reading;

    // avec INPUT_PULLUP, low signfie appuye
    return m_stableState == LOW;
  }

  return false;
}
