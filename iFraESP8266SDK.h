 
#ifndef HARDWAREPLATFORM_H
#define HARDWAREPLATFORM_H

#include "HardWarePlatform.h"

#endif // HARDWAREPLATFORM_H
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

class iFraESP8266SDK : public HardWarePlatform
{
   public:
        char* ssid_;
        char* password_;
        WiFiClient client_;
        iFraESP8266SDK(char* ssid, char* password);
        void Connect() override;
        Client* GetClient() override;
};


 