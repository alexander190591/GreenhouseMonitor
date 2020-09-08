#ifndef __DEFINES_H__
#define __DEFINES_H__

/**
 * @file defines.hpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief File containing all pinout defines.
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/****************************************************
 *                  PINS IN USE                     *
 * **************************************************/

//______Define___________________Pin________Possible functionalites_____________Used for____________________________
#define SOIL_MOISTURE_1_PIN     34         // Input only. RTC_GPIO4_ADC CH6    Soil Moisture Sensor 1
#define LED_PIN                 2          // RTC_GPIO12. TOUCH2. ADC2 CH2.    Built in LED pin
#define SOIL_TEMPERATURE_1_PIN  4          // RTC_GPIO10. TOUCH0. ADC2 CH0.    1-Wire communication

/****************************************************
 *         All unused pins defined below.           *
 * REMEMBER TO REMOVE THE ONE YOU ARE ABOUT TO USE! *
 * **************************************************/

// A N A L O G   P I N S
//______Define___________________Pin________Possible functionalites_____________________________Used for____________
// #define ANALOG_PIN_FUNCTIONALITY 36         // Input only. RTC_GPIO0. Sensor VP. ADC1 CH0.      Functionality
// #define ANALOG_PIN_FUNCTIONALITY 39         // Input only. RTC_GPIO3. Sensor VN. ADC1 CH3.      Functionality
// #define ANALOG_PIN_FUNCTIONALITY 35         // Input only. RTC_GPIO5. ADC1 CH7.                 Functionality
// #define ANALOG_PIN_FUNCTIONALITY 32         // RTC_GPIO9. TOUCH9. ADC CH4.                      Functionality
// #define ANALOG_PIN_FUNCTIONALITY 33         // RTC_GPIO8. TOUCH8. ADC1 CH5.                     Functionality
// #define ANALOG_PIN_FUNCTIONALITY 25         // RTC_GPIO6. DAC1. ADC2 CH8.                       Functionality
// #define ANALOG_PIN_FUNCTIONALITY 26         // RTC_GPIO7. DAC2. ADC2 CH9.                       Functionality
// #define ANALOG_PIN_FUNCTIONALITY 27         // RTC_GPIO17. TOUCH7. ADC2 CH7.                    Functionality
// #define ANALOG_PIN_FUNCTIONALITY 14         // RTC_GPIO16. HSPI CLK. TOUCH6. ADC2 CH6.          Functionality
// #define ANALOG_PIN_FUNCTIONALITY 12         // RTC_GPIO15. HSPI MISO. TOUCH5. ADC2 CH5.         Functionality
// #define ANALOG_PIN_FUNCTIONALITY 13         // RTC_GPIO14. HSPI MOSI. TOUCH4. ADC2 CH4.         Functionality
// #define ANALOG_PIN_FUNCTIONALITY 15         // RTC_GPIO13. TOUCH3. HSPI CSO. ADC2 CH3.          Functionality
// #define ANALOG_PIN_FUNCTIONALITY 0          // RTC_GPIO11. TOUCH1. ADC2 CH1.                    Functionality

// O T H E R   P I N S

//______Define___________________Pin________Possible functionalites_____________________________Used for____________
// #define PIN_FUNCTIONALITY        9          // SHD/SD2.                                         Functionality
// #define PIN_FUNCTIONALITY        10         // SWP/SD3.                                         Functionality
// #define PIN_FUNCTIONALITY        11         // CSC/CMD.                                         Functionality
// #define PIN_FUNCTIONALITY        23         // VSPI MOSI.                                       Functionality
// #define PIN_FUNCTIONALITY        22         // I2C SCL.                                         Functionality
// #define PIN_FUNCTIONALITY        1          // UART 0 TX.                                       Functionality
// #define PIN_FUNCTIONALITY        3          // UART 0 RX.                                       Functionality
// #define PIN_FUNCTIONALITY        21         // I2C SDA.                                         Functionality
// #define PIN_FUNCTIONALITY        19         // VSPI MISO.                                       Functionality
// #define PIN_FUNCTIONALITY        18         // VSPI CLK.                                        Functionality
// #define PIN_FUNCTIONALITY        5          // VSPI CSO.                                        Functionality
// #define PIN_FUNCTIONALITY        17         // UART 2 TX.                                       Functionality
// #define PIN_FUNCTIONALITY        16         // UART 2 RX.                                       Functionality
// #define PIN_FUNCTIONALITY        8          // SDI/SD1.                                         Functionality
// #define PIN_FUNCTIONALITY        7          // SDO/SD0.                                         Functionality
// #define PIN_FUNCTIONALITY        6          // SCK/CLK.                                         Functionality

#endif // __DEFINES_H__