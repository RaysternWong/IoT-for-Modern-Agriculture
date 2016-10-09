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

//const char* ssid = "TARUC Wireless";
//const char* password = "";

const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  connectToWifi(ssid,password);
}

void loop() {
  /*
  // read the input on analog pin 0:
  int sensorValue = analogRead(12);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  Serial.print("V");

  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiWrite;
           postStr +="&field1=";
           postStr += String(voltage);
           postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n"); 
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiWrite+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(postStr.length()); 
     client.print("\n\n"); 
     client.print(postStr);
             
  }
  client.stop();
   
  Serial.println("Waiting...");    
  // thingspeak needs minimum 15 sec delay between updates
  delay(20000);  
  */
}
