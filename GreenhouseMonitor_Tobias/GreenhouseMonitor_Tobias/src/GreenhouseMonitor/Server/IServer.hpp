#include <WString.h>

class IServer
{
    
    public:
    virtual void startServer() = 0;
    virtual void setServerName(String servername) = 0;
    virtual void setHostName(String hostname) = 0;
    virtual void updateString(String stringToUpdate) = 0;

};