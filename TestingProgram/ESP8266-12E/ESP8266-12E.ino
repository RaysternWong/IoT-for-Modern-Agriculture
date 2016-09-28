#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define PIN1 1
#define PIN2 2
#define PIN3 3

WiFiClient client;

String apiWrite = "DRW5K6F91WT954LA"; //The Key for write data to channel
String apiRead  = "QW4PODDM2Q96LA24"; //The Key for read data from channel

const char* ssid = "familywong88";
const char* password = "72680384";
const char* server = "api.thingspeak.com";

SoftwareSerial wifi(2,3);

void setup() {

  connectToWifi(ssid,password);

}

void loop() { 

 
}

void connectToWifi(const char *ssid,const char *password){
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
 
  Serial.print("\n\nConnecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}




void writeToField1(float data){
  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiWrite;
           postStr +="&field1=";
           postStr += String(data);
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

  // thingspeak needs 15 sec delay between updates
  delay(16000); 
}

int readSignalFrom(int pinNum){
  
}


