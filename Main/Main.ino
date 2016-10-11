#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#include "Server.h"
#include "Network.h"

#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12
#define D7  13
#define D8  15
#define D9  3
#define D10 1

#define BAUDRATE 115200

String apiWrite = "DRW5K6F91WT954LA"; //The Key for write data to channel
String apiRead  = "QW4PODDM2Q96LA24"; //The Key for read data from channel

const char* ssid = "familywong88";
const char* password = "72680384";

//const char* ssid = "TARUC Wireless";
//const char* password = "";
//const char* server = "api.thingspeak.com";

DHT dht(D8, DHT11,15); //Using D8 as receive pin, snesor type is DHT11, byte count is 15

void setup() {
  Serial.begin(BAUDRATE);
  delay(10);

  Serial.println("\n");
  connectToWifi(ssid,password);
}

void loop() {
  float h =0, t = 0;
  h = dht.readHumidity();
  t = dht.readTemperature();
  
  Serial.print("\nTemperature : ");
  Serial.print(t);
  Serial.print("Degree Celcius  Humidity : ");
  Serial.print(h);
  Serial.print("AH\n");


  Serial.println();

  delay(2000);  
}
