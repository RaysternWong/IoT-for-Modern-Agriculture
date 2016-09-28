#include "Server.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>


void connectToWifi(const char *ssid,const char *password){
  Serial.begin(9600);
  delay(10);

  Serial.print("\n\nConnecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
