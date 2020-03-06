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
        //Get client from strategy sdk
    this->client_ = this->hardWarePlatform_->GetClient(); 

    //Set Client to MQTT client 
    this->mqtt_client_.setClient(*this->client_);

    //Setup server and port number.
    this->mqtt_client_.setServer(this->server_, MQTT_PORT);
}

void iFraSDK::addSensor(char * sensor_name, char * unit, float value){
       JsonObject doc = _doc.createNestedObject();
       doc["n"] = sensor_name;
       doc["u"] = unit;
       doc["v"] = value;
      _recordCount++;
}

void iFraSDK::addActuator(char * actuator_name, void (*callbackFunc)(char * topic, byte * payload, unsigned int length)){

}

void iFraSDK::send() {
      if (this->mqtt_client_.connected()) {
                String channel(this->channel_);
                String topic = "organization/"+channel+"/messages";
                
                char message[4096];
                serializeJson(_doc, message);
                this->mqtt_client_.publish(topic.c_str(), message);
                this->mqtt_client_.loop();
                Serial.println(message);
        }

        _doc.clear();
        _recordCount = 0;
}

void iFraSDK::ConnectNetwork(){
      this->hardWarePlatform_->Connect();

      while (!this->mqtt_client_.connected()) {
                Serial.print("Start connect IFRA MQTT...");

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

 




