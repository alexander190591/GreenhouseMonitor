#include  <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>
#include "GreenhouseMonitor/GreenhouseMonitor.hpp"



void handle_OnConnect();
void handle_onboardLedOn();
void handle_onboardLedOff();
void handle_NotFound();
String SendHTML(uint8_t led1stat);

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
  else
  {
    digitalWrite(ONBOARD_LED, LOW);
  }
  

}

void handle_OnConnect()
{
  ONBOARD_LED_STATUS = LOW;
  server.send(200, "text/html", SendHTML(ONBOARD_LED_STATUS));
}

void handle_onboardLedOn()
{
  ONBOARD_LED_STATUS = HIGH;
  Serial.println("ONBOARD_LED Status: ON");
  server.send(200, "text/html", SendHTML(ONBOARD_LED_STATUS));
}

void handle_onboardLedOff()
{
  ONBOARD_LED_STATUS = LOW;
  Serial.println("ONBOARD_LED Status: OFF");
  server.send(200, "text/html", SendHTML(ONBOARD_LED_STATUS));
}

void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}


String SendHTML(uint8_t led1stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>GreenhouseMonitor_Tobias</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>GreenhouseMonitor_Tobias</h1>\n";
  
   if(led1stat)
  {ptr +="<p>ONBOARD_LED Status: ON</p><a class=\"button button-off\" href=\"/onboardled_off\">OFF</a>\n";}
  else
  {ptr +="<p>ONBOARD_LED Status: OFF</p><a class=\"button button-on\" href=\"/onboardled_on\">ON</a>\n";}

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

