#ifndef toiot_H
#define toiot_H

#include "arduino.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


class toiot
{
    public:
        toiot();
        void setupToiot(char* nodeI, char* ssid, char* password, char* broker_ip);
        void pub(char* sensorId, int value);
        void pub(char* sensorId, int value1, int value2);
        void pub(char* sensorId, int value1, int value2, int value3);
        void reconnect();
        PubSubClient client;
    private:
        unsigned long lastMsg = 0;
        char topic[100];
        char msg[30];  
        char* nodeId;
        WiFiClient espClient;
        
};

#endif