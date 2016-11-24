<h1>Flash my firmware</h1>

1. Go to my [open source branch](https://github.com/Raydivine/IoT-of-Modern-Agriculture/tree/openSource) , and download the repo by clicking "clone or download" -> "download zip"
<hr/>
2. Extract the zip file, inside the folder, click "IoT_Agriculture" to open my firmware

   <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Arduino/project%20file.PNG" />
<hr/>
3. Replace your channel ID, write api key and read api key into my code
   
   <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Arduino/Replace%20id%20and%20key.PNG"/>   
<hr/>   
4. Click compile and upload button (top left) to upload the firmware to your board
  
   <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Arduino/compile%20and%20upload.PNG" />
<hr/>
5. After uploaded, open the serial port monitor ( top right)
   <br/>
   <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Arduino/serial%20monitor.PNG"/>
   <br/>
   Set the baudrate to 115200, and 'BOTH NL & CR' 
   <br/>
   
   <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/Arduino/Print%20out%20message.PNG"/>
   <br/>
   
   If you cannot scan any network but you know there is network around your board, then means you board's wifi is not working, please      read [this](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Solve%20WiFi%20issue.md) to solve it.
   <br/>
   
   The message above is printed by my firmware code, every time the board start up, it will scan the target available network first,        then only connect to target network, this feature is is implement for troubleShoot purpose.
   <br/>
   
   <b><ins>If the target SSID cannot be connected, the case can be</ins></b><br/>
   a. The SSID is not available<br/>
   b. The distance is too long<br/>
   c. The password is wrong<br/>
   d. The SSID its self doesn't has internet connectivity<br/>
   e. The board's WiFi is not working<br/>
  
   By scanning the available WiFi's first before connect it, we can identify the situation, if the target SSID is scanned but not          connected, then we can known the case is belong to 'c' or 'd'. The WiFi scan feature can be removed, if you don't expect to do troubleShoot.
   <br/>
   
   If your board is working, you are able to see a complete 1 cycle message as shown above <i>(Ignore brightness control message, I  did not implement it in openSource branch)</i>, 
   <br/>
   please do remember test your board with reset and power cycle to ensure it is working consistency.
   <br/>
  
   After 1 cycle is run, you should be able to see the data updated in your thingSpeak channel.
   <br/>
   
   <img src="https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Image/ThingSpeak/channel%20updating.PNG" />
   
