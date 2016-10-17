#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#include "Server.h"
#include "Network.h"
#include "Setting.h"
#include "Photoresistor.h"

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
  pinMode( PH_POWER, OUTPUT );
  Serial.println("\n");
}

void loop() {
  float temperature = 0, humidity = 0;
  int illuminance = 0;
  
  temperature = dht.readTemperature(); //In celcius(°C)
  humidity    = dht.readHumidity();    //is return Relative Humidity, in percent(%)
  illuminance = readBrightness(RSV);

  Serial.print("Temperature              :");
  Serial.print(temperature);
  Serial.println(" celcius");
  //Serial.printf("Temperature              : %d celcius\n", (int)temperature);    //%f is not recognize by my Arduino
  Serial.printf("Relative Humidity        : %d percent\n", (int)humidity);             
  Serial.printf("Illuminance (Brightness) : %d Lux\n", illuminance);



  String writeDetails = apiWrite;
  writeDetails +=("&field1=" + String(temperature));
  writeDetails +=("&field2=" + String(humidity));
  writeDetails +=("&field3=" + String(illuminance));
  writeDetails +="\r\n\r\n";

  writeDataToThingSpeak(writeDetails,apiWrite);

  delay(500);  
  Serial.println("\n");
}
