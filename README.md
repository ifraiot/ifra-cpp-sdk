# IfraSDK

Example code for ESP32 Device.
This code will use to control the door to ON/OFF.
```cpp

#include "iFraSDK.h"
#include "iFraESP32SDK.h"

#define  DEVICE_KEY    "6981085e-34f2-4660-ba54-95a982b5ca46"
#define  DEVICE_SECRET "d48bc8ad-9717-40d6-9a80-9a001a317ca5"
#define  SERVER        "192.168.1.20"
#define  CHANNEL       "1"

#define WIFI_SSID      "ifrasoft"
#define WIFI_PASSWORD  "@ifrasoft2020"
#define DOOR_001       "Door001"
#define LED_PIN         2

iFraESP32SDK esp32(WIFI_SSID, WIFI_PASSWORD);
iFraSDK ifra(&esp32, CHANNEL, DEVICE_KEY, DEVICE_SECRET, SERVER);


void handleCallback(char * actuator_name, int * value , char * topic, byte * payload, unsigned int length) {

  if (strcmp(actuator_name, DOOR_001) == 0) {
    if (*value == ON) {
      digitalWrite(LED_PIN, HIGH);
      ifra.addSensor(DOOR_001, "switch", HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
      ifra.addSensor(DOOR_001, "switch", LOW);
    }
    ifra.send();
  }

}


void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  ifra.ConnectNetwork(); //Start connect network by wifi.
  ifra.addActuator(handleCallback);

}

void loop() {

  if (!ifra.connected()) {
    ifra.reconnect();
  }

}

```