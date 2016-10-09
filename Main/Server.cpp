#include "Server.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <string.h>

void connectToWifi(const char *ssid,const char *password){
  scanSSID(ssid);
  connectSSID(ssid,password);
}

void scanSSID(const char *ssid){
  Serial.println("scan start");

  int n = WiFi.scanNetworks();  // WiFi.scanNetworks will return the number of networks found
  Serial.printf("scan done, %d networks found\n", n);
  
  for (int i = 0; i < n; ++i){
    // Print SSID and RSSI for each network found
    Serial.printf("%d :",i + 1);
    Serial.print(WiFi.SSID(i));
    Serial.print(" (");
    Serial.print(WiFi.RSSI(i));
    Serial.print(")");
    Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
    delay(10);
  }
  Serial.println("");
}


void connectSSID(const char *ssid,const char *password){
  Serial.printf("\n\nConnecting to %s\n", ssid);
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.printf("IP address: ");
  Serial.println(WiFi.localIP());
}



