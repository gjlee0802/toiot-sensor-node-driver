# ToIoT-sensor-driver
* This library is used in the sensor node of the ToIoT platform.  
* The measured sensor values are delivered to the sink node through MQTT.
* Publish the value to the mqtt broker in the `data/[node_uuid]` topic in a fixed format using the pub function.

## Getting Started
1. Use the Arduino Library Manager to install the `ESP8266WiFi,` `PubSubClient` library.
  
2. Download `ToIoTwithWIFI` and put it in the Arduino/libraries folder.

3. Download the `config.h` file, fill in the contents, and put it in the sketch folder.

4. Write the code like examples/ToIoTwithWIFI.

```c++
#include "ToIoTwithWIFI.h"
#include "config.h"

double value = 0.0; // your sensor value 
ToIoTwithWIFI t;

void setup() {
    t.setupToIoTwithWIFI(nodeId, ssid, password, mqtt_server);
    // These parameters are in the config.h file.
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