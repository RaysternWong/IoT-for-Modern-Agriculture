#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
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

#define WRITE_DATA_TO_FILED1(data)  writeDataToThingSpeak(data, apiWrite, "field1")

String apiWrite = "DRW5K6F91WT954LA"; //The Key for write data to channel
String apiRead  = "QW4PODDM2Q96LA24"; //The Key for read data from channel

const char* ssid = "familywong88";
const char* password = "72680384";

//const char* ssid = "TARUC Wireless";
//const char* password = "";

 //const char* server = "api.thingspeak.com";


void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println("\n");
  connectToWifi(ssid,password);
}

void loop() {
  int data1 = 0;
  data1 = digitalRead(D6);
  Serial.println(data1);
  
  WRITE_DATA_TO_FILED1(data1);
  
  delay(2000);  
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
