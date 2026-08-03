
//#include "Keyboard.h"
//#include "Mouse.h"

bool onOffSwitch=true;
void DoAtStart(){
 // OpenCmd_Desktop();
 // DownloadUrlLinkInFolder("https://avatars0.githubusercontent.com/u/20149493");
 // Rename("20149493", "EloiWasHere.png");
 // ExitCmd();
 SetTrackedButton(true,true,true,true,true,true,true,true,true,true);
 SetTrackedAnalog(false,false,false,false,false, false);
}
void ButtonActiveAtStart0( ){}
void ButtonActiveAtStart1( ){}
void ButtonActiveAtStart2( ){}
void ButtonActiveAtStart3( ){}
void ButtonActiveAtStart4( ){}
void ButtonActiveAtStart5( ){}
void ButtonActiveAtStart6( ){}
void ButtonActiveAtStart7( ){}
void ButtonActiveAtStart8( ){}
void ButtonActiveAtStart9( ){}
void ButtonActiveAtStart10( ){}
void ButtonChange0(bool value) {if(onOffSwitch){Serial.println("cda");PressFX(5, value); }}
void ButtonChange1(bool value) {if(onOffSwitch){Serial.println("cdb");PressFX(6, value);}}
void ButtonChange2(bool value) {if(onOffSwitch){Serial.println("cdc");PressFX(7, value);}}
void ButtonChange3(bool value) {if(onOffSwitch){Serial.println("cdd");PressFX(8, value);}}
void ButtonChange4(bool value) {if(onOffSwitch){Serial.println("cde");PressFX(9, value);}}
void ButtonChange5(bool value) {if(onOffSwitch){Serial.println("cdf");PressFX(10, value);}}
void ButtonChange6(bool value) {if(onOffSwitch){Serial.println("cdg");PressFX(11, value);}}
void ButtonChange7(bool value) {if(onOffSwitch){Serial.println("cdh");PressFX(12, value);}}
void ButtonChange8(bool value) {if(onOffSwitch){Serial.println("cdp");PressFX(12, value);}}
void ButtonChange9(bool value) {if(onOffSwitch){Serial.println("cdo");PressFX(12, value);}}
void ButtonChange10(bool value){}//{onOffSwitch= value;}

void ButtonStay0(bool value) {}
void ButtonStay1(bool value) {if( value){}} //{Mouse.begin();Mouse.click();Mouse.end();Serial.println("ddd");}}
void ButtonStay2(bool value) {}
void ButtonStay3(bool value) {}
void ButtonStay4(bool value) {}
void ButtonStay5(bool value) {}
void ButtonStay6(bool value) {}
void ButtonStay7(bool value) {}//if( value){Mouse.begin();Mouse.click();Mouse.end();}}
void ButtonStay8(bool value) {}
void ButtonStay9(bool value) {}
void ButtonStay10(bool value){}//{onOffSwitch= value;}


//{}//
  void AnalogActiveAtStart0(){}
  void AnalogActiveAtStart1(){}
  void AnalogActiveAtStart2(){}
  void AnalogActiveAtStart3(){}
  void AnalogActiveAtStart4(){}
  void AnalogActiveAtStart5(){}

  
  void AnalogChange0(bool value) {if(onOffSwitch){PressFX(4, !value);Serial.println("caa");}}
  void AnalogChange1(bool value) {if(onOffSwitch){PressFX(3, !value);Serial.println("cab");}}
  void AnalogChange2(bool value) {if(onOffSwitch){PressFX(11, !value);Serial.println("cac");}}
  void AnalogChange3(bool value) {if(onOffSwitch){PressFX(12, !value);Serial.println("cad");}}
  void AnalogChange4(bool value) {if(onOffSwitch){PressNumpadNumber(0, value);Serial.println("cae");}}
  void AnalogChange5(bool value) {if(onOffSwitch){PressNumpadNumber(0, value);Serial.println("caf");}}
  
  void AnalogStay0(bool value)  {}
  void AnalogStay1(bool value)  {}
  void AnalogStay2(bool value)  {}
  void AnalogStay3(bool value)  {}
  void AnalogStay4(bool value)  {}
  void AnalogStay5(bool value)  {}

bool displayFrame=false;
long delayBetweenFrame=100;
int threshold =950;
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// DONT GO HERE EXCEPT TO CHANGE PINS OR IF YOU KNOW WHAT YOU DOING  //
//////////////////////////////////////////////////////////////////////
 struct PinState {
    public :
    int pin;
    bool useIt;
    bool previousValue;
    long lastTime;
    long cooldownInMilli;

  bool IsTracked(){
    return useIt;
    }
    
    bool IsPinOnDigital(){
     
       return digitalRead (pin) == LOW;
    }
    bool IsPinOnAnalog(){
      
       return analogRead (pin) > threshold;
    }
    void SetManuallyAs(bool value){
      previousValue=value;
      lastTime=millis();
      }
    bool IsLastStateOn(){
       return previousValue;
    }
    bool HasChanged(bool refreshIfTrue, bool useAnalog){ 
      if(HasCooldown(previousValue)){
       return false; 
      }
      
      bool isOn = false;
      if(useAnalog)
       isOn = IsPinOnAnalog();
      else
       isOn = IsPinOnDigital();
       
      bool isNew = !(isOn == previousValue);
      if( isNew && refreshIfTrue){
        SetAsChanged(isOn);
      }
      return isNew;
    }
    bool HasCooldown(long giveTime){
       long now = millis();
       long diff =now-giveTime;
       return diff< cooldownInMilli && diff>=0; 
    }
    bool SetAsChanged(bool newValue){
      lastTime = millis();
      previousValue=newValue;
    }

  
    
    private:
    
  };
//////////////////////////////////////////////////////////////////////////////
//**//Change the value here based on how you connect buttons on pin 2-12//**//
//////////////////////////////////////////////////////////////////////////////

PinState trackedPins []  = {
  { 2 ,true, false,0,200  },//0
  { 3 ,true, false,0,200  },//1
  { 4 ,true, false ,0,200 },//2
  { 5 ,true, false ,0,200 },//3
  { 6 ,true, false,0,200  },//4
  { 7 ,true, false ,0,200 },//5
  { 8 ,true, false ,0,200 },//6
  { 9 ,true, false ,0,200 },//7
  { 10 ,true, false ,0,200 },//8
  { 11 ,true, false ,0,200 },//9
  { 12 ,true, false ,0,200 }//10
  };
PinState analogTrackedPins []  = {
  { 0 ,true, false,0,200  },//0
  { 1 ,true, false,0,200  },//1
  { 2 ,true, false ,0,200 },//2
  { 3 ,true, false ,0,200 },//3
  { 4 ,false, false,0,200  },//4
  { 5 ,false, false,0,200  }//5
  };

  
long frame=0;
int pinsCount = 11;
int analogCount = 6;
void setup() {
  pinsCount = 11;
  analogCount = 6;
  Serial.begin(9600);
  
  //pinsCount= sizeof(trackedPins);
  for(int y=0; y < pinsCount ; y++){
    pinMode (trackedPins[y].pin , INPUT_PULLUP);
  } 

  
 
}

void loop() { 
  
  DisplayAllAnalogValue();
  DisplayAllDigitalValue();
  
if(frame==0){
  Serial.println("-------- Start: Begin -----------");
  delay(1000); 
  DoAtStart();
  for (int y=0; y<pinsCount; y++){
    if(trackedPins[y].IsTracked()  && trackedPins[y]. IsPinOnDigital()){
         ButtonActiveAtStart(y);
         trackedPins[y].SetManuallyAs(true);
      }
  }
   for(int y=0; y < analogCount ; y++){
      if(analogTrackedPins[y].IsTracked()&& trackedPins[y]. IsPinOnAnalog()){
         AnalogActiveAtStart(y);
         analogTrackedPins[y].SetManuallyAs(true);
      }
  }
  
  Serial.println("-------- Start: End -----------");
}
//*/
  delay(delayBetweenFrame); 
  String msg;
  
  if(displayFrame){
    msg = "Frame:";
    msg.concat(frame);
    Serial.println(msg );  
  }
  ///*
  bool changeDetected=false;
  for (int y=0; y<pinsCount; y++){
    if(trackedPins[y].IsTracked() && trackedPins[y].HasChanged(true,false)){
      //msg = "Pin digital: ";
      //msg.concat(y);
      //msg.concat(" ");
      //msg.concat(trackedPins[y].pin);
      //Serial.println(msg);  
      ButtonChange(y,trackedPins[y].IsLastStateOn());
    
      
      //Keyboard.println(msg);
      
    }
    else { 
    //  Serial.println("None"); 
      }
      if(trackedPins[y].IsTracked()){
          ButtonStay(y,trackedPins[y]. IsPinOnDigital());
      }
  }

   for(int y=0; y < analogCount ; y++){
      
         if(analogTrackedPins[y].IsTracked() && analogTrackedPins[y].HasChanged(true,true)){
          //msg = "Pin Anlaog: ";
          //msg.concat(y);
          //msg.concat(" ");
          //msg.concat(analogTrackedPins[y].pin);
          //Serial.println(msg);  
          AnalogChange(y,analogTrackedPins[y].IsLastStateOn());
          //Keyboard.println(msg);
          
        }
        else { 
        //  Serial.println("None"); 
          }
       if(analogTrackedPins[y].IsTracked()){
          AnalogStay(y, trackedPins[y]. IsPinOnAnalog());
      }
  }
  //*/
  frame++;
}
  bool IsOn(int index){
     return digitalRead (trackedPins[index].pin) == LOW;
  }
  bool IsAnalogOn(int index){
     return analogRead(analogTrackedPins[index].pin) > threshold;
  }

  void  SetTrackedButton(bool p0,bool p1,bool p2,bool p3,bool p4,bool p5,bool p6,bool p7,bool p8,bool p9){
    trackedPins[0].useIt= p0;
    trackedPins[1].useIt= p1;
    trackedPins[2].useIt= p2;
    trackedPins[3].useIt= p3;
    trackedPins[4].useIt= p4;
    trackedPins[5].useIt= p5;
    trackedPins[6].useIt= p6;
    trackedPins[7].useIt= p7;
    trackedPins[8].useIt= p8;
    trackedPins[9].useIt= p9;
    }
 void SetTrackedAnalog(bool p0,bool p1,bool p2,bool p3,bool p4,bool p5){
    analogTrackedPins[0].useIt= p0;
    analogTrackedPins[1].useIt= p1;
    analogTrackedPins[2].useIt= p2;
    analogTrackedPins[3].useIt= p3;
    analogTrackedPins[4].useIt= p4;
    analogTrackedPins[5].useIt= p5;
  }
// Those instruction will be call only if the button is pressed when the Arduino start
void ButtonActiveAtStart(int index){
switch(index){
  case 0:ButtonActiveAtStart0(); break;
  case 1:ButtonActiveAtStart1(); break;
  case 2:ButtonActiveAtStart2(); break;
  case 3:ButtonActiveAtStart3(); break;
  case 4:ButtonActiveAtStart4(); break;
  case 5:ButtonActiveAtStart5(); break;
  case 6:ButtonActiveAtStart6(); break;
  case 7:ButtonActiveAtStart7(); break;
  case 8:ButtonActiveAtStart8(); break;
  case 9:ButtonActiveAtStart9(); break;
  case 10:ButtonActiveAtStart10(); break;
  }  
}
// Those instruction will be call each time a change is detected on the 11 buttons tracked.
void ButtonChange(int index, bool value){
switch(index){
  case 0:ButtonChange0(value); break;
  case 1:ButtonChange1(value); break;
  case 2:ButtonChange2(value); break;
  case 3:ButtonChange3(value); break;
  case 4:ButtonChange4(value); break;
  case 5:ButtonChange5(value); break; 
  case 6:ButtonChange6(value); break;
  case 7:ButtonChange7(value); break;
  case 8:ButtonChange8(value); break;
  case 9:ButtonChange9(value); break;
  case 10:ButtonChange10(value); break;
  
  }  
}
void AnalogActiveAtStart(int index){
switch(index){
  case 0:AnalogActiveAtStart0(); break;
  case 1:AnalogActiveAtStart1(); break;
  case 2:AnalogActiveAtStart2(); break;
  case 3:AnalogActiveAtStart3(); break;
  case 4:AnalogActiveAtStart4(); break;
  case 5:AnalogActiveAtStart5(); break;
  }  
}
// Those instruction will be call each time a change is detected on the 11 buttons tracked.
void AnalogChange(int index, bool value){
switch(index){
  case 0:AnalogChange0(value); break;
  case 1:AnalogChange1(value); break;
  case 2:AnalogChange2(value); break;
  case 3:AnalogChange3(value); break;
  case 4:AnalogChange4(value); break;
  case 5:AnalogChange5(value); break;
  
  }  
}

void ButtonStay(int index, bool value){
switch(index){
  case 0: ButtonStay0(value); break;
  case 1: ButtonStay1(value); break;
  case 2: ButtonStay2(value); break;
  case 3: ButtonStay3(value); break;
  case 4: ButtonStay4(value); break;
  case 5: ButtonStay5(value); break; 
  case 6: ButtonStay6(value); break;
  case 7: ButtonStay7(value); break;
  case 8: ButtonStay8(value); break;
  case 9: ButtonStay9(value); break;
  case 10:ButtonStay10(value); break;
  
  }  
}

void AnalogStay(int index, bool value){
switch(index){
  case 0:AnalogStay0(value); break;
  case 1:AnalogStay1(value); break;
  case 2:AnalogStay2(value); break;
  case 3:AnalogStay3(value); break;
  case 4:AnalogStay4(value); break;
  case 5:AnalogStay5(value); break;
  
  }  
}
void DisplayAllAnalogValue(){
    String test="Analog: ";
   test.concat(" 0:");
   test.concat(analogRead(0));
   test.concat(" 1:");
   test.concat(analogRead(1));
   test.concat(" 2:");
   test.concat(analogRead(2));
   test.concat(" 3:");
   test.concat(analogRead(3));
   test.concat(" 4:");
   test.concat(analogRead(4));
   test.concat(" 5:");
   test.concat(analogRead(5));
   test.concat(" Threshold:");
   test.concat(threshold);
  Serial.println(test); 
  }
  void DisplayAllDigitalValue(){
  
    String test="Digital: ";
     for (int y=0; y<pinsCount; y++){
      
            test.concat(" ");
            test.concat(y);
            test.concat(":");
            test.concat(trackedPins[y].IsPinOnDigital());
          
      }
  Serial.println(test); 
  }
void WriteText( String text){
  
    Serial.println(text);
    //Keyboard.println(text);  
}
///////////////////////////////////////////
////// Cool Window Stuff  /////////////////
///////////////////////////////////////////

void PressNumpadNumber(int value, bool buttonvalue){
  /*//
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
  ///*/
}
void PressFX(int value, bool buttonvalue){
  /*//
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
 ///*/
}
