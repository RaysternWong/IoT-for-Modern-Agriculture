
static const uint8_t D1   = 5;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(5,OUTPUT );

}

// the loop routine runs over and over again forever:
void loop() {

  Serial.println("Write High");
  delay(3000);
  digitalWrite(5,HIGH);
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (1.0 / 1023.0);
  Serial.println(sensorValue);
  Serial.println(voltage);


  Serial.println("Write Low");
  delay(3000);
  digitalWrite(5,LOW);
  sensorValue = analogRead(A0);
  voltage = sensorValue * (1.0 / 1023.0);
  Serial.println(sensorValue);
  Serial.println(voltage);



}
