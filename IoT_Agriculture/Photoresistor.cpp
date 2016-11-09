#include "Photoresistor.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Setting.h"

//Please visit https://en.wikipedia.org/wiki/Lux to known the calculation of brightness
#define BIRGHTNESS_MIN    0                   // Moonless, overcast night sky
#define BIRGHTNESS_MAX    35000               // Direct sunlight

//Measured the data by analogRead(brightness pin) when is fully dark and fully bright , in order to known the range 
#define READ_MIN          A0_internat_value   // By right should be zero when is fully dark, by there is an internal reading of A0
#define READ_MAX          870                 // Measured under direct flash right


int readBrightness(int pinNum){
  digitalWrite(PH_POWER, HIGH);  //Turn on photoresistor
  delay(500);
  
  int val = analogRead(pinNum);
  int illuminance = map(val, READ_MIN , READ_MAX, BIRGHTNESS_MIN , BIRGHTNESS_MAX);
  digitalWrite(PH_POWER, LOW);   //Turn off photoresistor
  
  return illuminance;
}

