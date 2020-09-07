/**
 * @file SoilMoistureSensor.cpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "SoilMoistureSensor.hpp"
#include "../../../lib/defines.hpp"

/**
 * @brief Construct a new Soil Moisture Sensor:: Soil Moisture Sensor object
 * 
 */
SoilMoistureSensor::SoilMoistureSensor()
{
    Serial.println("SoilMoistureSensor Constructor.");
}

/**
 * @brief Returns the soil moisture as a percentage between 0% to 100% as a string.
 * 
 * @return String 
 */
String SoilMoistureSensor::getData() 
{
    double analogValue = readData();
    moistureData = convertToRH(analogValue);
    String data = moistureData + unit;
    return data;
}

String SoilMoistureSensor::getName() 
{
    return name;
}

String SoilMoistureSensor::getNameAndData()
{
    String nameAndData = "";
    nameAndData += getName();
    nameAndData += ": ";
    nameAndData += getData();
    return nameAndData;
};

double SoilMoistureSensor::readData() 
{
    return analogRead(ANALOG_PIN_SOIL_MOISTURE);
}

double SoilMoistureSensor::convertToRH(double data) 
{
    double soilmoisturepercent = 0;
    soilmoisturepercent = map(data, dryValue, wetValue, 0, 100);
    soilmoisturepercent = soilmoisturepercent > 100 ? 100 : soilmoisturepercent;
    soilmoisturepercent = soilmoisturepercent < 0 ? 0 : soilmoisturepercent;
    return soilmoisturepercent;
}