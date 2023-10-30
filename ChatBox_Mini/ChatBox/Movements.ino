#include <Servo.h>

#define Ears_port 2
#define REye_port 3
#define LEye_port 4
#define RNeck_port 5
#define LNeck_port 6
#define RArm_port 7
#define LArm_port 8

Servo Ears;
Servo REye;
Servo LEye;
Servo RNeck;
Servo LNeck;
Servo RArm;
Servo LArm;

//---------------------------------- servo_init ----------------------------------//
void servo_init(){ 
 // This function initialises the robots servos
 // INPUT:  (repeat = numebr of times it beeps)
 // OUTPUT: null
  
  Ears.attach(Ears_port);
  REye.attach(REye_port);
  LEye.attach(LEye_port);
  RNeck.attach(RNeck_port);
  LNeck.attach(LNeck_port);
  RArm.attach(RArm_port);
  LArm.attach(LArm_port);
}

//---------------------------------- Void MoveEyes ----------------------------------//
void MoveEyes(char select, int state){
// This function tells the eyes what to do, in a easier way
// INPUTS: (Select: R = right, L = Left, B = Both)
//         (State 0: Close, 1: Half-Opened 2: Open)
// OUTPUTS: NA

  switch(select){
    case 'R':
    REye.write(90-(state*30));
    break;
    case 'L':
    LEye.write(90+(state*30));
    break;
    case 'B':
    REye.write(90-(state*30));
    LEye.write(90+(state*30));
    break;
  }
  delay(100);
}

//---------------------------------- Void MoveNeck ----------------------------------//
void MoveNeck(char state){
// This function tells the neck what to do, in a easier way
// INPUTS:  (state: R = tilt right, L =  tilt left, U = up, D = Down)
// OUTPUTS: NA

  //Serial.println(state);
  //Beep(1);
  switch(state){
    case 'R':
    RNeck.write(40);
    LNeck.write(100);
    break;
    case 'L':
    RNeck.write(80);
    LNeck.write(140);
    break;
    case 'U':
    RNeck.write(120);
    LNeck.write(60);
    break;
    case 'M':
    RNeck.write(60);
    LNeck.write(120);
    break;
    case 'D':
    RNeck.write(40);
    LNeck.write(140);
    break;
  }
  delay(100);
}

//---------------------------------- Void MoveEars ----------------------------------//
void MoveEars(char state){
// This function tells the ears what to do, in a easier way
// INPUTS:  (State: O = open, C = close)
// OUTPUTS: NA

  //Serial.println(state);
  switch(state){
    case 'O':
    Ears.write(50);
    break;
    case 'C':
    Ears.write(110);
    break;
  }
  delay(100);
}

//---------------------------------- Void MoveArms ----------------------------------//
void MoveArms(char select, int state){
// This function tells the neck what to do, in a easier way
// INPUTS:  (select: R = right arm, L = left arm, B = Both)
//          (state: 0 = closed, 1 = half, 2 = open)  
// OUTPUTS: NA
  switch(select){
    case 'R':
    RArm.write(90+(state*42));
    break;
    case 'L':
    LArm.write(90-(state*42));
    break;
    case 'B':
    RArm.write(90+(state*42));
    LArm.write(90-(state*42));
    break;
  }
  delay(100);
}

//---------------------------------- Void Expression ----------------------------------//
void Expression(String Name) {
  if (Name == "Agree") {
    MoveEyes('B',2);
    MoveEars('C');
    MoveNeck('U');
    delay(500);
    MoveNeck('D');
    delay(500);
    MoveNeck('U');
    delay(500);
    MoveNeck('D');
    delay(500);

  } else if (Name == "Confusion") {
    MoveEyes('R',2);
    MoveEyes('L',1);
    MoveEars('O');
    MoveNeck('R');
    delay(2000);

  } else if (Name == "Greet") {
    MoveEyes('B',2);
    MoveNeck('R');
    MoveArms('R',2);
    delay(800);
    MoveNeck('L');
    MoveArms('R',1);
    delay(800);
    MoveNeck('R');
    MoveArms('R',2);
    delay(800);
    MoveNeck('L');
    MoveArms('R',1);
    delay(800);

  } else if (Name == "Default") {
    MoveEyes('B',2);
    MoveNeck('M');
    MoveEars('O');
    MoveArms('B',0);
    delay(1000);

  } else if (Name == "Sad") {
    MoveEyes('B',1);
    MoveNeck('U');
    MoveEars('C');
    MoveArms('B',1);
    delay(500);
    MoveNeck('D');
    MoveArms('B',0);
    MoveEars('O');
    delay(2000);

  } else if (Name == "Happy") {
    MoveEars('O');
    MoveEyes('B',2);
    MoveNeck('U');
    MoveArms('B',2);
    delay(400);
    MoveArms('B',0);
    delay(400);
    MoveArms('R',1);
    MoveArms('L',0);
    delay(400);
    MoveArms('R',0);
    MoveArms('L',1);
    delay(400);
    MoveArms('B',0);
    delay(2000);

  } else if (Name == "Sleep") {
    MoveEyes('B',0);
    MoveNeck('D');
    MoveEars('O');
    MoveArms('B',0);
    delay(2000);
  }
    else if (Name == "Express") { 
      MoveEyes('R',0); //wink
      MoveEyes('L',2);
      MoveEars('O');
      MoveNeck('R');
      delay(500);
      MoveEyes('R',2);
      delay(500);
      MoveEyes('R',0); 
      delay(1500);
      MoveEyes('B',1); //anger
      MoveEars('O');
      MoveNeck('D');
      MoveArms('B',1);
      delay(400);
      MoveArms('B',0);
      delay(400);
      MoveArms('B',1);
      delay(400);
      MoveArms('B',0);
      delay(1500);  // Happy
      MoveEars('O');
      MoveEyes('B',2);
      MoveNeck('U');
      MoveArms('B',2);
      delay(400);
      MoveArms('B',0);
      delay(400);
      MoveArms('R',1);
      MoveArms('L',0);
      delay(400);
      MoveArms('R',0);
      MoveArms('L',1);
      delay(400);
      MoveArms('R',1);
      MoveArms('L',0);
      delay(400);
      MoveArms('B',0);
      delay(1500);  // dance
      MoveEyes('B',0);
      MoveNeck('L');
      delay(400);
      MoveArms('R',2);
      MoveArms('L',0);
      MoveNeck('R');
      delay(400);
      MoveArms('R',0);
      MoveArms('L',2);
      MoveNeck('L');
      delay(400);
      MoveArms('R',2);
      MoveArms('L',0);
      MoveNeck('R');
      delay(400);
      MoveArms('R',0);
      MoveArms('L',2);
      MoveNeck('R');
      delay(400);
      MoveArms('R',2);
      MoveArms('L',0);
      MoveNeck('L');
      delay(400);
      MoveArms('R',0);
      MoveArms('L',2);
      MoveNeck('R');
      delay(400);
      MoveArms('B',0);
      delay(2000);   
    }
}
  
