//________________________________________+++ Void gesture +++________________________________________
void gesture(String Name){
  Iterator = 0;
  Serial.println("Gesture triggered");
  /*
  digitalWrite(OutputLink, HIGH);
  delay(200);
  digitalWrite(OutputLink, LOW);
  */
  if(Name == "AAA"){
    //Surprise wakeup
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 1000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('B');
            moveArm('R', 'M', 'M');
            moveArm('L', 'M', 'M');
            Iterator = 1;
          break;
          case(1):
            moveNeck('_');
            moveArm('R', 'L', 'I');            
            moveArm('L', 'L', 'I');
            Iterator = 2;
          break;
          case(2): Iterator = -1;
          break;
        }
      }
    }
    
  }else if (Name == "AAB"){
    //
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 1000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('_');
            moveArm('R', 'M', 'O');
            moveArm('L', 'M', 'O');
            Iterator = 1;
          break;
          case(1):
            moveNeck('R');
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'I');
            Iterator = 2;
          break;
          case(2):
            moveNeck('R');
            moveArm('R', 'L', 'm');
            moveArm('L', 'L', 'm');
            Iterator = 3;
          break;
          case(3):
            moveNeck('_');
            moveArm('R', 'L', 'O');
            moveArm('L', 'L', 'O');
            Iterator = 4;
          break;
          case(4): Iterator = -1;
          break;
        }
      }
    }
    
  }else if (Name == "AAC"){
    //Scratch head
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 1000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('_');
            moveArm('R', 'H', 'O');
            moveArm('L', 'L', 'I');
            Iterator = 1;
          break;
          case(1):
            moveNeck('L');
            moveArm('R', 'H', 'M');
            moveArm('L', 'L', 'I');
            Iterator = 2;
          break;
          case(2):
            moveNeck('L');
            moveArm('R', 'H', 'O');
            moveArm('L', 'L', 'I');
            Iterator = 3;
          break;
          case(3):
            moveNeck('L');
            moveArm('R', 'H', 'M');
            moveArm('L', 'L', 'I');
            Iterator = 4;
          break;
          case(4):
            moveNeck('L');
            moveArm('R', 'H', 'O');
            moveArm('L', 'L', 'I');
            Iterator = 5;
          break;
          case(5):
            moveNeck('_');
            moveArm('R', 'L', 'O');
            moveArm('L', 'L', 'O');
            Iterator = 6;
          break;
          case(6):
            moveNeck('_');
            moveArm('R', 'L', 'm');
            moveArm('L', 'L', 'm');
            Iterator = 7;
          break;
          case(7): Iterator = -1;
          break;
        }
      }
    }
    
  }else if (Name == "BAB"){
    //Emote: ponpon Alternate
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 1000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('_');
            moveArm('R', 'L', 'O');
            moveArm('L', 'L', 'I');
            Iterator = 1;
          break;
          case(1):
            moveNeck('_');
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'O');
            Timer += 1000;
            Iterator = 2;
          break;
          case(2): Iterator = -1;
          break;
        }
      }
    }
  }else if (Name == "BAC"){
    
  }else if (Name == "BBA"){
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 2000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('_');
            moveArm('R', 'L', 'O');
            moveArm('L', 'L', 'O');
            Iterator = 1;
          break;
          case(1): Iterator = -1;
          break;
        }
      }
    }
    
    
  }else if (Name == "CAA"){
    //nod head
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 1000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('F');
            moveArm('R', 'L', 'M');
            moveArm('L', 'L', 'M');
            Iterator = 1;
          break;
          case(1):
            moveNeck('_');
            Iterator = 2;
          break;
          case(2):
            moveNeck('F');
            Iterator = 3;
          break;
          case(3):
            moveNeck('_');
            Iterator = 4;
          break;
          case(4): Iterator = -1;
          break;
        }
      }
    }
    
  }else if (Name == "CAB"){
    //Bellylaugh
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 600){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('B');
            moveArm('R', 'M', 'I');
            moveArm('L', 'M', 'I');
            Iterator = 1;
          break;
          case(1):
            moveNeck('_');
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'I');
            Iterator = 2;
          break;
          case(2):
            moveNeck('B');
            moveArm('R', 'M', 'I');
            moveArm('L', 'M', 'I');
            Iterator = 3;
          break;
          case(3):
            moveNeck('_');
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'I');
            Iterator = 4;
          break;
          case(4):
            moveNeck('B');
            moveArm('R', 'M', 'I');
            moveArm('L', 'M', 'I');
            Iterator = 5;
          break;
          case(5):
            moveNeck('_');
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'I');
            Iterator = 6;
          break;
          case(6): Iterator = -1;
          break;
        }
      }
    }
    
  }else if (Name == "CAC"){
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 2000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('b');
            moveArm('R', 'L', 'M');
            moveArm('L', 'L', 'M');
            Iterator = 1;
          break;
          case(1): Iterator = -1;
          break;
        }
      }
    }
    
  }else if (Name == "CCC"){
    //Emote: proper bow
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 1000){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('_');
            moveArm('R', 'L', 'M');
            moveArm('L', 'L', 'M');
            Iterator = 1;
          break;
          case(1):
            moveNeck('_');
            moveArm('R', 'H', 'O');
            moveArm('L', 'H', 'O');
            Iterator = 2;
          break;
          case(2):
            moveNeck('F');
            moveArm('R', 'L', 'O');
            moveArm('L', 'L', 'O');
            Iterator = 3;
          break;
          case(3):
            moveNeck('_');
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'I');
            Iterator = 4;
          break;
          case(4): Iterator = -1;
          break;
        }
      }
    }
    
  }else if (Name == "CBA"){
    while(Iterator > -1){
      smoothMove();
      if(millis() - Timer >= 600){
        Timer = millis();
        switch(Iterator){
          case(0):
            moveNeck('_');
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'I');
            Iterator = 1;
          break;
          case(1):
            moveArm('R', 'L', 'M');
            moveArm('L', 'L', 'M');
            Iterator = 2;
          break;
          case(2):
            moveArm('R', 'L', 'I');
            moveArm('L', 'L', 'I');
            Iterator = 3;
          break;
          case(3):
            moveArm('R', 'L', 'M');
            moveArm('L', 'L', 'M');
            Iterator = 4;
          break;
          case(4):
            moveArm('R', 'M', 'O');
            moveArm('L', 'M', 'O');
            Iterator = 5;
          break;
          case(5): Iterator = -1;
          break;
        }
      }
    }
    
  }
}
  
//________________________________________+++ Void moveArm +++________________________________________
void moveArm(char Side, char Shoulder, char Arm){
  //Serial.print("Move arm");
  if(Side == 'R'){
    //Switch case for shoulder
    switch(Shoulder){
      case('H'):
        //RShoulder.write(180);
        RShoulderDest = 120;
      break;
      case('M'):
        //RShoulder.write(135);
        RShoulderDest = 90;
      break;
      case('L'):
        //RShoulder.write(90);
        RShoulderDest = 60;
      break;
    }
  
    //Switch case for arm
    switch(Arm){
      case('I'):
        //RArm.write(135);
        RArmDest = 65;
      break;
      case('M'):
        //RArm.write(45);
        RArmDest = 90;
      break;
      case('m'):
        //LArm.write(20);
        RArmDest = 90;
      break;
      case('O'):
        //RArm.write(0);
        RArmDest = 130;
      break;
    }
  }
  else if(Side == 'L'){
    //Switch case for shoulder
    switch(Shoulder){
      case('H'):
        //LShoulder.write(0);
        LShoulderDest = 60;
      break;
      case('M'):
        //LShoulder.write(45);
        LShoulderDest = 90;
      break;
      case('L'):
        //LShoulder.write(90);
        LShoulderDest = 120;
      break;
    }
  
    //Switch case for arm
    switch(Arm){
      case('I'):
        //LArm.write(45);
        LArmDest = 115;
      break;
      case('M'):
        //LArm.write(135);
        LArmDest = 90;
      break;
      case('m'):
        //LArm.write(160);
        LArmDest = 90;
      break;
      case('O'):
        //LArm.write(180);
        LArmDest = 50;
      break;
    }
  }
}

//________________________________________+++ Void smoothMove +++________________________________________
void smoothMove(){
  //Serial.print(".");
  if(millis() - MoveTimer >= 10){
    MoveTimer = millis();
    if(ArmSmooth == 0){
      RArm.write(RArmDest);
      LArm.write(LArmDest);
    }else{
      RArm.write(RArmCurr + ((RArmDest - RArmCurr) / abs(RArmDest - RArmCurr)));
      RArmCurr += ((RArmDest - RArmCurr) / abs(RArmDest - RArmCurr));
      LArm.write(LArmCurr + ((LArmDest - LArmCurr) / abs(LArmDest - LArmCurr)));
      LArmCurr += ((LArmDest - LArmCurr) / abs(LArmDest - LArmCurr));
    }
    
    if(ShoulderSmooth == 0){
      RShoulder.write(RShoulderDest);
      LShoulder.write(LShoulderDest);
    }else{
      RShoulder.write(RShoulderCurr + ((RShoulderDest - RShoulderCurr) / abs(RShoulderDest - RShoulderCurr)));
      RShoulderCurr += ((RShoulderDest - RShoulderCurr) / abs(RShoulderDest - RShoulderCurr));
      LShoulder.write(LShoulderCurr + ((LShoulderDest - LShoulderCurr) / abs(LShoulderDest - LShoulderCurr)));
      LShoulderCurr += ((LShoulderDest - LShoulderCurr) / abs(LShoulderDest - LShoulderCurr));
    }
    
    if(NeckSmooth == 0){
      RNeck.write(RNeckDest);
      LNeck.write(LNeckDest);
    }else{
      RNeck.write(RNeckCurr + ((RNeckDest - RNeckCurr) / abs(RNeckDest - RNeckCurr)));
      RNeckCurr += ((RNeckDest - RNeckCurr) / abs(RNeckDest - RNeckCurr));
      LNeck.write(LNeckCurr + ((LNeckDest - LNeckCurr) / abs(LNeckDest - LNeckCurr)));
      LNeckCurr += ((LNeckDest - LNeckCurr) / abs(LNeckDest - LNeckCurr));
    }
  }
}

//________________________________________+++ Void moveNeck +++________________________________________
void moveNeck(char Orientation){
  switch(Orientation){
    case('F'):
      NeckExtra = 10;
      RNeckDest = 150;
      LNeckDest = 30;
    break;
    case('B'):
      NeckExtra = -10;
      RNeckDest = 90;
      LNeckDest = 90;
    break;
    case('b'):
      RNeckDest = 110;
      LNeckDest = 70;
    break;
    case('R'):
      RNeckDest = 90;
      LNeckDest = 20;
    break;
    case('L'):
      RNeckDest = 160;
      LNeckDest = 90;
    break;
    case('_'):
      RNeckDest = 115 - NeckExtra;
      LNeckDest = 65 + NeckExtra;
    break;
  }
}

//________________________________________+++ Void Interpret +++________________________________________
// input types (A: .),(B: -),(C: ..),(D: --)
void interpret(){
  if(digitalRead(InputLink) == HIGH){
    delay(CommDelay * 2);
    if(digitalRead(InputLink) == HIGH){
      delay(CommDelay * 4);
      if(digitalRead(InputLink) == LOW){
        //longbeep
        Serial.println("longbeep");
        InputCache += "B";
      }else{
        Serial.println("delete");
        delay(CommDelay * 6);
        InputCommand = InputCache;
        Serial.println(InputCommand);
        gesture(InputCommand);
        InputCache = "";
      }
    }else{
      delay(CommDelay * 2);
      if(digitalRead(InputLink) == HIGH){
        //doublebeep
        delay(CommDelay * 1);
        Serial.println("doublebeep");
        InputCache += "C";
      }else{
        //shortbeep
        delay(CommDelay * 1);
        Serial.println("shortbeep");
        InputCache += "A";
      }
    }
  }
}
