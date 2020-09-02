#include <toiot.h>

char* ssid = "wifi-id";
char* password = "wifi-passwd";
char* mqtt_server = "mqtt-broker-ip";
char* nodeId = "node-id";
int value = 0; 
toiot t;

void setup() {
  t.setupToiot(nodeId, ssid, password, mqtt_server);
}


void loop() {
  t.pub("sensor-id-1", value);
  t.pub("sensor-id-2", value, value+1);
  t.pub("sensor-id-3", value, value+1, value+2);
  delay(4000);
  value++; // sensor value
  
}
