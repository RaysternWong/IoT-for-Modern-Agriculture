#include <SoftwareSerial.h>

SoftwareSerial Wifi(2,3); //pin2 as RX pin, pin3 as TX pin

void setup() {
  Serial.begin(9600);
  Serial.println("Wifi Started");
  Wifi.begin(9600);

}


void loop() { 
  
  if (Wifi.available()) {
    Serial.write(Wifi.read());
  }
  if (Serial.available()) {
    Wifi.write(Serial.read());
  }
}
