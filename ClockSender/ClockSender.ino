// Include the necessary libraries
  
#include <Wire.h>
#include "RTClib.h" // Clock library
#include <RH_ASK.h> // Sender library
#include <SPI.h>
  
// object of RTClib library
RTC_DS3231 rtc;
  
// object from RH_ASK
RH_ASK rf_driver;

//  2D character array to store days information
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Variables for storeing time related information

String str_year;
String str_month;
String str_day;
String str_hour;
String str_minute;
String str_second;
String str_out;

void setup() {


  Serial.begin(9600);
  delay(3000); // wait for console opening

  //// Clock Section ////
  
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
  
  //// Sender Section ////
  
  // Initalize Transmission
  // Standard Pin: D12 
  rf_driver.init();



}

void loop() {
  // put your main code here, to run repeatedly:

    //// Read and print time 
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
    delay(1000);
    
    //// Prepare Sender and message
    str_year = String(now.year());
    str_month = String(now.month());
    if(strlen(str_month.c_str()) < 2)
    {
      str_month = "0" + str_month;
    }
    str_day = String(now.day());
    if(strlen(str_day.c_str()) < 2)
    {
      str_day = "0" + str_day;
    }
    
    str_hour = String(now.hour());
    if(strlen(str_hour.c_str()) < 2)
    {
      str_hour = "0" + str_hour;
    }
    str_minute = String(now.minute());
    if(strlen(str_minute.c_str()) < 2)
    {
      str_minute = "0" + str_minute;
    }
    str_second = String(now.second());
    if(strlen(str_second.c_str()) < 2)
    {
      str_second = "0" + str_second;
    }

    
    // Put together in one string
    str_out = str_year + str_month + str_day + str_hour + str_minute + str_second;
    // Length: 13
  
    
    // Create a char array
    const char *msg = str_out.c_str();

    // Demo message 
    // const char *msg = "Hello World!"; // length 12

    Serial.print("Message that will be sent: ");
    Serial.println(str_out);
    Serial.print("Size of the message: ");
    Serial.println(strlen(msg));
    rf_driver.send((uint8_t *)msg, strlen(msg)); // string version
    rf_driver.waitPacketSent();
    delay(1000);
    
}
