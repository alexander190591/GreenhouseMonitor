#ifndef __SOILMOISTURESENSOR_H__
#define __SOILMOISTURESENSOR_H__

/**
 * @file SoilMoistureSensor.hpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../ISensor.hpp"

class SoilMoistureSensor : public ISensor
{
public:
    SoilMoistureSensor();
    String getData();
    String getName();
    String getNameAndData();
private:
    double readData();
    double convertToRH(double data);
    double moistureData = 0.0;
    String unit = " %";
    const String name = "Soil moisture sensor";
    int wetValue = 1558;                    // Set manually in wet water (go figure...). DO NOT TOUCH!
    int dryValue = 3559;                    // Set manually in dry air. DO NOT TOUCH!
};

#endif // __SOILMOISTURESENSOR_H__