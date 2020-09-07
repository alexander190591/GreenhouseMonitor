#include "IServer.hpp"
#include "HTML.hpp"
#include  <WiFi.h>
#include <WebServer.h>

class Webserver : public IServer
{
    public:

    Webserver(String servername, String SSID, String password);
    ~Webserver();
    void startServer();
    void setServerName(String servername);
    void setHostName(String hostname);
    void updateString(String stringToUpdate);
    void handleClient();
    static void onUpdate();
    static void onConnect();
    static void onNotFound();

    private:
    static String _stringToSend;
    String _serverName = "0";
    String _ssid = "0";
    String _password = "0";
    String _hostname = "0";
    static WebServer *_server;
    static HTML *_html;
    
};