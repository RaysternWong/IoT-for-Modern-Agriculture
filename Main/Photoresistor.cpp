#include "Photoresistor.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Setting.h"

//Set 0.01V = 320Lus, where 1V = 32000Lux
#define LUS_RATIO 32000 

//1024 - internet = 1024 - 4
#define ReadMax 1020

int readBrightness(int pinNum){
  digitalWrite(PH_POWER, HIGH);  //Turn on photoresistor

  int value = analogRead(A0); 
  Serial.println(value);
  int illuminance = map(value,6, 1024, 0, 32000);

/*
  //AnalogRead return value from 0 to 1024 as voltage range
  float phVoltage = analogRead(pinNum) * (ADC / 1024.0);
  int illuminance = phVoltage * LUS_RATIO; 
*/
  digitalWrite(PH_POWER, LOW);   //Turn off photoresistor
  
  return illuminance;
}

