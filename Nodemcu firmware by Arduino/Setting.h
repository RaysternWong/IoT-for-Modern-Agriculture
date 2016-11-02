#ifndef Setting_H
#define Setting_H
#include <SoftwareSerial.h>

#define BAUDRATE          115200
#define VCC               3.3   //Using NodeMCU internal 3.3 output voltage
#define ADC               1     //NodeMCU ADC pin only can read the voltage between 0~1V

#define D0                16
#define D1                 5
#define D2                 4
#define D3                 0
#define D4                 2
#define D5                14
#define D6                12
#define D7                13
#define D8                15
#define RSV               A0    //In my situation, arduino take RSV pin (just near by A0) as ADC pin, this case was brief by ESP8266 data sheet
#define A0_internat_value 6

#define PH_POWER          D1      //Use D1 as photoresistor supply voltage
#define WL_POWER          D5      //Use D2 as water level sensor supply voltage
#define LED               D6
#define DHT11_PIN         D7      //Use D7 pin conecct DHT11
#define PHOTO_PIN         RSV     //RSV pin is collecting birghntess data and water level data from D1 and D5 ,  by take turn power on and off them
#define WATER_LEVEL_PIN   RSV     

#define INTERNAL_LED      D0      //D0 is connected to internal Blue LED

#define BLINK_INTERNAL_LED      pinMode(INTERNAL_LED, OUTPUT);  delay(1000);  pinMode(INTERNAL_LED, INPUT);  

#endif // Setting_H
