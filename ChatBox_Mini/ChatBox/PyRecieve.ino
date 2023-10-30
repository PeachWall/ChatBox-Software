
//---------------------------------- PyReceive ----------------------------------//
void PyReceive(bool SerialOn) {
  if (SerialOn == true) {
    PyInput = "";
    PyInput = Serial.readStringUntil('\n');
    Serial.println("Received" + PyInput);
    //MoveMouth('O');
    
    if (PyInput.length() <= 2) {
      //Manually typed input
      Beep(1);
      if (Intent == "Welcome") {
        Expression("Greet");
        Expression("Default");
      } else {
        Expression("Agree");
        Expression("Default");
      }
    } else {
      //Voice detected input
      Beep(1);
      Intent = SplitString(PyInput, '/', 0);
      Intensity = SplitString(PyInput, '/', 1).toInt();
      Behaviour = SplitString(PyInput, '/', 2);
      Serial.println(Intent);
      
      if (Intent == "SmallTalk" || Intent == "Expression") {
        Expression("Express");
        Expression("Default");
      }
      else if (Intent == "Greeting" || Intent == "Wave") {
        //Execute greeting gesture
        Expression("Greet");
        Expression("Default");
      }
      else if (Intent == "Fallback") {
        Expression("Confusion");
        Expression("Default");
      }
      else if (Intent == "Good") {
        Expression("Happy");
        Expression("Default");
      }
      else if (Intent == "Bad") {
        Expression("Sad");
        Expression("Default");
      }
      //MoveMouth('C');
    }
  }
}

//---------------------------------- Void SplitString ----------------------------------//
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
