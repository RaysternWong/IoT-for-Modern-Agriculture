<h1>IoT-of-Modern-Agriculture</h1>

<h2>A nodeMCU embedded system for IoT of agriculture application</h2>
<i>   This is an environment monitoring project by using IoT technology, the monitoring object are temperature, humidity, brightness and rain density. This project is build for investigating how does IoT(Internet of Things) apply in modern agriculture, so it is named as its intend.</i>
<hr/>

<h3>Overview</h3>

 <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Agriculture/self%20farming.jpg" width="45%" height="250px" />  <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Agriculture/farm%20monitor.jpg" width="45%" height="45%" />

   <ins><i>If you are doing self farming, sometime when you are out of home, or going to travel, there is no body take care your farm, so what to do when your farm need to be watering?</i></ins>
  
By applying IoT technology, you can know your farm condition in 24 hours at anywhere. Let say you found the rain density is too low, you can send a HTTP request from your server (or let it be automatic) to activate an watering machine, or turn on LED light when sun light is not sufficient.
   
For a perfect agriculture monitoring system, the soil moisture , nutrient and air quality data are necessary be monitoring too. Apologize that I could not get those sensors, so they are not implementing in this firmware. I will explain how to use and improve my project, you are welcome to take , modifiy and republish it.
  
<h3>Introduction</h3>
1. [IoT ( Internet of things)](https://en.wikipedia.org/wiki/Internet_of_things)
2. [How does IoT involved in modern agriculture ](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Modern%20Agriculture.md)

<h3>Resources and Server</h3>
3. The [Components](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Component.md) are used in this project for collect environment data and then upload to server.
4. This [Server](https://thingspeak.com) is used for application monitor , analysis and action.

<h3>Procedure</h3>
5. [Build your device](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Build%20your%20device.md)
6. [Setup your server](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Register%20ThingSpeak.md)
7. [Setup your Arduino](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Setup%20Arduino.md)
8. [Connect your device to PC](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Connect%20Device%20to%20PC.md)
9. [Flash my firmware](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Flash%20my%20firmware.md)

<h3>Regards</h3>
Appreciate to the developers produced [NodeMCU's arduino framework](https://github.com/esp8266/Arduino), it make my life simple.
For NodeMCU learners, it is good that you start with arduino due its friendly developing environment, if you face any problem please look for help in their project repo, there is large number of members which can answer your question rapidly.

You can ask me question by creating an issue, I will reply you when I get my email reminded.
If you are using LUA please go to [ESP8266 Community Forum](http://www.esp8266.com/index.php?sid=7377269ab4c35f67c420ac8a88e5aeb3)</i> to look for help.

This project is welcome anyone to copy, modify and republish.<br/>
See the [LICENSE](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/LICENSE) file for license rights and limitations (MIT).

<!--
<h3>My server</h3>
a. [Monitor](https://thingspeak.com/channels/169688) channel is for collecting data and visualize them in graph form <br/>
b. [Analysis](https://thingspeak.com/channels/171094) channel is for investigate the data characteristics , apply with modern knowledge to calculate&get new data.<br/>
c. [Task](https://thingspeak.com/channels/171780) channel is for controlling purpose, the WiFi module will upload the on-time data to server, then server will do control adjust and write the instruction to this channel, finally the WiFi module will read the instruction from this channel and then perform the action. 
--->

