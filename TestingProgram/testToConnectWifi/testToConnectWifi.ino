#include <ESP8266WiFi.h>                  // Include ESP8266 library
const char* ssid = "familywong88";           // SSID is set
const char* password = "72680384";   // Password is set
#define LEDpin D0
void setup()
{
  Serial.begin(115200);                   // Enable UART
  Serial.println();
  Serial.print("Connecting to ");         // Print title message to the serial monitor
  Serial.println(ssid);                   // Print SSID name
  pinMode(LEDpin, OUTPUT);
  digitalWrite(LEDpin,HIGH);              // WiFi detected indicator - active low
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);             // Send password
  while (WiFi.status() != WL_CONNECTED)   // Check WiFi status
  {
    delay(200);
    digitalWrite(LEDpin, LOW);
    Serial.print(".");                    // Print dot for showing the progress status
    delay(200);
    digitalWrite(LEDpin, HIGH);    
  }
  Serial.println("");
  WiFi.printDiag(Serial);
  Serial.println("");
  Serial.println("WiFi connected");       // Print the connected message
  Serial.println("IP address: ");         // Print IP address
  Serial.println(WiFi.localIP());
}
void loop()
{
  digitalWrite(LEDpin, LOW);              // WiFi connected indicator - active low
  while (WiFi.status() != WL_CONNECTED)   // Check WiFi status
  {
    digitalWrite(LEDpin, 0);              // LED at D0 blink when disconnect WiFi
    delay(900);
    Serial.println("connection WiFi failed");   // Print error message to Serial Monitor
    digitalWrite(LEDpin, 1);
    delay(100);
  }
}
