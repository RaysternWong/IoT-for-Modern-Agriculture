<h3>Setup Arduino</h3>

1. Download Arduino IDE from the [official web], if you would like to use portable version then you can download from "Window Zip File"
<hr/>
2. After install IDE, open it and click on File->Preference , copy the URL below into "Addition Board Manager URL"
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   This URL link to resouces of  NodeMCU's Arduino Framework, the framework has contain the low end implementaion like WiFi function. 
 <hr/>
3. Go to Tool->Board->Board Manager, install the NodeMCU's (esp8266) Arduino Framework.

   ![alt text](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Arduino/esp8266%20board%20manager.PNG)

   There was an [Issue](https://github.com/esp8266/Arduino/issues/2265) about framework version 2.3, which the wifi function would not working, I face it too and their suggested solution did not work for me, so I am using version 2.0.
   
   I would recommend you use the lastest version, to test is the Wifi working, you can upload the example skectch from File->Examples->ESP8266WIFI->WIFISCAN to your board, then open the port terminal to observe the print out message for indentify is the WiFi working, please test with reset and power off your board to ensure it is fully working.
   
   If is not working, then you may downgrade the framework by remove the current version first, if you don't remove it I believe the versions may mix together, or it is better you that clear the package manually in C:\Users[username]\AppData\Roaming\Arduino15\packages\esp8266\hardware before install new one
<hr/>
4. Install ThingSpeak Library, this library allow you direct connect to your thingSpeak channel.
   Go to Sketch->Include Library->Manage libraries , search thingSpeak
   
   ![alt text](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Arduino/thingspeak%20library%20manager.PNG)
   
   Install SimpleDHT Library, this library has the functions to read temperature and humidity data from DHT11 sensor
   ![alt text](https://github.com/Raydivine/NodeMCU-with-IoT-practice/blob/master/Doc/Tutorial%20Image/DHT11%20library%20manager.PNG)
   
   <i>Arduino library contain a lot of resources, so you don't have to implement them as long they are found in library.</i>
   
