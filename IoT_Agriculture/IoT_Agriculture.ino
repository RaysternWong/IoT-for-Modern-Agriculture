#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <SimpleDHT.h>
#include "ThingSpeak.h"
#include "Network.h"
#include "Setting.h"
#include "Photoresistor.h"
#include "WaterLevelSensor.h"

unsigned long monitorChannel = 0 ;  // Replace 0 with your monitor channel ID
const char *monitorWrite = "";      // Type in your write api key inside ""
const char *monitorRead  = "";      // Type in your read api key inside ""

const char* ssid = "";              // Type in your ssid inside ""
const char* password = "";          // Type in your password inside "", if doesn't has just leave it blank

WiFiClient  client;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(BAUDRATE);
  delay(10);
  connectToWifi(ssid,password); 
  BLINK_INTERNAL_LED;           //Blink for indicate WiFI is connected
  pinMode( PH_POWER, OUTPUT );
  pinMode( WL_POWER, OUTPUT );

  ThingSpeak.begin(client);
  Serial.println("\n");
}

void loop(){
  byte temperature = 0, humidity = 0;
  int illuminance = 0, waterLevel = 0;

  illuminance = readBrightness(PHOTO_PIN);
  waterLevel  = readWaterLevel(WATER_LEVEL_PIN);
  dht11.read(DHT11_PIN, &temperature, &humidity, NULL);

  Serial.print("Temperature              : ");
  Serial.print(temperature);
  Serial.println(" celcius");

  Serial.print("Relative Humidity        : ");
  Serial.print(humidity);
  Serial.println(" percent");
             
  Serial.printf("Illuminance (Brightness) : %d Lux\n", illuminance);
  Serial.printf("Water level (Millimeter) : %d mm\n\n", waterLevel);

  Serial.println("Writting data to ThingSpeak......");
  ThingSpeak.setField(1, (int)temperature);
  ThingSpeak.setField(2, (int)humidity);
  ThingSpeak.setField(3, illuminance);
  ThingSpeak.setField(4, waterLevel);
  ThingSpeak.writeFields(monitorChannel, monitorWrite);  

  Serial.println("ThingSpeak only accept updates every 15 seconds, please wait for next update\n\n");
  delay(17000);  //Wait 17 sec for safe
}
