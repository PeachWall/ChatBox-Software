void PyReceive(bool SerialOn) {
  if (SerialOn == true) {
    PyInput = "";
    PyInput = Serial.readStringUntil('\n');
    //MoveMouth('O');
    
    if (PyInput.length() <= 2) {
      Communicate(GestureSignal[PyInput.toInt()][0]);
      Communicate(GestureSignal[PyInput.toInt()][1]);
      Communicate(GestureSignal[PyInput.toInt()][2]);
      Communicate(3);
      if (Intent == "Welcome") {
        Expression("Agree");
        Expression("Static");
      } else {
        Expression("Question");
        Expression("Static");
      }
    } else {
      Intent = SplitString(PyInput, '/', 0);
      Intensity = SplitString(PyInput, '/', 1).toInt();
      Behaviour = SplitString(PyInput, '/', 2);
      //Serial.println(Intent);
      
      if (Intent == "Greeting") {
        //Reaction for Checking in
        if(Behaviour == '?') {
          Communicate(0);
          Communicate(0);
          Communicate(2);
          Communicate(3);
        }else{
          Communicate(2);
          Communicate(0);
          Communicate(0);
          Communicate(3);
        }
      }
      else if (Intent == "expression") {
        //Reaction for Smalltalk response
        Communicate(2);
        Communicate(0);
        Communicate(1);
        Communicate(3);
      }
      else if (Intent == "wave") {
        //Execute greeting gesture
        Communicate(2);
        Communicate(2);
        Communicate(2);
        Communicate(3);
      }
      else if (Intent == "fallback") {
        //Reaction for fallback response
        Communicate(0);
        Communicate(0);
        Communicate(2);
        Communicate(3);
      }
      else if (Intent == "Intro") {
        //Reaction for fallback response
        Communicate(2);
        Communicate(2);
        Communicate(2);
        Communicate(3);
      }
      if (PyInput == "see"){
        check();
      }
      //MoveMouth('C');
    }
  }
}
