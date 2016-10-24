#ifndef Setting_H
#define Setting_H

#define VCC 3.3   //Using NodeMCU internal 3.3 output voltage
#define ADC 1     //NodeMCU ADC pin only can read the voltage between 0~1V

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

#define RSV A0    //In my situation, arduino take RSV pin (just near by A0) as ADC pin, this case was brief by ESP8266 data sheet
#define A0_internat_value 6


#define DHT11_PIN         D6      //Use D6 pin conecct DHT11
#define PHOTO_PIN         RSV     //Photoresistor and water level sensor share the pin of RSV
#define WATER_LEVEL_PIN   RSV     

//Because the RSV pin is shared by 2 sensor, so the sensors has to use GPIO as supply
//RSV can collect each data by taking round of power on the sensor
#define  PH_POWER  D1 //Use D1 as photoresistor supply voltage
#define  WL_POWER  D5 //Use D5 as water level sensor supply voltage
#define  LED       D3

#define BAUDRATE 115200


#endif // Setting_H
