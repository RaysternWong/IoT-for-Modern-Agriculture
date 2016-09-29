#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Server.h"

#define PIN1 1
#define PIN2 2
#define PIN3 3

String apiWrite = "DRW5K6F91WT954LA"; //The Key for write data to channel
String apiRead  = "QW4PODDM2Q96LA24"; //The Key for read data from channel

const char* ssid = "familywong88";
const char* password = "72680384";
const char* server = "api.thingspeak.com";

void setup() {
  Serial.begin(115200);
  delay(10);

  connectToWifi(ssid,password);
}

void loop() {
  // put your main code here, to run repeatedly:

}
