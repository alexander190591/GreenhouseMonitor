

class IServer
{
    
    public:
    virtual void startServer() = 0;
    virtual void setServerName(char * name) = 0;
    virtual void setServerCallbackMethod() = 0;
};