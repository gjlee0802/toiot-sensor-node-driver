# Toiot Sensor Node Driver
* This library is used in the sensor node of the ToIoT platform.  
* The measured sensor values are delivered to the sink node through MQTT.
* Publish the value to the mqtt broker in the `data/[node_uuid]` topic in a fixed format using the pub function.

## Getting Started with WIFI
1. Use the Arduino Library Manager to install the `ESP8266WiFi`, `PubSubClient` library.
2. Download `ToIoTwithWIFI` and put it in the Arduino/libraries folder.
3. Fill in the contents of `config.h` and put it in the sketch folder. You can set this application through this file.
4. Write the main source code like [example](https://github.com/SSU-NC/toiot-sensor-node-driver/blob/dev/ToIoTwithWIFI/examples/ToIoTwithWIFI/ToIoTwithWIFI.ino).

```c++
#include "ToIoTwithWIFI.h"
#include "config.h"

double value = 0.0; // your sensor value 
ToIoTwithWIFI t;

void setup() {
    // These parameters are in the config.h file.
    t.setupToIoTwithWIFI(nodeId, ssid, password, mqtt_server, mqtt_port);
}


void loop() {
    /* Read sensor values and call the pub function 
    with the sensor uuid, number of values, and values as arguments */
    t.pub("sensor-uuid-1", 1, value);
    t.pub("sensor-uuid-2", 2, value, value);
    t.pub("sensor-uuid-3", 3, value, value, value);
    delay(4000); 
}
```

## Getting Started with LoRaWAN
![LoRa_with_UNO](https://user-images.githubusercontent.com/49184890/104308980-cce1f780-5514-11eb-8256-a2de8c06e99f.PNG)   

## Getting Started with Bluetooth

