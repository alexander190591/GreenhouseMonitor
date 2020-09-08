/**
 * @file SoilTemperatureSensor.cpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "SoilTemperatureSensor.hpp"
#include "../../../lib/defines.hpp"                         // For custom pin defenitions on the ESP32



SoilTemperatureSensor::SoilTemperatureSensor() 
{
    // Setup
    _oneWire = new OneWire(SOIL_TEMPERATURE_1_PIN);          // Setup a oneWire instance to communicate with any OneWire device.
    _tempSensor = new DallasTemperature(&(*_oneWire));           // Pass the oneWire reference to Dallas Temperature.

    _tempSensor->begin();                                    // Start up the Dallas Temperature library.

    // discoverOneWireDevices();                            // For debugging purposes.
}

String SoilTemperatureSensor::getData() 
{
    String data = readTemp() + _unit;
    return data; // More sensors can be put on same wire. We only have one.
}

String SoilTemperatureSensor::getName() 
{
    return _name;
}

String SoilTemperatureSensor::getNameAndData() 
{
    String nameAndData = "";
    nameAndData += getName();
    nameAndData += ": ";
    nameAndData += getData();
    return nameAndData;
}

double SoilTemperatureSensor::readTemp() 
{
    _tempSensor->requestTemperatures();

    // Serial.print("Temperature read: ");                         // For debugging purposes.
    // Serial.println(_tempSensor->getTempCByIndex(0));            // For debugging purposes.

    return _tempSensor->getTempCByIndex(0);
}

/**
 * @brief discovers connected soil temperature sensors without the DallasTemperature library.
 * 
 */
// void SoilTemperatureSensor::discoverOneWireDevices() 
// {
//     byte i;
//     byte present = 0;
//     byte data[12];
//     byte addr[8];
    
//     Serial.print("Looking for 1-Wire devices...\n\r");

//     while(_oneWire->search(addr)) {
//         Serial.print("\n\rFound \'1-Wire\' device with address:\n\r");

//         for( i = 0; i < 8; i++) {
//             Serial.print("0x");
//             if (addr[i] < 16) {
//                 Serial.print('0');
//             }

//             Serial.print(addr[i], HEX);

//             if (i < 7) {
//                 Serial.print(", ");
//             }
//         }

//         if ( OneWire::crc8( addr, 7) != addr[7]) 
//         {
//             Serial.print("CRC is not valid!\n");
//             return;
//         }
//     }
//     Serial.print("\n\r\n\rThat's it.\r\n");
//     _oneWire->reset_search();
//     return;
// }