#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

const char* ssid = "familywong88";
const char* password = "72680384";
 
void setup() {
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


void loop() { 

}
