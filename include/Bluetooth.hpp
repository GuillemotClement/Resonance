#pragma once 

#include <string>
#include <BluetoothA2DPSink.h> // fournis la classe de la lib
#include <driver/i2s.h> // fournit la struct de configuration


class Bluetooth {
  public: 

  Bluetooth(
    const std::string& name, // passe le name par reference
    int bckPin,
    int wsPin,
    int dataOutPin
  ); // constructeur

  void begin();
  void stop();

  private:
  std::string m_name;
  i2s_pin_config_t m_pinConfig{};
  BluetoothA2DPSink m_sink;
};