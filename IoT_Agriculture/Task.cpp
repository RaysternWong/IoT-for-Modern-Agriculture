#include "Task.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include "Setting.h"

#define LED_FIELD           1
#define FAN_FIELD           2
#define WATER_PUMP_FIELD    3
#define COOLER_FIELD        4
#define HEATER_FIELD        5

#define VALUE_CONTROL_FOR_DEVICE(device, controlVal, maxValOfDevice )  analogWrite( device, map(controlVal, 0, maxValOfDevice, 0, 255) )

void performTasks(int channel_ID){

  Serial.println("Reading brightness, fanSpeed, heaterValue , coolerValue, waterPumpVal from ThingSpeak......\n");

  int ledBrightness = ThingSpeak.readFloatField(channel_ID, LED_FIELD);
  int fanSpeed      = ThingSpeak.readFloatField(channel_ID, FAN_FIELD);
  int waterPumpVal  = ThingSpeak.readFloatField(channel_ID, WATER_PUMP_FIELD);
  int heaterVal     = ThingSpeak.readFloatField(channel_ID, HEATER_FIELD);
  int coolerVal     = ThingSpeak.readFloatField(channel_ID, COOLER_FIELD);

  Serial.printf("ledBrightness : %d Lux\n", ledBrightness);
  Serial.printf("fanSpeed      : %d \n", fanSpeed);
  Serial.printf("waterPumpVal  : %d \n", waterPumpVal);
  Serial.printf("coolerVal     : %d \n", coolerVal);
  Serial.printf("heaterVal     : %d \n", heaterVal);
  
  VALUE_CONTROL_FOR_DEVICE( LED       , ledBrightness , 35000); //Set 35000 Lux as the max Brightness of LED
  VALUE_CONTROL_FOR_DEVICE( FAN       , fanSpeed      , 1);     //Use 1 and 0 as On/Off, doesn't has value skecthing
  VALUE_CONTROL_FOR_DEVICE( WATER_PUMP, waterPumpVal  , 1);     //Use 1 and 0 as On/Off, doesn't has value skecthing
  VALUE_CONTROL_FOR_DEVICE( COOLER    , coolerVal     , 1);     //Use 1 and 0 as On/Off, doesn't has value skecthing
  VALUE_CONTROL_FOR_DEVICE( HEATER    , heaterVal     , 1);     //Use 1 and 0 as On/Off, doesn't has value skecthing
}

