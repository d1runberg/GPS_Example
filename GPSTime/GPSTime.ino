/*
 GPS Shield Altitude Example using the EM406 GPS Unit-- Time Example Code
 By: Derek Runberg
 SparkFun Electronics
 Date: December 14th, 2015
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

Example code to use the GPS Shield paired with the EM406 GPS unit. The example code parses the current time from the 
NMEA senetence. Time is based on 24 hour clock.


 Hardware Hookup:
 -GPS Shield -- Make sure all pins are aligned and inserted into the Arduino female headers
 -EM406 GPS Unit hooked up to the GPS Shield using the shot GPS cable
 - GPS Power switch 'ON'
 - Serial selection set to DLINE
 */


#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 2, TXPin = 3;
static const uint32_t GPSBaud = 4800;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  ss.begin(GPSBaud);

}

void loop() {
 if(ss.available()>0&&gps.encode(ss.read()) )
 {
  if (gps.altitude.isValid())
  {
    Serial.println("--------Current Altitude------");

    Serial.print("Altitude(m): ");
    Serial.println(gps.altitude.meters());

    delay(5000);
  }
  else if(gps.charsProcessed()<10)
  {
    Serial.println("...");
  }
  }
 }


