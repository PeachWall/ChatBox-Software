//________________________________________+++ Intial Prep +++________________________________________
#include <Servo.h>
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 11); // RX, TX

#define Ears_Port 2
#define REBrow_Port 3
#define LEBrow_Port 4
#define RELid_Port 5
#define LELid_Port 6
#define Mouth_Port 7

#define OutputLink 8
#define InputLink 13

Servo Ears; 
Servo REBrow;
Servo LEBrow;
Servo RELid;
Servo LELid;
Servo Mouth;

//Variables dedicated for PyInput
String PyInput = "";
String Intent;
int Intensity;
String Behaviour;
int CommDelay = 40;

int GestureSignal[11][3] = {
  // A = 0 B = 1 C = 2
  {0, 0, 0}, {0, 0, 2}, {2, 2, 2}, {2, 0, 1}, {1, 0, 2}, {1, 1, 0}, {2, 0, 0}, {2, 0, 1}, {2, 0, 2}, {2, 2, 2}, {2, 1, 0}
};
//________________________________________+++ Facial Angles +++________________________________________
/*
  Closed eyes
  RELid.write(130);
  LELid.write(50);

  Open eyes
  RELid.write(70);
  LELid.write(110);
*/

//________________________________________+++ Void Setup +++________________________________________
void setup() {
  Ears.attach(Ears_Port);
  REBrow.attach(REBrow_Port);
  LEBrow.attach(LEBrow_Port);
  RELid.attach(RELid_Port);
  LELid.attach(LELid_Port);
  Mouth.attach(Mouth_Port);

  Serial.begin(9600);
  mySerial.begin(9600); //Set up baud rate for UART communication between HuskyLens and Roduino
  while (!huskylens.begin(mySerial)){
    Serial.println(F("Begin failed!"));
    Serial.println(F("1.Please recheck the Protocol Type in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
    Serial.println(F("2.Please recheck the connection."));
    delay(100);
  }
  pinMode(OutputLink, OUTPUT);
  pinMode(InputLink, INPUT);

  Ears.write(120);
  REBrow.write(110);
  LEBrow.write(70);
  MoveEyes('R','L');
  MoveEyes('L','L');
  MoveMouth('C');
  delay(1000);

  Communicate(0);
  Communicate(0);
  Communicate(0);
  Communicate(3);
  Expression("Static");
}

//________________________________________+++ Void Loop +++________________________________________
void loop() {
  PyReceive(Serial.available() > 0);
  //Serial.println(Serial.available() > 0);
}

//________________________________________+++ Void MoveEyes +++________________________________________
void MoveEyes(char Side, char Degree) {
  if(Side == 'R'){
    switch(Degree){
      case('H'):
        RELid.write(70);
      break;
      case('M'):
        RELid.write(100);
      break;
      case('L'):
        RELid.write(130);
      break;
    }
  }
  else if(Side == 'L'){
    switch(Degree){
      case('H'):
        LELid.write(110);
      break;
      case('M'):
        LELid.write(80);
      break;
      case('L'):
        LELid.write(50);
      break;
    }
  }
}

//________________________________________+++ Void MoveMouth +++________________________________________
void MoveMouth(char Degree) {
  if(Degree == 'O') Mouth.write(110);
  else if(Degree == 'C') Mouth.write(70);
}

//________________________________________+++ Void Check +++________________________________________
void check() { 
   int countIdA = 0;
   int countIdB = 0;
   int countIdC = 0;
   for (int i = 0; i < 10; i++){
    // initial checks for any issues: Unable to connect, No available faces 
    if (huskylens.request()) {
      while (huskylens.available()){  //if HuskyLens detects an object
        HUSKYLENSResult result = huskylens.read();
        if (result.command == COMMAND_RETURN_BLOCK) {
          if (result.ID == 1) countIdA++;
          if (result.ID == 2) countIdB++;
          if (result.ID == 3) countIdC++;  
        }
      }
    }
    delay(100);
  }
  if (countIdA + countIdB + countIdC == 0) Serial.println("0");
  if ((countIdA>countIdB)&&(countIdA>countIdC)) Serial.println("1");
  if ((countIdB>countIdA)&&(countIdB>countIdC)) Serial.println("2");
  if ((countIdC>countIdA)&&(countIdC>countIdB)) Serial.println("3");
}

//________________________________________+++ Void Expression +++________________________________________
void Expression(String Name) {
  if (Name == "Agree") {
    Ears.write(140);
    REBrow.write(90);
    LEBrow.write(90);
    MoveEyes('R','H');
    MoveEyes('L','H');
    MoveMouth('O');
    delay(2000);

  } else if (Name == "Static") {
    Ears.write(120);
    REBrow.write(110);
    LEBrow.write(70);
    MoveEyes('R','H');
    MoveEyes('L','H');
    MoveMouth('C');
    delay(2000);

  } else if (Name == "Question") {
    Ears.write(150);
    REBrow.write(70);
    LEBrow.write(90);
    MoveEyes('R','M');
    MoveEyes('L','M');
    MoveMouth('C');
    delay(2000);

  } else if (Name == "Agree") {

  } else if (Name == "Agree") {

  } else if (Name == "Agree") {

  } else if (Name == "Agree") {

  } else if (Name == "Agree") {

  }
}

//________________________________________+++ Void Communication +++________________________________________
//0:A, 1:B, 2:C, 3:D
void Communicate(int Signal) {
  switch (Signal) {
    case (0):
      digitalWrite(OutputLink, HIGH);
      delay(CommDelay);
      digitalWrite(OutputLink, LOW);
      delay(CommDelay * 5);
      break;
    case (1):
      digitalWrite(OutputLink, HIGH);
      delay(CommDelay * 5);
      digitalWrite(OutputLink, LOW);
      delay(CommDelay);
      break;
    case (2):
      digitalWrite(OutputLink, HIGH);
      delay(CommDelay);
      digitalWrite(OutputLink, LOW);
      delay(CommDelay * 2);
      digitalWrite(OutputLink, HIGH);
      delay(CommDelay);
      digitalWrite(OutputLink, LOW);
      delay(CommDelay * 2);
      break;
    case (3):
      digitalWrite(OutputLink, HIGH);
      delay(CommDelay * 10);
      digitalWrite(OutputLink, LOW);
      delay(CommDelay * 2);
      break;
  }
  //delay(CommDelay);
}

//________________________________________+++ Void SplitString +++________________________________________
String SplitString(String text, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = text.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (text.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? text.substring(strIndex[0], strIndex[1]) : "";
}
