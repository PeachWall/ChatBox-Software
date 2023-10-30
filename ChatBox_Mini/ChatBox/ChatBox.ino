#define Buzzer 9
#define MaskSensor 13

String PyInput = ""; //for pyserial communication
String Intent;
String Behaviour;
int Intensity;

bool Mask = false;

//________________________________________+++ Void Setup +++________________________________________
void setup() {
  Serial.begin(9600);

  servo_init();
  
  pinMode(Buzzer, OUTPUT);
  pinMode(MaskSensor, INPUT);
  
  Expression("Greet");
}

//________________________________________+++ Void Loop +++________________________________________
void loop() {
  if(digitalRead(MaskSensor) == LOW){
    if(Mask == false) {
      Expression("Default");
      Beep(2);
      Mask = true;
    }
    PyReceive(Serial.available() > 0);
  }else{
    if(Mask == true) {
      Expression("Sleep");
      Mask = false;
    }
  }
}

//________________________________________+++ Void Beep +++________________________________________
void Beep(int repeat){
  // This function beeps a given amount of times, using a for loop
  // input: repeat(the numebr of times it beeps)
  // output: null
  for(int i=0; i<repeat; i++){
    digitalWrite(Buzzer, HIGH);
    delay(100);
    digitalWrite(Buzzer, LOW);
    delay(100);
  }
}
