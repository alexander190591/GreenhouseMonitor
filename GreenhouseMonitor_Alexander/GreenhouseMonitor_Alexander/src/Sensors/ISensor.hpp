#ifndef __ISENSOR_H__
#define __ISENSOR_H__

/**
 * @file ISensor.hpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Arduino.h"

class ISensor
{
public:
    virtual String getData() = 0;           //returning data as String
    virtual String getName() = 0;           //returning name as String
    virtual String getNameAndData() = 0;    //returning data and name concated on the form "''Name'': ''Data''"
};

#endif // __ISENSOR_H__