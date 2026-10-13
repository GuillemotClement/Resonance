#include <Arduino.h>
#include <Bluetooth.hpp>
#include <Config.hpp>
#include <Button.hpp>
#include <Led.hpp>

Bluetooth bluetooth(Config::BluetoothName, Config::I2sBckPin, Config::I2sWsPin, Config::I2sDataOutPin);
Button onOffButton(Config::PinButton);
Led led(Config::PinLed);

bool isRunning = false;

void setup(){
  Serial.begin(Config::SerialSpeed);
  onOffButton.begin();
  led.begin();
}

void loop(){
  if(onOffButton.wasPressed()){
    isRunning = !isRunning;

    if(isRunning){
      bluetooth.begin();
      Serial.println("Bluetooth allumé");
      led.start();
    } else {
      bluetooth.stop();
      Serial.println("Bluetooth éteint");
      led.stop();
    }
  }
}