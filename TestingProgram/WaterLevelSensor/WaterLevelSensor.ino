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

#define _40MM 700
#define _35MM 687
#define _30MM 662
#define _25MM 655
#define _20MM 638
#define _15MM 570
#define _10MM 487
#define  _5MM 454

#define BELOW_5MM(v)   (v >   0   && v <= _5MM )
#define BELOW_10MM(v)  (v >  _5MM && v <= _10MM)
#define BELOW_15MM(v)  (v > _10MM && v <= _15MM)
#define BELOW_20MM(v)  (v > _15MM && v <= _20MM)
#define BELOW_25MM(v)  (v > _20MM && v <= _25MM)
#define BELOW_30MM(v)  (v > _25MM && v <= _30MM)
#define BELOW_35MM(v)  (v > _35MM && v <= _35MM)
#define BELOW_40MM(v)  (v > _35MM && v <= _40MM)

#define MEASURE_IN_5MM(v)  waterHeight = map(v,    11 , _5MM , 0  , 5 )  // 11 is the pin's internet voltage, by right it should be 0 if there is no internal voltage
#define MEASURE_IN_10MM(v) waterHeight = map(v,  _5MM , _10MM, 5  , 10) 
#define MEASURE_IN_15MM(v) waterHeight = map(v, _10MM , _15MM, 10 , 15) 
#define MEASURE_IN_20MM(v) waterHeight = map(v, _15MM , _20MM, 15 , 20)
#define MEASURE_IN_25MM(v) waterHeight = map(v, _20MM , _25MM, 20 , 25) 
#define MEASURE_IN_30MM(v) waterHeight = map(v, _25MM , _30MM, 25 , 30) 
#define MEASURE_IN_35MM(v) waterHeight = map(v, _30MM , _35MM, 30 , 35) 
#define MEASURE_IN_40MM(v) waterHeight = map(v, _35MM , _40MM, 35 , 40)  
 
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int waterHeight;
  int sensorValue;
  digitalWrite(D5, HIGH);
  delay(500);
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);


  if      BELOW_5MM(sensorValue)  MEASURE_IN_5MM(sensorValue);
  else if BELOW_10MM(sensorValue) MEASURE_IN_10MM(sensorValue);
  else if BELOW_15MM(sensorValue) MEASURE_IN_15MM(sensorValue);
  else if BELOW_20MM(sensorValue) MEASURE_IN_20MM(sensorValue);
  else if BELOW_25MM(sensorValue) MEASURE_IN_25MM(sensorValue);
  else if BELOW_30MM(sensorValue) MEASURE_IN_30MM(sensorValue);
  else if BELOW_35MM(sensorValue) MEASURE_IN_35MM(sensorValue);
  else                            MEASURE_IN_40MM(sensorValue);



  waterHeight = ( waterHeight > 40 ? 40 : waterHeight);

  Serial.println(waterHeight);
  digitalWrite(D5, LOW);
  Serial.println();
  delay(1000);        // delay in between reads for stability
}
