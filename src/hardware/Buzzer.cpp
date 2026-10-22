#include <Buzzer.hpp>

Buzzer::Buzzer(int pin): m_pin(pin){}

void Buzzer::begin()
{
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, LOW);
}

void Buzzer::start()
{
  tone(m_pin, 1500, 150);
}

void Buzzer::startBluetoothAlert()
{
  tone(m_pin, 2000, 150);
}

void Buzzer::stop()
{
  noTone(m_pin);
}

void Buzzer::connectedBluetoothAlert()
{
  tone(m_pin, 3000, 150);
}

void Buzzer::lostConnectedBluetoothAlert(){
  tone(m_pin, 500, 150);
}