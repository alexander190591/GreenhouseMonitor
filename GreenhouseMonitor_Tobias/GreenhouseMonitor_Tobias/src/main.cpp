#include  <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>
#include "GreenhouseMonitor/GreenhouseMonitor.hpp"
#include "../src/GreenhouseMonitor/Server/Webserver.hpp"

#define SERIAL_BAUDRATE 9600 //Used for serial printing to monitor

//LED VARIABLES:
#define ONBOARD_LED 2
bool ONBOARD_LED_STATUS = LOW;
//END LED VARIABLES

//HTTP VARIABLES:
const char* ssid = "FTTH_XB6940";
const char* password = "CeipgemRoyb5";



//END HTTP VARIABLE

Webserver _testServer("GreenhouseMonitor_Tobias", ssid, password);




void setup() {
  _testServer.setHostName("GreenhouseMonitor_Tobias");
  _testServer.startServer();
  
  Serial.begin(SERIAL_BAUDRATE);
  delay(100); //delay because why not??
  pinMode(ONBOARD_LED, OUTPUT);
  Serial.println("Connection to: ");
  Serial.println(ssid);


  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  Serial.println("HTTP server started");  
  
  
}

void loop() {
 


  _testServer.handleClient();
  
}



