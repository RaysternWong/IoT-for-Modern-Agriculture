#include "Server.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

WiFiClient client;

const char* thingSpeakIP = "api.thingspeak.com"; // "184.106.153.149"

void writeDataToThingSpeak(float data, String apiWrite, String field){
  if (client.connect(thingSpeakIP,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr  = field;          // apiKey
           postStr += "=";            // apiKey field1 = 
           postStr += String(data);   // apiKey field1 = data
 
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
  delay(16000);   // thingspeak needs minimum 15 sec delay between updates
}


