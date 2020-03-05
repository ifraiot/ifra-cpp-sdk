#ifndef HARDWAREPLATFORM_H
#define HARDWAREPLATFORM_H

#include "HardWarePlatform.h"

#endif // HARDWAREPLATFORM_H
#include <ArduinoJson.h>
#include "Client.h"
#include "Stream.h"
#include <WiFi.h>
#include <PubSubClient.h>

#ifndef IFRA_SERVER
#define IFRA_SERVER "hub.ifra.io"
#endif

#ifndef NTP_SERVER
#define NTP_SERVER "asia.pool.ntp.org"
#endif

#ifndef MQTT_PORT
#define MQTT_PORT 1883
#endif


const size_t _capacity = JSON_ARRAY_SIZE(500) + JSON_OBJECT_SIZE(10);

class iFraSDK
{
private:
    HardWarePlatform* hardWarePlatform_;
    char* channel_;
    char* username_;
    char* password_;
    char* server_;
    char* _base_name;
    char* _base_unit;
    int _recordCount;
    unsigned long int _base_time;
    Client *client_;
    PubSubClient mqtt_client_;
    // void callback(char *topic, byte*payload, unsigned int length);

public:
    iFraSDK();
    iFraSDK(HardWarePlatform* hardWarePlatform, char* channel, char* username, char* password);
    iFraSDK(HardWarePlatform* hardWarePlatform  ,char* channel, char* username, char* password, char* server) ;
    void addSensor(char * sensor_name, char * unit, float value);
    void addActuator(char * actuator_name, void (*callbackFunc)(char * topic, byte * payload, unsigned int length));
    void send();
    void ConnectNetwork();
};

