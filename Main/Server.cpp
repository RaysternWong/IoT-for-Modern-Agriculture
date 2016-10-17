#include <ThingSpeak.h>
#include "Server.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

WiFiClient client2;

const char* thingSpeakIP = "api.thingspeak.com"; // "184.106.153.149"

void writeDataToThingSpeak(String writeDetails, String apiWrite){
  if (client2.connect(thingSpeakIP,80)) {  //   "184.106.153.149" or api.thingspeak.com
     client2.print("POST /update HTTP/1.1\n"); 
     client2.print("Host: api.thingspeak.com\n"); 
     client2.print("Connection: close\n"); 
     client2.print("X-THINGSPEAKAPIKEY: "+apiWrite+"\n"); 
     client2.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client2.print("Content-Length: "); 
     client2.print(writeDetails.length()); 
     client2.print("\n\n"); 
     client2.print(writeDetails);
  }
  client2.stop();
   
     
 
}


