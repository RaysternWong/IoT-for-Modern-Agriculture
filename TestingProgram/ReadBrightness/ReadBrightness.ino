
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

#define READ_MIN 3
#define READ_MAX 870
#define BIRGHTNESS_MIN 0
#define BIRGHTNESS_MAX 35000

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(D1,OUTPUT );
}

// the loop routine runs over and over again forever:
void loop() {

  //Serial.println("Write High");

  digitalWrite(D1,HIGH);
  delay(500);
  int val = analogRead(A0);
  int illuminance = map(val, READ_MIN , READ_MAX, BIRGHTNESS_MIN , BIRGHTNESS_MAX);
  Serial.println(val);
  Serial.printf("%d Lux\n\n",illuminance);

  digitalWrite(D1,LOW);
  /*
  int phValue = analogRead(A0);
  int illuminance = map(phValue, 5 , 1024, 0 , 35000);
  Serial.println(phValue);
  Serial.printf("%d Lux\n\n",illuminance);
  digitalWrite(D1,LOW);
  /*
  //Serial.println("Write Low");
 
  phValue = analogRead(A0);
  illuminance = map(phValue, 0 , 1023, 0 , 32000);
  Serial.println(phValue);
  Serial.printf("%d Lux\n\n",illuminance);
*/
  delay(1000);
}
