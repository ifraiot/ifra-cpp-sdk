#include "ifra-cpp-sdk.h"

IfraSDK::IfraSDK(){
        
}

IfraSDK::IfraSDK(char* _channel, char* username, char* password){

}

IfraSDK::IfraSDK(char* _channel, char* username, char* password, char* server){
    
}

void IfraSDK::addMeasurement(char *name, float value){
    
}

void IfraSDK::addActuator(char * measurement, void (*callbackFunc)(char * topic, byte * payload, unsigned int length)){

}

void IfraSDK::send(){

}

void IfraSDK::send(char *topic){

}