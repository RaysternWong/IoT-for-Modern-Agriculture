#include "Photoresistor.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Setting.h"

#define READ_MIN 3
#define READ_MAX 870
#define BIRGHTNESS_MIN 0
#define BIRGHTNESS_MAX 35000

int readBrightness(int pinNum){
  digitalWrite(PH_POWER, HIGH);  //Turn on photoresistor
  delay(500);
  
  int val = analogRead(pinNum);
  int illuminance = map(val, READ_MIN , READ_MAX, BIRGHTNESS_MIN , BIRGHTNESS_MAX);
  digitalWrite(PH_POWER, LOW);   //Turn off photoresistor
  
  return illuminance;
}

