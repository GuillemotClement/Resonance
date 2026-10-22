#include <Arduino.h>
#include <Bluetooth.hpp>
#include <Config.hpp>
#include <Button.hpp>
#include <Led.hpp>
#include <Buzzer.hpp>
#include <Interupteur.hpp>

Bluetooth bluetooth(Config::BluetoothName, Config::I2sBckPin, Config::I2sWsPin, Config::I2sDataOutPin);
Button onOffButton(Config::PinButton);

Led led(Config::PinLed);
Buzzer buzzer(Config::PinBuzzer);
Interupteur inter(Config::PinButton);

bool isRunning = false;

void setup(){
  Serial.begin(Config::SerialSpeed);
  // onOffButton.begin();
  inter.begin();
  led.begin();
  buzzer.begin();
}

void loop(){

  const bool requestedRunning = inter.isOn();


  if(requestedRunning != isRunning){
    isRunning = requestedRunning;

    if(isRunning){
      bluetooth.begin();
      buzzer.startBluetoothAlert();
      Serial.println("Bluetooth allumé");
      led.start();
    } else {
      buzzer.stop();
      bluetooth.stop();
      Serial.println("Bluetooth éteint");
      led.stop();
    }
  }
}
