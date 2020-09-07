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
    _moistureData = convertToPercentage(analogValue);
    String data = _moistureData + _unit;
    return data;
}

/**
 * @brief 
 * 
 * @return String 
 */
String SoilMoistureSensor::getName() 
{
    return _name;
}

/**
 * @brief 
 * 
 * @return String 
 */
String SoilMoistureSensor::getNameAndData()
{
    String nameAndData = "";
    nameAndData += getName();
    nameAndData += ": ";
    nameAndData += getData();
    return nameAndData;
};

/**
 * @brief Reads analog value of soil moisture sensor.
 * 
 * @return double Returns the value read. Between 
 */
double SoilMoistureSensor::readData() 
{
    return analogRead(SOIL_MOISTURE_1_PIN);
}

/**
 * @brief Private function for converting the read analog value to moisture in percentage.
 * 
 * @param data Analog value from Soil Moisture Sensor.
 * @return double percentage of moisture measured in the soil.
 */
double SoilMoistureSensor::convertToPercentage(double analogValue) 
{
    double soilmoisturepercent = 0;
    soilmoisturepercent = map(analogValue, _dryValue, _wetValue, 0, 100);
    soilmoisturepercent = soilmoisturepercent > 100 ? 100 : soilmoisturepercent;
    soilmoisturepercent = soilmoisturepercent < 0 ? 0 : soilmoisturepercent;
    return soilmoisturepercent;
}