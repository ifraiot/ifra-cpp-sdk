#include "iFraESP8266SDK.h"

iFraESP8266SDK::iFraESP8266SDK(char* ssid, char* password){
    this->ssid_=ssid;
    this->password_=password;
}

void iFraESP8266SDK::Connect() {
      WiFi.begin(this->ssid_, this->password_);
      Serial.print("Start connect wifi");
      while (WiFi.status() != WL_CONNECTED) 
         {
            delay(500);
            Serial.print(".");
         }
      WiFi.setAutoReconnect(true);
      Serial.println("WiFi connected");  
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
}