#include  <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>



void handle_OnConnect();
void handle_onboardLedOn();
void handle_onboardLedOff();
void handle_NotFound();

#define SERIAL_BAUDRATE 9600 //Used for serial printing to monitor

//LED VARIABLES:
#define ONBOARD_LED 2
bool ONBOARD_LED_STATUS = LOW;
//END LED VARIABLES

//HTTP VARIABLES:
const char* ssid = "FTTH_XB6940";
const char* password = "CeipgemRoyb5";
WebServer server(80);
//END HTTP VARIABLE




void setup() {

  
  Serial.begin(SERIAL_BAUDRATE);
  delay(100); //delay because why not??
  pinMode(ONBOARD_LED, OUTPUT);
  Serial.println("Connection to: ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password); // Connecting to local wi-fi network
  WiFi.setHostname("GreenhouseMonitor_Tobias");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/onboardled_on", handle_onboardLedOn);
  server.on("/onboardled_off", handle_onboardLedOff);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");  
  
  
}

void loop() {
 
  server.handleClient();
  if(ONBOARD_LED_STATUS)
  {
    digitalWrite(ONBOARD_LED,HIGH);
  }

}

void handle_OnConnect()
{
  ONBOARD_LED_STATUS = LOW;
}

void handle_onboardLedOn()
{

}

void handle_onboardLedOff()
{

}

void handle_NotFound()
{
  
}

