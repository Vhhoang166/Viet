//Functions
// SPISettings
// begin()
// beginTransaction()
// endTransaction()
// end()
// setBitOrder()
// setClockDivider()
// setDataMode()
// transfer()
// usingInterrupt()
#include<SPI.h>                                
int x;
String readString;

void setup ()

{
  Serial.begin(9600);                        
  pinMode(LED_BUILTIN,OUTPUT);   
  pinMode(MOSI,OUTPUT);               
  SPI.begin();                            
  SPI.setClockDivider(SPI_CLOCK_DIV8); 
  //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);      
  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave) 
  Serial.print("Pls enter: \n");        
}

void loop() {
  byte m_send, m_receive;  
  while (Serial.available()) {
    delay(1);
    char c = Serial.read();
    Serial.print(c);
    if (isControl(c)) {
      break;
    }
    readString +=c;
  }
  if(readString == "1") {
    x = 1;
  }
  else if (readString == "0") {
    x = 0;
  }      
  m_send = x;
  digitalWrite(SS, LOW);   
  //Starts communication with Slave connected to master                                           
  m_receive = SPI.transfer(m_send); 
  //Send the m_send value to slave also receives value from slave

  int y = m_receive;
  if(y == 1) {
    digitalWrite(LED_BUILTIN,HIGH);  
    Serial.print("Master LED ON\n");      
  }
  else if (y == 0) {
   digitalWrite(LED_BUILTIN,LOW);  
   Serial.print("Master LED OFF\n");         
  }
  else {
    Serial.print("Invalid!\n");
  }
  delay(100);
  digitalWrite(SS, HIGH);
  readString = ""; // Reset readString for the next input
  delay(300);
}
// LED_BUILTIN does not work 
//since it is at gate 13, which becomes SS now.
