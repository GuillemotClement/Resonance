#include <Buzzer.hpp>

Buzzer::Buzzer(int pin): m_pin(pin){}

void Buzzer::begin()
{
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, LOW);
}

void Buzzer::start()
{
  tone(m_pin, 2000);
}

void Buzzer::startBluetoothAlert()
{
  tone(m_pin, 2000, 150);
}

void Buzzer::stop()
{
  noTone(m_pin);
}
