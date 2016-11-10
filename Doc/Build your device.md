<h1><ins>Build your device</ins></h1>

<h4> Nodemcu Pin </h4>
<img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Data/NodeMCU%20Pin%20Map.png" />

<h4> This is how the circuit look like </h4>
   <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Resources/circuit%20diagram.PNG" alt="circuit" />

1. As long the as USB power is connected, NodeMCU can support 3V output voltage from 3V3 pin, or 5V voltage from Vin pin. For make our life simple, just power the device with micro usb charger, rather than go prepare an external power supply.
2. Connect 3V3 pin or Vin pin to your VCC, and GND pin to ground.
3. Connect DHT11's data pin to D7, GND for ground and VCC for VCC.
4. Connect water level sensour '+'pin to D5, '-'pin to ground, 's' pin to 100 ohms -> 80 ohms -> ground.
5. Connect photoresistor to D1 and the opposite to 10k ohms -> ground , from the between, connect to 2k ohms-> 1k ohms -> ground.
6. Connect RSV pin to the the middle of resistors as diagram shown above.

<h2><ins>Why the circuit like this?</ins></h2>
Nodemcu has only 1 [ADC](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/using-the-arduino-addon) pin, which can read the voltage value, for non ADC pins can only read high or low.
In order to read the value of brightness and water level, this 2 sensor has to been [power control](http://www.instructables.com/id/ESP8266-with-Multiple-Analog-Sensors/) by nodeMCU output pin, when one sensor is on another should be off.
And then, this ADC pins only can read the voltage range from 0V to 1V, so you have to scale down the sensor's output to 1V by using voltage divider circuit.
(Transistor switch is not comfortable use in this case due to there is 0.7 bias voltage)

<h6> My circuit device </h6>
 <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Resources/My%20Circuit.jpg" />
 
 
 
