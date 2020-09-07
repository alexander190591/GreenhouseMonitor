#ifndef __DUMMYSENSOR_H__
#define __DUMMYSENSOR_H__

/**
 * @file DummySensor.hpp
 * @author Alexander Najbjerg Christensen (alexander190591@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../ISensor.hpp"

class DummySensor : public ISensor
{
    String getData() {return "50%";};
    String getName() {return "DummySensor";};
    String getNameAndData()
    {
        String nameAndData = "";
        nameAndData += getName();
        nameAndData += ": ";
        nameAndData += getData();
        return nameAndData;
    };
};

#endif // __DUMMYSENSOR_H__