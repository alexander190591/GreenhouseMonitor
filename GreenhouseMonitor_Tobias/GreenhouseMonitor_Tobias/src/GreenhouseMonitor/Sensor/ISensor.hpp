#include "WString.h"

class ISensor
{
    public:
    virtual String getData() = 0; //returning data as String
    virtual String getName() = 0; //returning name as String
    virtual String getDataAndName() = 0; //returning data and name concated on the form "''Name'': ''Data''"
};