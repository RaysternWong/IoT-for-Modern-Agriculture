
#define D1 5

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(D1,OUTPUT );

}

// the loop routine runs over and over again forever:
void loop() {

  Serial.println("Write High");

  digitalWrite(D1,HIGH);
  int phValue = analogRead(A0);
  float phVoltage = phValue * (1.0 / 1023.0);
  int illuminance = phVoltage * 32000; // using the ratio : 0.01V =  320Lus , where 1V = 32000Lux
  Serial.println(phValue);
  Serial.println(phVoltage);
  Serial.printf("%d Lux\n",illuminance);
  /*
  Serial.println("Write Low");
  digitalWrite(D1,LOW);
  phValue = analogRead(A0);
  phVoltage = phValue * (1.0 / 1023.0);
  Serial.println(phValue);
  Serial.println(phVoltage);
  */
  
  delay(1000);


}
