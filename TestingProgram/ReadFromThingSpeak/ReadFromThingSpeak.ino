#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

String apiWrite = "GB91TIAKXFPD6JNX"; //The Key for write data to channel
String apiRead  = "0N7QYR503X9K51FA"; //The Key for read data from channel

const char* ssid = "familywong88";
const char* password = "72680384";

WiFiClient  client;


unsigned long weatherStationChannelNumber = 171780;
unsigned int temperatureFieldNumber = 2;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop() {
  float ledBrightness = ThingSpeak.readFloatField(weatherStationChannelNumber, temperatureFieldNumber);

  Serial.print("Current ledBrightness is: "); 
  Serial.print(ledBrightness);
  Serial.println(" Lux\n\n"); 

//  delay(15000); // Note that the weather station only updates once a minute
  
}
