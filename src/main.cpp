#include <Arduino.h>
#include <Bluetooth.hpp>
#include <Config.hpp>
#include <Button.hpp>
#include <Led.hpp>
#include <Buzzer.hpp>


Bluetooth bluetooth(Config::BluetoothName, Config::I2sBckPin, Config::I2sWsPin, Config::I2sDataOutPin);
Button onOffButton(Config::PinButton);
Led led(Config::PinLed);
Buzzer buzzer(Config::PinBuzzer);

bool isRunning = false;

void setup(){
  Serial.begin(Config::SerialSpeed);
  onOffButton.begin();
  led.begin();
  buzzer.begin();
}

void loop(){
  if(onOffButton.wasPressed()){
    isRunning = !isRunning;

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
