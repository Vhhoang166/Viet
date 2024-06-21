#include <Wire.h>
int x = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(9);
  Wire.write(x);
  Wire.endTransmission();
  x++;
  if (x>5) {x=0;}
  Serial.println(x);
  delay(500);
}

// Wire library:
// begin() - Initialise the I2C bus
// end() - Close the I2C bus
// requestFrom()- Request bytes from a peripheral device
// beginTransmission() - Begins queueing up a transmission
// endTransmission() - Transmit the bytes that have been queued and end the transmission
// write() - Writes data from peripheral to controller or vice versa
// available() - returns the number of bytes available for retrieval
// read() - Reads a byte that was transmitted from a peripheral to a controller.
// setClock() - Modify the clock frequency
// onReceive() - Register a function to be called when a peripheral receives a transmission
// onRequest() - Register a function to be called when a controller requests data
// setWireTimeout() - Sets the timeout for transmissions in controller mode
// clearWireTimeoutFlag() - Clears the timeout flag
// getWireTimeoutFlag() - Checks whether a timeout has occurred since the last time the flag was cleared.
