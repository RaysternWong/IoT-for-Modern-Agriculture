#include "Task.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include "Setting.h"


void control_LED(int channel_ID, int field){
  Serial.println("Reading brightness control from ThingSpeak......");
  int ledBrightness = ThingSpeak.readFloatField(channel_ID, field);
  
  Serial.printf("Set LedBrightness to     : %d Lux\n", ledBrightness);
  ledBrightness = map(ledBrightness, 0, 35000, 0, 255);
  analogWrite(LED, ledBrightness);
}


