#ifndef __SOILTEMPERATURESENSOR_H__
#define __SOILTEMPERATURESENSOR_H__

/**
 * @file SoilTemperatureSensor.hpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief The Soil Temperature Sensor is a DS18B20 Digital Temperature Sensor.
 *        More info here: https://randomnerdtutorials.com/esp32-ds18b20-temperature-arduino-ide/
 * @version 1.0
 * @date 2020-09-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../ISensor.hpp"
#include "DallasTemperature.h"                          // For temperature calculations
#include "OneWire.h"                                    // Communication protocol for 1-Wire to the DS18B20

class SoilTemperatureSensor: public ISensor
{
public:
    SoilTemperatureSensor();
    String getData();
    String getName();
    String getNameAndData();
private:
    double readTemp();
    String _unit = " °C";
    const String _name = "Soil temperature sensor";
    OneWire* _oneWire;                                  // Pointer for the OneWire protocol object.
    DallasTemperature* _tempSensor;                     // Pointer for the DS18B20 protocol translator.
};

 #endif // __SOILTEMPERATURESENSOR_H__