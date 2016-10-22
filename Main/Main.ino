#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include "DHT.h"
#include "Server.h"
#include "Network.h"
#include "Setting.h"
#include "Photoresistor.h"
#include "WaterLevelSensor.h"

unsigned long monitorChannel = 169688;
const char *monitorWrite = "GB91TIAKXFPD6JNX"; //The Key for write data to channel
const char *monitorRead  = "0N7QYR503X9K51FA"; //The Key for read data from channel

unsigned long analysisChannel = 171094;
const char *analysisWrite = "4JCJEWOPSIBJHMV2"; 
const char *analysisRead  = "S0Z31XZI8CHT9JDQ"; 

unsigned long operationChannel = 171780;
const char *operationWrite = "XY2RZA5HK5ADFW2F"; 
const char *operationRead  = "RJI8HKEATJP2H5EM"; 

const char* ssid = "familywong88";
const char* password = "72680384";

//const char* ssid = "TARUC Wireless";
//const char* password = "";

DHT dht(D7, DHT11,15); //Using D7 as receive pin, snesor type is DHT11, byte count is 15

WiFiClient  client;

void setup() {
  Serial.begin(BAUDRATE);
  delay(10);

  //You might want to use WiFi.mode(WIFI_STA) to set your esp's wifi to station mode
  //I set it in AT command due to required of ESPressif Based firmware
  connectToWifi(ssid,password);
  ThingSpeak.begin(client);
  
  pinMode( PH_POWER, OUTPUT );
  pinMode( WL_POWER, OUTPUT );
  pinMode( LED, OUTPUT );

  Serial.println("\n");
}

void loop() {
  float temperature = 0, humidity = 0;
  int illuminance = 0, waterLevel = 0;

  illuminance = readBrightness(PHOTO_PIN);
  waterLevel  = readWaterLevel(WATER_LEVEL_PIN);
  temperature = dht.readTemperature(); //In celcius(°C)
  humidity    = dht.readHumidity();    //is return Relative Humidity, in percent(%)
  
  Serial.print("Temperature              : ");
  Serial.print(temperature);
  Serial.println(" celcius");

  Serial.print("Relative Humidity        : ");
  Serial.print(humidity);
  Serial.println(" percent");
             
  Serial.printf("Illuminance (Brightness) : %d Lux\n", illuminance);
  Serial.printf("Water level (Millimeter) : %d mm\n\n", waterLevel);

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, illuminance);
  ThingSpeak.setField(4, waterLevel);
  ThingSpeak.writeFields(monitorChannel, monitorWrite);  

  Serial.println("Reading brightness control from ThingSpeak......");
  int ledBrightness = ThingSpeak.readFloatField(operationChannel, 2);
  Serial.printf("Set LedBrightness to     : %d Lux\n", ledBrightness);
   
  ledBrightness = map(ledBrightness, 0, 35000, 0, 255);
  analogWrite(LED, ledBrightness);

  Serial.println("ThingSpeak only accept updates every 15 seconds, please wait for next update\n\n");
  delay(13000);  // Due to read LED brighntess need 3 second, so set the delay value as 13 second
}
