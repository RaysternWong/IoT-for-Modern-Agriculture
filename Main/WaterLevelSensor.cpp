#include "WaterLevelSensor.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Setting.h"

/*  The water level sensor's output is logaritham graph form.
 *   
 *   My measurement
 * 
 * -------------------------------------------
 *    Water height(mm)    |   analogRead(A0) |
 * -------------------------------------------
 *         0.5            |       532        |
 *         1.0            |       600        | 
 *         1.5            |       648        | 
 *         2.0            |       700        | 
 *         2.5            |       759        | 
 *         3.0            |       784        |
 *         3.5            |       792        |
 *         4.0            |       805        |         
*/

/*
int readWaterLevel(int pinNum){
  int waterHeight, sensorValue;
  digitalWrite(D5, HIGH);
  delay(500);
  sensorValue = analogRead(WATER_LEVEL_PIN);

  if( sensorValue >= 0 && sensorValue <= 532 )
    waterHeight = map(sensorValue, 11 , 532, 0 , 5);
    
  else if( sensorValue > 532 && sensorValue <= 600 )
    waterHeight = map(sensorValue, 533 , 600, 5 , 10);
    
  else if( sensorValue > 600 && sensorValue <= 648 )
    waterHeight = map(sensorValue, 601 , 648, 10 , 15);
    
  else if( sensorValue > 648 && sensorValue <= 700 )
    waterHeight = map(sensorValue, 649 , 700, 15 , 20);
    
  else if( sensorValue > 700 && sensorValue <= 759 )
    waterHeight = map(sensorValue, 701 , 759, 20 , 25);
    
  else if( sensorValue > 759 && sensorValue <= 784 )
    waterHeight = map(sensorValue, 760 , 784, 25 , 30);
    
  else if( sensorValue > 784 && sensorValue <= 792 )
    waterHeight = map(sensorValue, 785 , 792, 30 , 35);

  else waterHeight = map(sensorValue, 793 , 805, 35 , 40);

  waterHeight = ( waterHeight > 40 ? 40 : waterHeight);

  digitalWrite(D5, LOW);

  return waterHeight;
}*/

