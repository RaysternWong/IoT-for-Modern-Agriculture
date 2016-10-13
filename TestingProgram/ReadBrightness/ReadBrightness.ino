#include "user_modules.h"

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(A0,INPUT );

}

// the loop routine runs over and over again forever:
void loop() {

  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (3.3 / 1023.0);


  Serial.println();
  Serial.println(sensorValue);
  Serial.println(voltage);

  delay(1500);
}
