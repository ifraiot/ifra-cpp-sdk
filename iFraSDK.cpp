#include "iFraSDK.h"
 
DynamicJsonDocument _doc(_capacity);
 
 iFraSDK::iFraSDK(){
        
}
 iFraSDK::iFraSDK(HardWarePlatform* hardWarePlatform, char* channel, char* username, char* password)  {

    //Assign to global valuable.
    this->hardWarePlatform_ = hardWarePlatform;
    this->channel_ = channel;
    this->username_ = username;
    this->password_ = password;
    
    //Get client from strategy sdk
    this->client_ = this->hardWarePlatform_->GetClient(); 

    //Set Client to MQTT client 
    this->mqtt_client_.setClient(*this->client_);

    //Setup server and port number.
    this->mqtt_client_.setServer(IFRA_SERVER, MQTT_PORT);

}

iFraSDK::iFraSDK(HardWarePlatform* hardWarePlatform  ,char* channel, char* username, char* password, char* server){
    this->channel_ = channel;
    this->username_ = username;
    this->password_ = password;
    this->hardWarePlatform_ = hardWarePlatform;
    this->server_ = server;
}

void iFraSDK::addSensor(char * sensor_name, char * unit, float value){
       JsonObject doc = _doc.createNestedObject();
        if (_base_time != 0 && _recordCount == 0) {
                doc["bt"] = _base_time;
        }

        if (_base_name == "") {
                doc["n"] = sensor_name;
        } else if (_recordCount == 0) {
                doc["bn"] = sensor_name;
        }

        if (_base_unit == "") {
                doc["u"] = unit;
        } else if (_recordCount == 0) {
                doc["bu"] = unit;
        }

        doc["v"] = value;
        _recordCount++;
}

void iFraSDK::addActuator(char * actuator_name, void (*callbackFunc)(char * topic, byte * payload, unsigned int length)){

}

void iFraSDK::send() {
        // char * toptic = "organization/9/messages"
        // if (_mqtt_client.connected()) {
        //         char message[4096];
        //         serializeJson(_doc, message);
        //         _mqtt_client.publish(toptic, message);
        //         _mqtt_client.loop();
        //         //Serial.println(message);
        // }

        // _doc.clear();
        // _recordCount = 0;
}

void iFraSDK::ConnectNetwork(){
      this->hardWarePlatform_->Connect();

      while (!this->mqtt_client_.connected()) {
                Serial.print("Connecting IFRA MQTT...");

                if (this->mqtt_client_.connect(this->username_, this->username_, this->password_)) {
                        Serial.println("connected ^_^");
                        // String topic = "OTA/";
                        // String client_id(_username);
                        // String full_topic = topic + client_id;
                        // this->mqtt_client_.subscribe(full_topic.c_str());

                } else {
                        Serial.print("failed, rc=");
                        Serial.print(this->mqtt_client_.state());
                        Serial.println(" try again in 5 seconds");
                        // Wait 5 seconds before retrying
                        delay(5000);

       }

      }
}

 




