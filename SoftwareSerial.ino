#include <SoftwareSerial.h>
SoftwareSerial NewSerial(10,11);
int led = 13;
void setup() {
  Serial.begin(9600);
  NewSerial.begin(9600);
  NewSerial.write("Please enter: \n");
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  if (NewSerial.available()>0) {
    char onscreen = NewSerial.read();
    function(onscreen);
  }
}

void function(int onscreen) {
  if (onscreen == '1') {
    NewSerial.write("2 times!!");
    for (int i = 0; i<2; i=i+1) {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  }

  if (onscreen == '0') {
    NewSerial.write("3 times!!");
    for (int i = 0; i<3; i=i+1) {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  }
}

// Functions
// if(Serial)
// available()
// availableForWrite()
// begin()
// end()
// find()
// findUntil()
// flush()
// parseFloat()
// parseInt()
// peek()
// print()
// println()
// read()
// readBytes()
// readBytesUntil()
// readString()
// readStringUntil()
// setTimeout()
// write()
// serialEvent()