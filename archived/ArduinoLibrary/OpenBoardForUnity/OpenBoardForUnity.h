#ifndef OpenBoardForUnity_H
#define OpenBoardForUnity_H
#include "Arduino.h"
#include "SoftwareSerial.h"



struct PinsToFollowGroupedInfo {
public :
	PinsToFollowGroupedInfo(int digitalPins[], int digitCount, int analogPins[], int analogCount);
	int m_digitalCount;
	int *m_digitalPins;
	int m_analogCount;
	int *m_analogPins;
private:
};


class DigitalPin {

public:
	DigitalPin(int pinNumber = 0); // Define the pin to listen to
	void setListenedPin(int index); // Store and pullup the pin to listen to
	void setAsPullUp(); // Set The pin as pullup state;
	bool getHardwareValue(); // Check the value on the Arduino
	void setWithNewValue(bool value); // Allow to the new value and so the previous one
	bool getCurrentValue(); // recover the current store value
	bool getPreviousValue(); // recover the previous value store
	void refreshWithHardwareValue(); // use getHardware and setValue
	bool hasValueChange(); // quick check is store value has changed
	int getPinNumber(); // Return the pin followed 

private:
	int m_pinNumber; // The number of the pin use on the arduino board
	bool m_currentValue; // the value store from the hardware by the developer
	bool m_previousValue; // the previous value store when current value is changed

};


class DeviceDigitalPinsState {

public:
	DeviceDigitalPinsState();
	DeviceDigitalPinsState(PinsToFollowGroupedInfo pinsToFollow);
	DeviceDigitalPinsState(int pinToListen[], int arraySize);
	void init(int  pinToListen[], int arraySize);
	int getPinsCount();
	bool getPinState(int index);
	DigitalPin& getPinInfo(int index);
	int * m_listeningToPins;

private:

	int m_pinsCount;
	DigitalPin * m_stateOfPins;

};





class AnalogPin {

public:
	AnalogPin(int pinNumber = A0, int threshold=400); // Define the pin to listen to
	void setListenedPin(int index); // Store and pullup the pin to listen to
	void setAsPullUp(); // Set The pin as pullup state;
	int getHardwareValue(); // Check the value on the Arduino
	int getCurrentValue(); // Return the value of the analog from 0-1024
	int getCurrentValueAsOneDigit(); // return the value of the analog from 0-9
	void setWithNewValue(int value); // Allow to set the analog value
	void setIsHightWithNewValue(bool value); // Allow to the new value and so the previous one
	bool getIsHighCurrentValue(); // recover the current store value
	bool getIsHighPreviousValue(); // recover the previous value store
	void refreshWithHardwareValue(); // use getHardware and setValue
	int getPinNumber(); // Return the pin followed 

	void setThreshold(int value );// threshold to  set on/off (max1024)
	bool hasIsHighValueChange(); // quick check is store value has changed

private:
	int m_pinNumber; // The number of the pin use on the arduino board
	bool m_currentIsHighValue; // the value store from the hardware by the developer
	bool m_previousIsHighValue; // the previous value store when current value is changed
	int m_threshold;
	int m_analogValue;

};


class DeviceAnalogPinsState {

public:
	DeviceAnalogPinsState();
	DeviceAnalogPinsState(PinsToFollowGroupedInfo pinsToFollow);
	DeviceAnalogPinsState(int pinToListen[], int arraySize);
	void init(int  pinToListen[], int arraySize);
	int getPinsCount();
	AnalogPin& getPinInfo(int index);
	int * m_listeningToPins;

private:

	int m_pinsCount;
	AnalogPin * m_stateOfPins;

};




//
///*

class HardwareConfiguration {

public:
	HardwareConfiguration(int tx, int rx,  PinsToFollowGroupedInfo pinsToFollow,int lightPin= 13);

	void setLightOn(bool value);
	void startSerialAndBluetooth(int baud=9600, bool startClassicSeriaToo =true);
	void println(String message);
	SoftwareSerial* getBluetoothSerial();
	char getReadAvalaible();
private:
	int m_bluetoothTx = 2;
	int m_bluetoothRx = 3;
    int m_pinForLight = 13;
	DeviceDigitalPinsState* m_digitalPins=NULL;
	DeviceAnalogPinsState* m_analogPins = NULL;
	SoftwareSerial* m_bluetoothSerial=NULL;

	void startLightPin();
	//void setPinInformation(PinsToFollowGroupedInfo& pinsToFollow);
	//void refreshPinsInformation();

};
//*/

#endif
