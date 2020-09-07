#include <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>
#include "Sensors/SoilMoistureSensor/SoilMoistureSensor.hpp"
#include "Sensors/DummySensor/DummySensor.hpp"
#include "Sensors/ISensor.hpp"

#define LED_PIN 2
#define SERIAL_BAUDRATE 9600

void handle_OnConnect();
void handle_NotFound();
void handle_update();
String SendHTML(uint8_t ledstatus);

// Server stuff
const char* ssid = "FTTH_XB6940";       // SSID for router here
const char* password = "CeipgemRoyb5";  // Password for router here
WebServer server(80);                   // Port 80 is the default HTTP port.

bool LEDstatus = LOW;

// Sensors
ISensor* mySoilMoistureSensor;

void setup()
{
  Serial.begin(SERIAL_BAUDRATE);                   // Serial setup with baud rate.
  delay(100);

  mySoilMoistureSensor = new DummySensor();

  pinMode(LED_PIN, OUTPUT);               // Set LED_PIN as output pin.

  Serial.print("Connecting to "); Serial.println(ssid);

  WiFi.begin(ssid, password);             // Connect to local WiFi network.
  WiFi.setHostname("GreenhouseMonitor-A");
  Serial.print("Host name: "); Serial.println(WiFi.getHostname());
  
  while (WiFi.status() != WL_CONNECTED)   // While connection is not established;
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/update", handle_update);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started.");
}

void loop()
{
  server.handleClient();
  if(LEDstatus)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}

void handle_OnConnect()
{
  LEDstatus = LOW;
  Serial.println("GPIO4 Status: OFF | GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LEDstatus));
}

void handle_update()
{
  if(LEDstatus)
  {
    LEDstatus = LOW;
    Serial.println(mySoilMoistureSensor->getNameAndData());
  }
  else
  {
    LEDstatus = HIGH;
    Serial.println(mySoilMoistureSensor->getNameAndData());
  }

  // String allData;
  // GET ALL SENSOR DATA:
  // for(int i = 0; i < sizeOfArray)

  server.send(200, "text/html", SendHTML(LEDstatus));
}

void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t ledstatus)
{
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>GreenhouseMonitor_Alexander</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 200px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-update {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>GreenhouseMonitor_Alexander</h1>\n";
  ptr +="<h3>Click the button to get the latest data</h3>\n";
  ptr +="<h4>LED Status: ";

  if(ledstatus)
    ptr += "ON";
  else
    ptr +="OFF";

  ptr += "</h4><a class=\"button button-off\" href=\"/update\">UPDATE</a>\n";

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}