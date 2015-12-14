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
  if (gps.time.isValid())
  {
    Serial.println("--------Current Time------");

    Serial.print(gps.time.hour());
    Serial.print(F(":"));

    if(gps.time.minute()<10)
    {
      Serial.print("0");
    }
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
   
    Serial.println(gps.time.second());

    delay(5000);
  }
  else if(gps.charsProcessed()<10)
  {
    Serial.println("...");
  }
  }
 }


