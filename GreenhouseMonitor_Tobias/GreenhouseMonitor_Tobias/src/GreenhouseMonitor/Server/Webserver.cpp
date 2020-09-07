#include "Webserver.hpp"

Webserver::Webserver(String servername, String SSID, String password)
{
    this->_serverName = servername;
    this->_ssid = SSID;
    this->_password = password;
    _server = new WebServer(80);
    _html = new HTML();
}

Webserver::~Webserver()
{
    delete this->_html;
    delete this->_server;
}

void Webserver::setHostName(String hostname)
{
    this->_hostname = hostname;
    
}

void Webserver::setServerName(String servername)
{
    this->_serverName = servername;
}


void Webserver::startServer()
{
    WiFi.begin(this->_ssid.c_str(), this->_password.c_str());
    WiFi.setHostname(this->_hostname.c_str());

    while(WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected..!");
    Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
    _server->on("/update",onUpdate);
    _server->onNotFound(onNotFound);
    _server->on("/",onConnect);
    _server->begin();
}

void Webserver::handleClient()
{
    _server->handleClient();
}

void Webserver::onUpdate()
{
    _server->send(200, "text/HTML",_html->sendHTML(_stringToSend));
}

void Webserver::onNotFound()
{
    _server->send(404, "text/plain", "not found");
}

void Webserver::onConnect()
{
    _server->send(200, "text/HTML", _html->sendHTML(_stringToSend));
}

void Webserver::updateString(String stringToUpdate)
{
    _stringToSend.clear();
    _stringToSend += stringToUpdate;
}