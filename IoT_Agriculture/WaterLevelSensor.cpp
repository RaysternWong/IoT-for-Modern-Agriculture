#include "WaterLevelSensor.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Setting.h"

/*
  Please visit https://codebender.cc/sketch:135119#%5Barduino-tutorial%5D%20Water%20Level%20Sensor%20(40mm).ino
  to known how to read data from water level sensor, take note that the sensor output is not directly proportional, 
  so you have to manually measure in multiple point by using analogRead(WATER_LEVEL_PIN), the use map() to scale them in different level
*/
#define  _0MM   A0_internat_value 
#define  _5MM   454
#define _10MM   487
#define _15MM   570
#define _20MM   638
#define _25MM   655
#define _30MM   662
#define _35MM   687
#define _40MM   700

#define BELOW_5MM(v)              (v >  _0MM && v <= _5MM )
#define BELOW_10MM(v)             (v >  _5MM && v <= _10MM)
#define BELOW_15MM(v)             (v > _10MM && v <= _15MM)
#define BELOW_20MM(v)             (v > _15MM && v <= _20MM)
#define BELOW_25MM(v)             (v > _20MM && v <= _25MM)
#define BELOW_30MM(v)             (v > _25MM && v <= _30MM)
#define BELOW_35MM(v)             (v > _35MM && v <= _35MM)
#define BELOW_40MM(v)             (v > _35MM && v <= _40MM)

#define MEASURE_IN_5MM(v)         waterLevel = map(v,  _0MM , _5MM , 0  , 5 ) 
#define MEASURE_IN_10MM(v)        waterLevel = map(v,  _5MM , _10MM, 5  , 10) 
#define MEASURE_IN_15MM(v)        waterLevel = map(v, _10MM , _15MM, 10 , 15) 
#define MEASURE_IN_20MM(v)        waterLevel = map(v, _15MM , _20MM, 15 , 20)
#define MEASURE_IN_25MM(v)        waterLevel = map(v, _20MM , _25MM, 20 , 25) 
#define MEASURE_IN_30MM(v)        waterLevel = map(v, _25MM , _30MM, 25 , 30) 
#define MEASURE_IN_35MM(v)        waterLevel = map(v, _30MM , _35MM, 30 , 35) 
#define MEASURE_IN_40MM(v)        waterLevel = map(v, _35MM , _40MM, 35 , 40)  

int readWaterLevel(int pinNum){
  int waterLevel, sensorValue;
  digitalWrite(WL_POWER, HIGH); //Turn on the sensor
  delay(500);
  sensorValue = analogRead(WATER_LEVEL_PIN);

  if  BELOW_5MM(sensorValue)  
    MEASURE_IN_5MM(sensorValue);
    
  else if BELOW_10MM(sensorValue) 
    MEASURE_IN_10MM(sensorValue);
    
  else if BELOW_15MM(sensorValue) 
    MEASURE_IN_15MM(sensorValue);
    
  else if BELOW_20MM(sensorValue) 
    MEASURE_IN_20MM(sensorValue);
    
  else if BELOW_25MM(sensorValue) 
    MEASURE_IN_25MM(sensorValue);
    
  else if BELOW_30MM(sensorValue) 
    MEASURE_IN_30MM(sensorValue);
    
  else if BELOW_35MM(sensorValue) 
    MEASURE_IN_35MM(sensorValue);
    
  else  MEASURE_IN_40MM(sensorValue);

  digitalWrite(WL_POWER, LOW);  //Turn off the sensor
  return ( waterLevel > 40 ? 40 : waterLevel);  //Maximum return is 40mm
}

