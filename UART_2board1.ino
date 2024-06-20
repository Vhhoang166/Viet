#include <SoftwareSerial.h>
SoftwareSerial NewSerial(10,11);
void setup() {
  Serial.begin(9600);
  NewSerial.begin(9600);
  Serial.write("Please enter: \n"); 
}

void loop() { 
  String readString;
  String q;
  while (NewSerial.available()) {
    delay(1);
    char onscreen = NewSerial.read();
    Serial.print(onscreen);
    if (isControl(onscreen)) break;
  }
  while (Serial.available()) {
    delay(1);
    char c = Serial.read();
    if (isControl(c)) {
      break;
    }
    readString +=c;
  }
  q = readString;
  if (readString == "one") {
    NewSerial.write("1");
    Serial.print("1 is sent\n");
  }
  if (readString == "two") {
    NewSerial.write("2");
    Serial.print("2 is sent\n");
  }
}

