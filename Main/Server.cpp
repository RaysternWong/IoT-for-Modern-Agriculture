#include <ThingSpeak.h>
#include "Server.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

WiFiClient client;

const char* thingSpeakIP = "api.thingspeak.com"; // "184.106.153.149"

void writeDataToThingSpeak(String writeDetails, String apiWrite){
  if (client.connect(thingSpeakIP,80)) {  //   "184.106.153.149" or api.thingspeak.com
     client.print("POST /update HTTP/1.1\n"); 
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiWrite+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(writeDetails.length()); 
     client.print("\n\n"); 
     client.print(writeDetails);
  }
  client.stop();
   
  Serial.println("Wait for thingspeak 15sec update delay");    
  delay(16000);   // thingspeak needs minimum 15 sec delay between updates
}


