/*
 GPS Shield Altitude Example using the EM406 GPS Unit-- TimeStamp Example Code
 By: Derek Runberg
 SparkFun Electronics
 Date: December 14th, 2015
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

Example code to use the GPS Shield paired with the EM406 GPS unit. The example code parses the current date and time and creates
a string to use for setting a timestamp for data logging..

 Hardware Hookup:
 -GPS Shield -- Make sure all pins are aligned and inserted into the Arduino female headers
 -EM406 GPS Unit hooked up to the GPS Shield using the shot GPS cable
 - GPS Power switch 'ON'
 - Serial selection set to DLINE
 */


#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 4800;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup() {
 Serial.begin(115200);
  ss.begin(GPSBaud);

}

void loop() {
  Serial.println("-------GPS Time Stamp---------"); 
 if (gps.date.isValid())
  {
    Serial.print("Date: ");
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
    Serial.print(" , ");
  }
  else
  {
    Serial.print(F("Date ERROR!"));
  }

if (gps.time.isValid())
  {
    Serial.print("Time: ");
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("Time Error!"));
  }
}
