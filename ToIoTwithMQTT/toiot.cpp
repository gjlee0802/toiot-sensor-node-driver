#include "toiot.h"

#include <cstring>
#include "arduino.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

toiot::toiot()
{
    PubSubClient* client2 = new PubSubClient (espClient);
    client = *client2;
}

void toiot::setupToiot(char* nodeI, char* ssid, char* password, char* broker_ip)
{
    Serial.begin(115200);
    
    delay(500);
   
    Serial.println("");
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros());

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
 
    nodeId = nodeI;

    client.setServer(broker_ip, 1883);
}

void toiot::reconnect()
{
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP8266Client")) {
            Serial.println("connected");
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void toiot::pub(char* sensorId, int value)
{
    if(!client.connected())
    {
        reconnect();
    }
    snprintf (msg, 30, "%ld", value);
    snprintf(topic, 100, "data/%s/%s", nodeId, sensorId);
    Serial.print(topic);
    Serial.print(":");
    Serial.println(msg);
    client.publish(topic,  msg);

}

void toiot::pub(char* sensorId, int value1, int value2)
{
    if(!client.connected())
    {
        reconnect();
    }
   
    snprintf (msg, 30, "%ld, %ld", value1, value2);
    snprintf(topic, 100, "data/%s/%s", nodeId, sensorId);
    Serial.print(topic);
    Serial.print(":");
    Serial.println(msg);
    client.publish(topic,  msg);

}

void toiot::pub(char* sensorId, int value1, int value2, int value3)
{
    if(!client.connected())
    {
        reconnect();
    }
    
    snprintf (msg, 30, "%ld, %ld, %ld", value1, value2, value3);
    snprintf(topic, 100, "data/%s/%s", nodeId, sensorId);
    Serial.print(topic);
    Serial.print(":");
    Serial.println(msg);
    client.publish(topic,  msg);

}