/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12
#define D7  13
#define D8  15
#define D9  3
#define D10 1

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(D5, OUTPUT);

}


/*  My measurement
 * 
 * -------------------------------------------
 *    Water height(mm)    |   analogRead(A0) |
 * -------------------------------------------
 *         0.5            |       532        |
 *         1.0            |       600        | 
 *         1.5            |       648        | 
 *         2.0            |       700        | 
 *         2.5            |       759        | 
 *         3.0            |       784        |
 *         3.5            |       792        |
 *         4.0            |       805        |         
 */

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int waterHeight;
  int sensorValue;
  digitalWrite(D5, HIGH);
  delay(500);
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);


  if( sensorValue >= 0 && sensorValue <= 532 )
    waterHeight = map(sensorValue, 11 , 532, 0 , 5);
    
  else if( sensorValue > 532 && sensorValue <= 600 )
    waterHeight = map(sensorValue, 533 , 600, 5 , 10);
    
  else if( sensorValue > 600 && sensorValue <= 648 )
    waterHeight = map(sensorValue, 601 , 648, 10 , 15);
    
  else if( sensorValue > 648 && sensorValue <= 700 )
    waterHeight = map(sensorValue, 649 , 700, 15 , 20);
    
  else if( sensorValue > 700 && sensorValue <= 759 )
    waterHeight = map(sensorValue, 701 , 759, 20 , 25);
    
  else if( sensorValue > 759 && sensorValue <= 784 )
    waterHeight = map(sensorValue, 760 , 784, 25 , 30);
    
  else if( sensorValue > 784 && sensorValue <= 792 )
    waterHeight = map(sensorValue, 785 , 792, 30 , 35);

  else waterHeight = map(sensorValue, 793 , 805, 35 , 40);


  waterHeight = ( waterHeight > 40 ? 40 : waterHeight);

  Serial.println(waterHeight);
  digitalWrite(D5, LOW);
  Serial.println();
  delay(1000);        // delay in between reads for stability
}
