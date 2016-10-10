#include "Network.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

void connectToWifi(const char *ssid,const char *password){
  if(scanSSID(ssid) == true){
    Serial.printf("%s is found, if the connection time is too long, then you might have wrong password\n\n", ssid);
  }else{
    Serial.printf("%s is not found, but system will try to connect to it, please ensure the distance is close\n\n", ssid);
  }
  connectSSID(ssid,password);
}

bool scanSSID(const char *ssid){
  bool exist = false;
  const char *ID;
  Serial.println("scan start");

  int n = WiFi.scanNetworks();  // WiFi.scanNetworks will return the number of networks found
  Serial.printf("scan done, %d networks found\n", n);
  
  for (int i = 0; i < n; ++i){
    String s = WiFi.SSID(i);
    ID = s.c_str();

    if(strcmp(ssid, ID) == 0)
      exist = true;

    Serial.printf("%d : %s ",i + 1, ID);
    Serial.printf(" (%ld)",WiFi.RSSI(i));
    Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
    delay(10);
  }
  Serial.println();
  return exist;
}

void connectSSID(const char *ssid,const char *password){
  Serial.printf("Connecting to %s\n", ssid);
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.printf("IP address: ");
  Serial.println(WiFi.localIP());
}
