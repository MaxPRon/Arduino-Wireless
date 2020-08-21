  // Include the necessary libraries
  
  #include <Wire.h>
  #include "RTClib.h"
  #include <RCSwitch.h>
  #include <RH_ASK.h>
  #include <SPI.h>
  
  // object of RTClib library
  RTC_DS3231 rtc;

  // objject rcswitch library
  RCSwitch rcSwitch = RCSwitch(); 

  // object from RH_ASK
  RH_ASK driver

  //  2D character array to store days information
  char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};




void setup() {


  Serial.begin(9600);
  delay(3000); // wait for console opening

  
  if (! rtc.begin()) { // rtc.begin:  function ensures that the RTC module is connected.
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) { // lostPower(): function reads the DS3231’s internal I2C registers to check if the chip has lost track of time. If the function returns true, we can then set the date & time.
    Serial.println("RTC lost power, lets set the time!");
  
  // Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
    // rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
  }

  // Receiver is connected with digital pin 9 
  rcSwitch.enableTransmit(9);


}

void loop() {
  // put your main code here, to run repeatedly:
    DateTime now = rtc.now(); // function returns current date & time. Its return value is usually stored in the variable of datatype DateTime

    // All println are used to format accuaretly
    Serial.println("Current Date & Time: ");
    Serial.print(now.year(), DEC); // function returns current year
    Serial.print('/');
    Serial.print(now.month(), DEC); // function returns current month
    Serial.print('/');
    Serial.print(now.day(), DEC); // function returns current day
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]); // unction returns current day of the week. This function is usually used as an index of a 2D character array that stores days information like the one defined in above program daysOfTheWeek
    Serial.print(") ");
    Serial.print(now.hour(), DEC); // function returns current hour
    Serial.print(':');
    Serial.print(now.minute(), DEC); // function returns current minute
    Serial.print(':');
    Serial.print(now.second(), DEC); // // function returns current second
    Serial.println();

    Serial.println();
    
    Serial.println();
    const char *msg = "hello world";

    //rcSwitch.send(9876,24);
    rcSwitch.send((long unsigned)msg,strlen(msg));
    delay(1000);
    
}