# IfraSDK

Example code for ESP32 Device.
This code will use to control the door to ON/OFF.
```cpp

#include "iFraSDK.h"
#include "iFraESP32SDK.h"

#define WIFI_SSID      "<ชื่อ WIFI>"
#define WIFI_PASSWORD  "<รหัสผ่าน WIFI>"

#define  USERNAME    "218c2b41-970b-4354-946b-1f6138c218ad"
#define  PASSWORD    "91fd563b-c384-41ea-8101-83699b79ea2b"
#define  CHANNEL       "17f2b49e-a2c7-47d0-9421-a51627f21d14"

iFraESP32SDK esp32(WIFI_SSID, WIFI_PASSWORD);
iFraSDK client(&esp32, CHANNEL, USERNAME, CHANNEL);

void setup() {
  Serial.begin(115200);  
  client.wifiConnection();
}

void loop() {
  client.addSensor("temp","c",random(1,100));
  client.send();
  delay(2000);
}

```