# Arduino-Wireless

Simple script to read the time from a Real time clock (RTC) DS3231 transmit it using 433 Mhz sender/receiver modules. For this two Arduino Nano are used where one reads and controls the time and sender. The second one functions as the receiver. (See schematic)


## Used components

- Sender-Receiver 433 Mhz modules:  https://www.amazon.de/Aukru-Superregeneration-Transmitter-Modul-receiver-module/dp/B00OLI93IC
- Arduino Nano: https://store.arduino.cc/arduino-nano
- RTC DS3231 I2C: https://www.amazon.de/AZDelivery-Real-Clock-DS3231-Parent/dp/B07ZQGBH14


## Schematic

![Schematic](/Pictures/Schematic_m.png)

## References:

Code is based on the following:

1. https://draeger-it.blog/arduino-tutorial-433mhz-sender-empfaenger/
2. https://lastminuteengineers.com/ds3231-rtc-arduino-tutorial/
3. https://dronebotworkshop.com/433mhz-rf-modules-arduino/
