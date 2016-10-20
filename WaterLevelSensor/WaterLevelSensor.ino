/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int waterHeight;
  int sensorValue = analogRead(A0);
/*
  if(sensorValue>690)
    waterHeight = map(sensorValue, 700, 1024, 0, 40);
  else
    waterHeight = 0;
  // print out the value you read:
*/
  if(sensorValue>700)
    waterHeight = 1;
  if(sensorValue>736)
    waterHeight = 5;
  if(sensorValue>790)
    waterHeight = 10;
  if(sensorValue>827)
    waterHeight = 15;
  if(sensorValue>843)
    waterHeight = 20;
  if(sensorValue>857)
    waterHeight = 25;
  if(sensorValue>870)
    waterHeight = 3;
  if(sensorValue>910)
    waterHeight = 3.5;
  if(sensorValue>1010)
    waterHeight = 40;

  
  Serial.println(sensorValue);
  Serial.println(waterHeight);

  Serial.println();
  delay(1000);        // delay in between reads for stability
}
