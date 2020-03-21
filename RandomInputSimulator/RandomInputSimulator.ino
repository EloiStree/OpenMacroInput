#define ARRAY_SIZE 10
int digitalInput=3;
int analogInput=3;
bool digitalState[ARRAY_SIZE];
int analogState[ARRAY_SIZE];



void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  digitalInput= random(ARRAY_SIZE);
  analogInput= random(ARRAY_SIZE);
   
  //  Serial.print(digitalInput);
  //  Serial.print(analogInput);
  ResetToZero();
}


void loop() {
    delay(500);

    ResetToZero();
    digitalState[random(digitalInput)]=random(500)%2==1;
    analogState[random(analogInput)]=random(10);


    
    String mockState="#";
    for(int i =0; i<digitalInput; i++){
       mockState.concat(digitalState[i]==true?'1':'0');
    }
       mockState.concat("|");
    for(int i =0; i<analogInput; i++){
       mockState.concat(analogState[i]);
    }
    Serial.println(mockState);
  

}

void ResetToZero(){
  
   for(int i =0; i<digitalInput; i++){
       digitalState[i]=false;
    }
    for(int i =0; i<analogState; i++){
      analogState[i]=0;
    
    }
  }
