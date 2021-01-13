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


According to the LoRa Alliance document, **the unlicensed ISM band for Lora's use in Korea is specified as 920-923.**   
The 433 MHz band used by the SX1278 LoRa chip is a limited frequency band in Korea.   
The 433 MHz band frequency is the band assigned to the **HAM**.   
To use LoRa **in Korea, LBT(Listen Before Talk)** should be used in Korea.   
But in this project, we used 433 MHz for test.   
- For Arduino:    
Connect SX1278 with arduino as shown as below.   
![Transmitting-Side-Connecting-LoRa-SX1278-with-Arduino-UNO](https://user-images.githubusercontent.com/49184890/104311794-12a0bf00-5519-11eb-8039-b8d42397c83b.png)
![LoRa_with_UNO](https://user-images.githubusercontent.com/49184890/104308980-cce1f780-5514-11eb-8256-a2de8c06e99f.PNG)   
- For NodeMCU SENDER:    
Connect SX1278 with NodeMCU as shown as below.   
![LoRa_with_NodeMCU](https://user-images.githubusercontent.com/49184890/104408324-2561d500-55a7-11eb-88b7-c84003821d7b.PNG)   

## Getting Started with Bluetooth

