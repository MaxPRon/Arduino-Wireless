#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK rf_driver;


void setup() {
  Serial.begin(9600); //Begin der seriellen Kommunikation mit 9600 baud.
  rf_driver.init(); // PIN D11
  
}
void loop() {
  
  // Set buffer to size of expected message
  uint8_t buf[24];
  uint8_t buflen = sizeof(buf);
  // Check if received packet is correct size
  if (rf_driver.recv(buf, &buflen))
  {   
    // Message received with valid checksum
    Serial.print("Message Received: ");
    Serial.println((char*)buf);         
  }
}
