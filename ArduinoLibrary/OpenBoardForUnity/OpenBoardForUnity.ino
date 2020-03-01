#include "OpenBoardForUnity.h"

#include "SoftwareSerial.h"

// Not using the PIN 2&3 for Bluetooth purpose
PinsToFollowGroupedInfo arduinoUno((int[]) {
  4, 5, 6, 7, 8, 9, 10, 11, 12
}, 9, (int[]) {
  A0, A1, A2, A3, A4, A5
}, 6);
PinsToFollowGroupedInfo arduinoNano((int[]) {
  4, 5, 6, 7, 8, 9, 10, 11, 12
}, 9, (int[]) {
  A0, A1, A2, A3, A4, A5, A6, A7
}, 8);
//PinsToFollowGroupedInfo arduinoMega((int[]){4,5,6,7,8,9,10,11,12,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53},41,(int[]){A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15},16);

// I remove the pin 5 of digital because there is only one 5V pin for current on Micro Pro and we need one for set on/off light for light sensor.
// Custom your own if you prefer using the 5 or set the light elsewhere.
PinsToFollowGroupedInfo arduinoProClassic((int[]) {
  4, 6, 7, 8, 9, 10, 15, 14, 16
}, 9, (int[]) {
  A0, A1, A2, A3
}, 4);
PinsToFollowGroupedInfo arduinoProFullAnalog((int[]) {
  7, 15, 14, 16
}, 4, (int[]) {
  A0, A1, A2, A3, 4, 6, 8, 9, 10
}, 8);
PinsToFollowGroupedInfo arduinoProFullDigital((int[]) {
  4, 6, 7, 8, 9, 10, 21, 20, 19, 18, 15, 14, 16, 10
}, 14, (int[]) {}, 0);

PinsToFollowGroupedInfo custom((int[]) {
  4, 6, A2
}, 3, (int[]) {
  A0, A1
}, 2);


DeviceDigitalPinsState digital (custom);
DeviceAnalogPinsState analog (custom);
HardwareConfiguration hardware(10, 11, custom, 13);

int frame = 0;
void setup() {

  hardware.startSerialAndBluetooth(9600);
 
}

void loop() {

  delay(500);
  DebugDeviceInfo();
//  frame++;
  
//  hardware.setLightOn(frame % 2 == 0);
if(hardware.getBluetoothSerial()->available()){
    char c = hardware.getBluetoothSerial()->read();
    if(c=='0')
      hardware.setLightOn(false);
    if(c=='1')
      hardware.setLightOn(true);
  
  Serial.print("READ: ");
  Serial.println(c);
}
  hardware.println("Tick");

  
}

void DebugDeviceInfo() {
  Serial.println(" ");
  Serial.println("Frame Start: ");
  for (int i = 0; i < digital.getPinsCount(); i++) {

    Serial.print(digital.m_listeningToPins[i]);
  }
  Serial.println(digital.getPinsCount());

  for (int i = 0; i < digital.getPinsCount(); i++) {

    digital.getPinInfo(i).refreshWithHardwareValue();
    String pinDebug = "Pin:";
    pinDebug.concat(i);
    pinDebug.concat(": ");
    pinDebug.concat(digital.getPinInfo(i).getPinNumber());
    pinDebug.concat(": ");
    pinDebug.concat(digital.getPinInfo(i).getHardwareValue());
    pinDebug.concat(" ");
    pinDebug.concat(digital.getPinInfo(i).getCurrentValue());
    hardware.println(pinDebug);
    if (digital.getPinInfo(i).hasValueChange()) {
      String s = "Switch ";
      s.concat (i);
      s.concat(" ");
      s.concat(digital.getPinInfo(i).getHardwareValue());
      Serial.println(s);
    }
  }


  for (int i = 0; i < analog.getPinsCount(); i++) {

    analog.getPinInfo(i).refreshWithHardwareValue();
    String pinDebug = "Analog:";
    pinDebug.concat(i);
    pinDebug.concat(": ");
    pinDebug.concat(analog.getPinInfo(i).getPinNumber());
    pinDebug.concat(": ");
    pinDebug.concat(analog.getPinInfo(i).getCurrentValueAsOneDigit());
    pinDebug.concat("/");
    pinDebug.concat(analog.getPinInfo(i).getHardwareValue());
    pinDebug.concat(" ");
    pinDebug.concat(analog.getPinInfo(i).getCurrentValue());
    hardware.println(pinDebug);
    if (analog.getPinInfo(i).hasIsHighValueChange()) {
      String s = "Switch ";
      s.concat (i);
      s.concat(" ");
      s.concat(analog.getPinInfo(i).getHardwareValue());
      Serial.println(s);
    }
  }


  Serial.println("Frame Stop");
  Serial.println(" ");
}
