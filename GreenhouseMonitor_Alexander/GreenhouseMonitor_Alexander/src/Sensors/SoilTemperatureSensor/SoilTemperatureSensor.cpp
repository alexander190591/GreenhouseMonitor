/**
 * @file SoilTemperatureSensor.cpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief Implementation of the Soil temperature sensor class. Temperature sensor is the DS18B20.
 *        More info here: https://randomnerdtutorials.com/esp32-ds18b20-temperature-arduino-ide/
 * @version 1.0
 * @date 2020-09-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "SoilTemperatureSensor.hpp"
#include "../../../lib/defines.hpp"                         // For custom pin defenitions on the ESP32

/**
 * @brief Construct a new Soil Temperature Sensor:: Soil Temperature Sensor object.
 *        Sets up the OneWire object to listen to the data-pin connected to the DS18B20 soil temperature sensor.
 *        Sets up the protocol translating object (made by Dallas Temperature).
 */
SoilTemperatureSensor::SoilTemperatureSensor() 
{
    // Setup
    _oneWire = new OneWire(SOIL_TEMPERATURE_1_PIN);          // Setup a oneWire instance to communicate with any OneWire device.
    _tempSensor = new DallasTemperature(&(*_oneWire));       // Pass the oneWire reference to Dallas Temperature.

    _tempSensor->begin();                                    // Start up the Dallas Temperature library.
}

/**
 * @brief Method called to receive the temperature in degrees Celcius as a string.
 * 
 * @return String containing the temperature in degrees Celcius.
 */
String SoilTemperatureSensor::getData() 
{
    String data = readTemp() + _unit;
    return data;
}

/**
 * @brief Method called to receive the name of the sensor as a String.
 * 
 * @return String containing the name of the sensor.
 */
String SoilTemperatureSensor::getName() 
{
    return _name;
}

/**
 * @brief Method called to receive the name of the sensor and temperature measured in degrees Celcius as a String.
 * 
 * @return String containing name of the sensor and the temperature measured in degrees Celcius.
 */
String SoilTemperatureSensor::getNameAndData() 
{
    String nameAndData = "";
    nameAndData += getName();
    nameAndData += ": ";
    nameAndData += getData();
    return nameAndData;
}

/**
 * @brief Private method used to request the temperature from the temperature sensor and receive the temperature in degrees Celcius as a double.
 * 
 * @return double containing the temperature in degrees Celcius.
 */
double SoilTemperatureSensor::readTemp() 
{
    _tempSensor->requestTemperatures();                     // Method needed to be able to call getTempCByIndex(0).

    return _tempSensor->getTempCByIndex(0);
}