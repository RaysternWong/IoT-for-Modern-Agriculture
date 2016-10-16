#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <stdio.h>
#include "DHT.h"
#include "Server.h"
#include "Network.h"
#include "Setting.h"

String apiWrite = "GB91TIAKXFPD6JNX"; //The Key for write data to channel
String apiRead  = "0N7QYR503X9K51FA"; //The Key for read data from channel

const char* ssid = "familywong88";
const char* password = "72680384";

//const char* ssid = "TARUC Wireless";
//const char* password = "";

DHT dht(D7, DHT11,15); //Using D7 as receive pin, snesor type is DHT11, byte count is 15

/*
  You might want to use WiFi.mode(WIFI_STA) to set your esp's wifi to station mode
  I set it in AT command due to required of ESPressif Based firmware
*/
void setup() {
  Serial.begin(BAUDRATE);
  delay(10);
  connectToWifi(ssid,password);
  Serial.println("\n");
}

void loop() {
  float h =0, t = 0;
  h = dht.readHumidity();
  t = dht.readTemperature();

  Serial.printf("\nTemperature : %d °C\n", (int)t);
  Serial.printf("\nRelative Humidity : %d %\n", (int)h);

  /*
  Serial.print("\nTemperature : ");
  Serial.print(t);
  Serial.print("Degree Celcius  Humidity : ");
  Serial.print(h);
  Serial.print("AH\n");
  */

  String writeDetails = apiWrite;
  writeDetails +=("&field1=" + String(t));
  writeDetails +=("&field2=" + String(h));
  writeDetails +="\r\n\r\n";

  //Serial.println(writeDetails);
  //String writeDetails  ="field1=" + String(t);
  //       writeDetails +="field2=" + String(h);

  writeDataToThingSpeak(writeDetails,apiWrite);
  Serial.println("\n");
  delay(500);  
}
