#include "Bluetooth.hpp"

using namespace std;

// définition du constructeur
Bluetooth::Bluetooth( const std::string& name,
                      int bckPin,
                      int wsPin,
                      int dateOutPin)
  :m_name(name)
{
  m_pinConfig.mck_io_num = I2S_PIN_NO_CHANGE;
  m_pinConfig.bck_io_num = bckPin;
  m_pinConfig.ws_io_num = wsPin;
  m_pinConfig.data_out_num = dateOutPin;
  m_pinConfig.data_in_num = I2S_PIN_NO_CHANGE;
};

void Bluetooth::begin()
{
  m_sink.set_pin_config(m_pinConfig);
  m_sink.start(m_name.c_str());
};

void Bluetooth::stop(){
  m_sink.end(false);
}

bool Bluetooth::isConnected(){
  return m_sink.is_connected();
}