#ifndef ToIoTwithWIFI_H
#define ToIoTwithWIFI_H

#include "arduino.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


class ToIoTwithWIFI
{
    public:
        ToIoTwithWIFI();
        void setupToIoTwithWIFI(char* nodeI, char* ssid, char* password, char* broker_ip);
        void pub(char* sensorId, int cnt, ...);
        void reconnect();
        PubSubClient client;
    private:
        unsigned long lastMsg = 0;
        char topic[100];
        char msg[40];  
        char* nodeId;
        WiFiClient espClient;
        
};

#endif