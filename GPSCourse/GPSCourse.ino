/*
 GPS Shield Altitude Example using the EM406 GPS Unit-- Course and Cardinal Direction Example Code
 By: Derek Runberg
 SparkFun Electronics
 Date: December 14th, 2015
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

Example code to use the GPS Shield paired with the EM406 GPS unit. The example code parses the current heading of 
the unit as well as the cardinal direction to the "home" coordinates.

Swap out the the HOME_LAT and HOME_LON with a coordinate set that you would like to use.

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

//set GPS point for your home or location you want to measure the distance to 
static const double HOME_LAT = 45.495335, HOME_LON = -122.935516;
void setup() {
  Serial.begin(9600);
  ss.begin(GPSBaud);

}

void loop() {
 if(ss.available()>0&&gps.encode(ss.read()) )
 {
  if (gps.location.isValid())
  {
    Serial.println("--------Current Course and Cardinal Direction to Home------");
     unsigned long courseToHome = TinyGPSPlus::courseTo(gps.location.lat(),gps.location.lng(),HOME_LAT, HOME_LON);
    Serial.print("Course to Home: ");
    Serial.print(courseToHome);
    Serial.print(" , ");

    const char *cardinalToHome = TinyGPSPlus::cardinal(courseToHome);
    Serial.print("Cardinal Direction: ");
    Serial.println(cardinalToHome);

    delay(5000);
  }
  else if(gps.charsProcessed()<10)
  {
    Serial.println("...");
  }
  }
 }


