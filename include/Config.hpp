#pragma once

namespace Config {
  // config bluetooth
  constexpr char BluetoothName[] = "Resonance TSF";
  constexpr int I2sBckPin = 26; // audio data biy clock
  constexpr int I2sWsPin = 25; // audio data left and right clock
  constexpr int I2sDataOutPin = 22; // ESP32 audio data output -> to speaker

  constexpr int SerialSpeed = 115200;

  // config button on/off 
  constexpr int PinButton = 13;
}