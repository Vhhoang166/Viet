#include<SPI.h>
#define outputLED 6
volatile boolean received;
volatile byte Slavereceived,Slavesend;
//To make sure variables shared between an ISR
// and the main program are updated correctly
int x; String readString;
void setup() {
  Serial.begin(9600);
  
  pinMode(outputLED,OUTPUT);               
  pinMode(MISO,OUTPUT);                  
  //Sets MISO as OUTPUT (Have to Send data to Master IN
  SPCR |= _BV(SPE); //Turn on SPI in Slave Mode                 

  SPI.attachInterrupt();
  // or attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  // Interupt free the microcontroller to get 
  //some other work done while not missing the input.
} 
  ISR (SPI_STC_vect) { 
  //SPI Serial Transfer Complete (SPI_STC) interrupt vector
    Slavereceived = SPDR; 
    // Value received from master if store in variable slavereceived    
    received = true;                        
}

void loop() {
  while (Serial.available()) {
    delay(1);
    char c = Serial.read();
    if (isControl(c)) {
      break;
    }
    readString +=c;
  }

  if (Slavereceived == 1) {
    Serial.print("received\n");
    digitalWrite(outputLED,HIGH); 
    delay(100); 
  }  
  else if (Slavereceived == 0) {
    Serial.print("not received\n");
    digitalWrite(outputLED,LOW);
    delay(100); 
  }

  if (readString== "1") x=1;
  else if (readString =="0") x=0;
  Slavesend=x; //Sends the x value to master via SPDR                        
  SPDR = Slavesend; 
  readString = ""; // Reset readString for the next input
  delay(300);                     
}