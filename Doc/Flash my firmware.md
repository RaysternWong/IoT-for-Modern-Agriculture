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
   
   The message above is printed by my firmware code, every time the board start up, it will scan the target WiFi's SSID first, then only    connect it. This feature is implemented for troubleshoot purpose.  <br/>
   
   <b><ins>If the target SSID cannot be connected, the case can be</ins></b><br/>
   a. The SSID is not available<br/>
   b. The distance is too long<br/>
   c. The password is wrong<br/>
   d. The SSID its self doesn't has internet connectivity<br/>
   e. The board's WiFi is not working<br/><br/>
   
   If you cannot scan any network but you know there is network around your board, than means you board's wifi is not working, please      read [this](https://github.com/Raydivine/IoT-of-Modern-Agriculture/blob/master/Doc/Solve%20WiFi%20issue.md) to solve it.
   <br/>
   
   By scanning the available WiFi's at beginning can let us identify the situation, if the target SSID is scanned but not connected then    we can known it is the case is belong to 'c' or 'd'. You can remove the WiFi's scan feature if you don't expect to do any                troubleshooting.
   <br/>
   
   You are able to see a complete 1 cycle message as shown above if your board is working. 
   <br/>
   <i>(Ignore brightness control message, I  did not implement it in openSource branch)</i>
   <br/>
   
   After 1 cycle is run, you should be able to see the data updated in your thingSpeak channel, please do remember test your board with    reset and power cycle to ensure it is working consistency.
