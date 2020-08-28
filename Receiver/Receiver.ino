#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK rf_driver;


// Variables for storeing time related information

String str_year;
String str_month;
String str_day;
String str_hour;
String str_minute;
String str_second;
String str_out;


void setup() {
  Serial.begin(9600); //Begin der seriellen Kommunikation mit 9600 baud.
  rf_driver.init(); // PIN D11
  
}
void loop() {
  
  // Set buffer to size of expected message
  uint8_t buf[14];
  uint8_t buflen = sizeof(buf);
  // Check if received packet is correct size
  if (rf_driver.recv(buf, &buflen))
  { 
    // Message received with valid checksum
    // Get received values into string
    str_out = String((char*)buf);
    Serial.println("-------");
    Serial.println(str_out);

    str_year = str_out.substring(0, 4);
    str_month = str_out.substring(4, 6);
    str_day = str_out.substring(6, 8);
    str_hour = str_out.substring(8, 10);
    str_minute = str_out.substring(10, 12);
    str_second = str_out.substring(12, 14);
    
    
    Serial.print("Message Received: ");
    Serial.println((char*)buf);   
    Serial.println("Decoded Message: ");
    Serial.println("Date: " + str_day + "." + str_month + "." + str_year);
    Serial.println("Time: " + str_hour + ":" + str_minute + ":" + str_second);      
    
    
  }
}
