#include "Arduino.h"
#include <SoftwareSerial.h>
#include "Keyboard.h"


SoftwareSerial BTserial(3, 2); // RX , TX
//4|5|6|7|8|9|10|11|12
//0|1|2|3|4|5|6 | 7| 8
const int inPins[] = { 0, 1, 2, 3, 6, 7,8, 9, 10 };

int fromDigit = 4, toDigit = 12;
int fromAnalog = 0, toAnalog = 9;
int debugLight = 13;
int timeBetweenFrame = 20;
String tmpString;
int tmpInt;
void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  
    //Begin keyboard for HID over bluetooth
  Keyboard.begin();

 // pinMode(debugLight, OUTPUT);

  //for (int y = fromDigit; y <= toDigit; y++) {
  //  pinMode(y, INPUT_PULLUP);
  //}
   pinMode(5, OUTPUT);
 pinMode(7, OUTPUT);
 //digitalWrite(debugLight, HIGH);
 digitalWrite(5, HIGH);
 digitalWrite(7, HIGH);
}

char c = ' ';
void loop() {

  /**
 // Keep reading from HC-06 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        Serial.write(BTserial.read());
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-06
    if (Serial.available())
    {
        BTserial.write(Serial.read());
    }
    */
    
  DisplayAllValueCompressed();

  if (BTserial.available() > 0) {

    char data = (char) BTserial.read();
    switch (data) {
      case '1':
        digitalWrite(debugLight, HIGH);
        break;

      case '0':
        digitalWrite(debugLight, LOW);
        break;

      default:
        Serial.print("NOT RECOGNISED: ");
        Serial.println(data);
        BTserial.print("Error!");
    }
  }
  delay(timeBetweenFrame);        // delay in between reads for stability
}

void DisplayAllValue() {

  String test = "Digital: ";
  for (int y = fromDigit; y <= toDigit; y++) {

    test.concat(" ");
    test.concat(y);
    test.concat(":");
    test.concat(digitalRead(y));

  }

  test.concat(" Analog: ");
  for (int y = fromAnalog; y <= toAnalog; y++) {

    test.concat(" ");
    test.concat(y);
    test.concat(":");
    test.concat(analogRead(y));

  }

  Serial.println(test);
  BTserial.println(test);
}
void DisplayAllValueCompressed() {

  String test = "";

  test.concat("#");
  for (int y = fromDigit; y <= toDigit; y++) {

    if (y > fromDigit){
      int value =digitalRead(y);
      test.concat(value);
        if(y==0 &value>600){
         // Keyboard.write("0");
        }
      }
      
  }

  test.concat("|");
  for (int y = fromAnalog; y < toAnalog; y++) {

    if (y >= fromAnalog)
      tmpInt = analogRead(inPins[y]);
    if (tmpInt > 999)
      tmpInt = 999;
    if (tmpInt < 100)
      tmpInt = 0;
   // tmpString = tmpInt;
    //test.concat(tmpString);
    test.concat(' ');
    test.concat(tmpInt);
        if(y<8 &tmpInt<100){
          PressNumpadNumber(y,true);
          delay(10);
          PressNumpadNumber(y,false);
        }
  }

  Serial.println(test);
  BTserial.println(test);
}

void PressNumpadNumber(int value, bool buttonvalue){
  switch(value){
    case 0:  value= 234; break;
    case 1:  value= 225; break;
    case 2:  value= 226; break;
    case 3:  value= 227; break;
    case 4:  value= 228; break;
    case 5:  value= 229; break;
    case 6:  value= 230; break;
    case 7:  value= 231; break;
    case 8:  value= 232; break;
    case 9:  value= 233; break;
    
  //220 '\334' Keypad /
  //221 '\335' Keypad *
  //222 '\336' Keypad -
  //223 '\337' Keypad +
  //224 '\340' Keypad ENTER
  //235 '\353' Keypad . and Delete
    default: value=-1;
    }
    if( value >-1){
      if(buttonvalue){
       
          Keyboard.press(value);
        }
      else 
       
        {
          Keyboard.release(value);
          }
      
      
    }
    
}
void PressFX(int value, bool buttonvalue){
  switch(value){
    case 1:  value=(KEY_F1); break;
    case 2:  value=(KEY_F2); break;
    case 3:  value=(KEY_F3); break;
    case 4:  value=(KEY_F4); break;
    case 5:  value=(KEY_F5); break;
    case 6:  value=(KEY_F6); break;
    case 7:  value=(KEY_F7); break;
    case 8:  value=(KEY_F8); break;
    case 9:  value=(KEY_F9); break;
    case 10:  value=(KEY_F10); break;
    case 11:  value=(KEY_F11); break;
    case 12:  value=(KEY_F12); break;
    default: value=-1;
    }
    if( value >-1){
      if(buttonvalue){
       
          Keyboard.press(value);
          
        }
      else 
       
        {
          Keyboard.release(value);
        }
    }

}
