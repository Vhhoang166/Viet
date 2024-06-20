#include <Arduino.h>
void setup() {
  Serial.begin(9600); // Baud Rate = 9600
  Serial.println("<Arduino is ready>"); // in + xuống dòng
  pinMode(LED_BUILTIN, OUTPUT);
}
void processReceivedChar(char receivedChar) {
  if (receivedChar == '1') {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Turned on LED");
}
  else if (receivedChar == '0') {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Turned off LED");
  }
  else {
    Serial.print("Unknown Command: ");
    Serial.println(receivedChar);
  }
}

void loop() {
  if (Serial.available() > 0) { //Serial.available(): nhận đủ 8 bit sẽ trả lại giá trị >0 
                                //--> đã có dữ liệu nên sẽ dùng read() để đọc dữ liệu đó
    char receivedChar = Serial.read(); // đọc kí tự, .readString(): chuyển thành chuỗi sau khi đọc
    processReceivedChar(receivedChar);
  }
}