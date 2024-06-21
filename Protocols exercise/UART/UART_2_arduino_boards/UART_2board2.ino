#include <SoftwareSerial.h>
SoftwareSerial NewSerial2(11,10);
int led = 13;
void setup() {
  Serial.begin(9600);
  NewSerial2.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  String readString2;
  while (NewSerial2.available()) {
    delay(1);
    char onscreen2 = NewSerial2.read();
    if (isControl(onscreen2)) break;
    readString2 +=onscreen2;
  }
  while (Serial.available()) {
    delay(1);
    char c = Serial.read();
    if (isControl(c)) {
      break;
    }
  }

  if (readString2 == "1") {
    Serial.print("1 is received!!\n");
    for (int i = 0; i<1; i=i+1) {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  }

  if (readString2 == "2") {
    Serial.print("2 is received!!\n");
    for (int i = 0; i<2; i=i+1) {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  }
}
