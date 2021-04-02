#include <Servo.h>
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; // for storing positions/steps
short int speedDelay = 20;
short int index = 0;
int servo01_value=90,servo02_value=140,servo03_value=110,servo04_value=180,servo05_value=45,servo06_value=100;
char dataIn_char,dataArduinoMaster;
void setup() {
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);
  Serial.begin(9600);
  Serial.setTimeout(10);
  servo01.write(servo01_value);
  servo02.write(servo02_value);
  servo03.write(servo03_value);
  servo04.write(servo04_value);
  servo05.write(servo05_value);
  servo06.write(servo06_value);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  pinMode(4,INPUT);
}
void runservo();
void write_servo( char servo,int value);
void loop() {
 // dataIn_char="";
 if(Serial.available()){
    dataIn_char=Serial.read();
   // write_servo(servo_char,servo_value);
   if(dataIn_char=='a'){
      servo01_value=Serial.parseInt();
      servo01.write(servo01_value);  
    }
    if(dataIn_char=='b'){
      servo02_value=Serial.parseInt();
      servo02.write(servo02_value);  
    }
    if(dataIn_char=='c'){
      servo03_value=Serial.parseInt();
      servo03.write(servo03_value);  
    }
    if(dataIn_char=='d'){
      servo04_value=Serial.parseInt();
      servo04.write(servo04_value);  
    }
    if(dataIn_char=='f'){
      servo05_value=Serial.parseInt();
      servo05.write(servo05_value);  
    }
    if(dataIn_char=='g'){
      servo06_value=Serial.parseInt();
      servo06.write(servo06_value);  
    }
    if ( dataIn_char=='s') {
      //servo01.write(0);
      servo01SP[index] = servo01_value;  // save position into the array
      servo02SP[index] = servo02_value;
      servo03SP[index] = servo03_value;
      servo04SP[index] = servo04_value;
      servo05SP[index] = servo05_value;
      servo06SP[index] = servo06_value;
      index++;
      delay(100);                     
    }
     // If button "RUN" is pressed
    if (dataIn_char=='r') {
     // servo01.write(180);
      runservo();  // Automatic mode - run the saved steps 
    //}
    delay(100);

  }
  if(dataIn_char=='e'){
      memset(servo01SP, 0, sizeof(servo01SP)); // Clear the array data to 0
      memset(servo02SP, 0, sizeof(servo02SP));
      memset(servo03SP, 0, sizeof(servo03SP));
      memset(servo04SP, 0, sizeof(servo04SP));
      memset(servo05SP, 0, sizeof(servo05SP));
      memset(servo06SP, 0, sizeof(servo06SP));
      index = 0;
    }
 }
}
 void runservo() {
  while (dataIn_char != "e") {
    dataArduinoMaster="";
    if (Serial.available()) { 
    dataArduinoMaster=Serial.read();
    }
    if(dataArduinoMaster=="l"){
    delay(2000);
    for (int i = 0; i <= index - 2; i++) { 
      if (Serial.available()) {    
        dataIn_char = Serial.read();;
      }
      if(dataIn_char=='p'){               
            while(dataIn_char!='r'){
            if (Serial.available()) {
             dataIn_char = Serial.read();;
            }
            }
          }
      if (servo01SP[i] == servo01SP[i + 1]) {
      }
      if (servo01SP[i] > servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j >= servo01SP[i + 1]; j--) {
          servo01.write(j);
          delay(speedDelay);
        }
      }
      if (servo01SP[i] < servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j <= servo01SP[i + 1]; j++) {
          servo01.write(j);
          delay(speedDelay);
        }
      }
      if (servo02SP[i] == servo02SP[i + 1]) {
      }
      if (servo02SP[i] > servo02SP[i + 1]) {
        for ( int j = servo02SP[i]; j >= servo02SP[i + 1]; j--) {
          servo02.write(j);
          delay(speedDelay);
        }
      }
      if (servo02SP[i] < servo02SP[i + 1]) {
        for ( int j = servo01SP[i]; j <= servo02SP[i + 1]; j++) {
          servo02.write(j);
          delay(speedDelay);
        }
      }
      if (servo03SP[i] == servo03SP[i + 1]) {
      }
      if (servo03SP[i] > servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j >= servo03SP[i + 1]; j--) {
          servo03.write(j);
          delay(speedDelay);
        }
      }
      if (servo03SP[i] < servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j <= servo03SP[i + 1]; j++) {
          servo03.write(j);
          delay(speedDelay);
        }
      }
      if (servo04SP[i] == servo04SP[i + 1]) {
      }
      if (servo04SP[i] > servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j >= servo04SP[i + 1]; j--) {
          servo01.write(j);
          delay(speedDelay);
        }
      }
      if (servo04SP[i] < servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j <= servo04SP[i + 1]; j++) {
          servo04.write(j);
          delay(speedDelay);
        }
      }
      if (servo05SP[i] == servo05SP[i + 1]) {
      }
      if (servo05SP[i] > servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j >= servo05SP[i + 1]; j--) {
          servo05.write(j);
          delay(speedDelay);
        }
      }
      if (servo05SP[i] < servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j <= servo05SP[i + 1]; j++) {
          servo05.write(j);
          delay(speedDelay);
        }
      }
      if (servo06SP[i] == servo06SP[i + 1]) {
      }
      if (servo06SP[i] > servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j >= servo06SP[i + 1]; j--) {
          servo06.write(j);
          delay(speedDelay);
        }
      }
      if (servo06SP[i] < servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j <= servo06SP[i + 1]; j++) {
          servo06.write(j);
          delay(speedDelay);
        }
      }
    }
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    delay(3000);
    Serial.print("l\n");
  }
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    
  }
}
