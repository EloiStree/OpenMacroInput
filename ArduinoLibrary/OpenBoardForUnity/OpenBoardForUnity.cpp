#include "OpenBoardForUnity.h"
#include "Arduino.h"
#include "SoftwareSerial.h"



////////////////////////////Digital PIN MANAGEMENT////////////////////////////////////
     DigitalPin::DigitalPin (int pinNumber=0)// Define the pin to listen to
     {
      m_currentValue=false;
	  m_previousValue = false; 
	  setListenedPin(pinNumber);
	  
     }
	 void DigitalPin::setListenedPin(int pin) {
		 m_pinNumber = pin;
		 setAsPullUp();
	 }
     void DigitalPin::setAsPullUp(){
        pinMode(m_pinNumber, INPUT_PULLUP);
     }
     bool DigitalPin::getHardwareValue() // Check the value on the Arduino
     {
      return digitalRead(m_pinNumber);
     }
     void DigitalPin::setWithNewValue(bool value) // Allow to the new value and so the previous one
     {
		 m_previousValue = m_currentValue;
      m_currentValue = value;
     }
     bool DigitalPin::getCurrentValue() // recover the current store value
     {
      return m_currentValue;
     }
     bool DigitalPin::getPreviousValue() // recover the previous value store
     {
      return m_previousValue;
     }
     void DigitalPin::refreshWithHardwareValue() // use getHardware and setValue
     {
      setWithNewValue(getHardwareValue());
     }
     bool DigitalPin::hasValueChange() // quick check is store value has changed
     {
       return (m_currentValue != m_previousValue);
     }
	 int DigitalPin::getPinNumber() {
		 return m_pinNumber;
	 }
	 DeviceDigitalPinsState::DeviceDigitalPinsState(PinsToFollowGroupedInfo pinsToFollow) {

		 DeviceDigitalPinsState::init(pinsToFollow.m_digitalPins, pinsToFollow.m_digitalCount);
	 }
	 DeviceDigitalPinsState::DeviceDigitalPinsState(int pinToListen[], int arraySize) {
	
		 DeviceDigitalPinsState::init(pinToListen, arraySize);
	 }
	 void DeviceDigitalPinsState::init(int pinToListen[], int arraySize) {
	 
		 m_pinsCount = arraySize;
		 m_stateOfPins = new  DigitalPin[m_pinsCount];
		 m_listeningToPins = new int[m_pinsCount];
		 for (int i = 0; i < m_pinsCount; i++)
		 {
			 m_listeningToPins[i] = pinToListen[i];
			 m_stateOfPins[i].setListenedPin(pinToListen[i]);
		 }
	 }
	 int DeviceDigitalPinsState::getPinsCount() {
		 return m_pinsCount;
	 } 
	 bool DeviceDigitalPinsState::getPinState(int index) {
		 if (index >= m_pinsCount)
			 index = m_pinsCount - 1;
		 if (index < 0)
			 index = 0;
		 return m_stateOfPins[index].getCurrentValue();
	 }
	 DigitalPin& DeviceDigitalPinsState::getPinInfo(int index) {
		 if (index >= m_pinsCount)
			 index = m_pinsCount - 1;
		 if (index < 0)
			 index = 0;
		 return m_stateOfPins[index];
	 }


	 ////////////////////////////Analog PIN MANAGEMENT////////////////////////////////////

	 AnalogPin::AnalogPin(int pinNumber , int threshold)// Define the pin to listen to
	 {
		 m_currentIsHighValue = false;
		 m_previousIsHighValue = false;
		 setThreshold(threshold);
		 setListenedPin(pinNumber);

	 }
	 void AnalogPin::setListenedPin(int pin) {
		 m_pinNumber = pin;
		 setAsPullUp();
	 }
	 void AnalogPin::setAsPullUp() {
		 pinMode(m_pinNumber, INPUT_PULLUP);
	 }
	 int AnalogPin::getHardwareValue() // Check the value on the Arduino
	 {
		 return analogRead(m_pinNumber);
	 }
	 int AnalogPin::getCurrentValue() {
		 return m_analogValue;
	 }
	 int AnalogPin::getCurrentValueAsOneDigit() {
		 return (int)((double) m_analogValue /  102.4);
	 }

	 void AnalogPin::setWithNewValue(int value) // Allow to the new value and so the previous one
	 {
		 m_analogValue = value;
	 }

	 void AnalogPin::setIsHightWithNewValue(bool value) // Allow to the new value and so the previous one
	 {
		 m_previousIsHighValue = m_currentIsHighValue;
		 m_currentIsHighValue = value;
	 }
	 bool AnalogPin::getIsHighCurrentValue() // recover the current store value
	 {
		 return m_currentIsHighValue;
	 }
	 bool AnalogPin::getIsHighPreviousValue() // recover the previous value store
	 {
		 return m_previousIsHighValue;
	 }
	 void AnalogPin::refreshWithHardwareValue() // use getHardware and setValue
	 {
		 int value = getHardwareValue();
		 setWithNewValue(value);
		 setIsHightWithNewValue(value >= m_threshold);
	 }
	 bool AnalogPin::hasIsHighValueChange() // quick check is store value has changed
	 {
		 return (m_currentIsHighValue != m_previousIsHighValue);
	 }
	 int AnalogPin::getPinNumber() {
		 return m_pinNumber;
	 }
	 void AnalogPin::setThreshold(int value) {
		 m_threshold = value;
	 }

	 //---------------------
	 DeviceAnalogPinsState::DeviceAnalogPinsState(PinsToFollowGroupedInfo pinsToFollow) {

		 DeviceAnalogPinsState::init(pinsToFollow.m_analogPins, pinsToFollow.m_analogCount);
	 }
	 DeviceAnalogPinsState::DeviceAnalogPinsState(int pinToListen[], int arraySize) {

		 DeviceAnalogPinsState::init(pinToListen, arraySize);
	 }
	 void DeviceAnalogPinsState::init(int pinToListen[], int arraySize) {

		 m_pinsCount = arraySize;
		 m_stateOfPins = new  AnalogPin[m_pinsCount];
		 m_listeningToPins = new int[m_pinsCount];
		 for (int i = 0; i < m_pinsCount; i++)
		 {
			 m_listeningToPins[i] = pinToListen[i];
			 m_stateOfPins[i].setListenedPin(pinToListen[i]);
		 }
	 }
	 int DeviceAnalogPinsState::getPinsCount() {
		 return m_pinsCount;
	 }
	
	 AnalogPin& DeviceAnalogPinsState::getPinInfo(int index) {
		 if (index >= m_pinsCount)
			 index = m_pinsCount - 1;
		 if (index < 0)
			 index = 0;
		 return m_stateOfPins[index];
	 }



	 ////////////////////////////STRUCT PIN TO FOLLOW////////////////////////////////////
	 PinsToFollowGroupedInfo::PinsToFollowGroupedInfo(int digitalPins[], int digitCount, int analogPins[], int analogCount) {
		 m_digitalPins = digitalPins;
		 m_digitalCount = digitCount;
		 m_analogPins = analogPins;
		 m_analogCount = analogCount;
	 }




	 ////////////////////////////OPEN BOARD FOR UNITY COMPRESSION ////////////////////////////////////
	 //
	 /*
	 HardwareConfiguration::HardwareConfiguration(int tx, int rx, PinsToFollowGroupedInfo pinsToFollow, int lightPin) {
	 
		 m_bluetoothTx = tx;
		 m_bluetoothRx = rx;
		 m_pinForLight = lightPin;
	     //m_digitalPins = new DeviceDigitalPinsState(pinsToFollow);
		 //m_analogPins = new DeviceAnalogPinsState(pinsToFollow);
	 
	 }
	 //*/
