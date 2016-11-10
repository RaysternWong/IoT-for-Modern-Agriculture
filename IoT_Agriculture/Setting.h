#ifndef Setting_H
#define Setting_H
#include <SoftwareSerial.h>

#define BAUDRATE        115200

//Real Pin            GPIO Pin
#define D0                  16
#define D1                   5
#define D2                   4
#define D3                   0
#define D4                   2
#define D5                  14
#define D6                  12
#define D7                  13
#define D8                  15
#define RSV                 A0    //In my situation, arduino take RSV pin (just near by A0) as ADC pin, this case was brief by ESP8266 data sheet

#define A0_internat_value   6    //There was an reading of RSV pin by analogRead(RSV) even it is not connected to output voltage
                                  //So the value has to include for indicate it is the minimum reading
#define LED                 D6
#define DHT11_PIN           D7    //Use D7 pin to collect data from DHT11
#define PHOTO_PIN           RSV   //Use RSV pin to collect data from photoresistor and water level sensor
#define WATER_LEVEL_PIN     RSV   //In order collect data without conflict, use output pin as supply voltage for manually turn on and off of the sensors
#define PH_POWER            D1    //Use D1 supply voltage to photoresistor
#define WL_POWER            D5    //Use D2 supply voltage to water level sensor   

#define INTERNAL_LED        D0    //D0 is connected to NodeMCU's internal Blue LED
#define BLINK_INTERNAL_LED  pinMode(INTERNAL_LED, OUTPUT);  delay(1000);  pinMode(INTERNAL_LED, INPUT); 

#endif // Setting_H
