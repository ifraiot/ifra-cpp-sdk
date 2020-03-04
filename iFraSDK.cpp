#include "iFraSDK.h"
 
DynamicJsonDocument _doc(_capacity);
 
// IfraSDK::IfraSDK() {
//   std::cout << __FUNCTION__ << std::endl;
// }

// //-----------------------------------------------------------------------------
// // DTOR
// //-----------------------------------------------------------------------------
// IfraSDK::~IfraSDK() {
//   std::cout << std::endl << __FUNCTION__ << std::endl;
// }
 iFraSDK::iFraSDK(){
        
}
 iFraSDK::iFraSDK(HardWarePlatform* hardWarePlatform, char* channel, char* username, char* password)  {
    this->channel_ = channel;
    this->username_ = username;
    this->password_ = password;
    this->hardWarePlatform_ = hardWarePlatform;
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

void iFraSDK::send(){

}

void iFraSDK::ConnectNetwork(){
  this->hardWarePlatform_->Connect();
}

 




