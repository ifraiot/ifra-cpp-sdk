
class IfraSDK
{
private:
    char* _channel;
    char* _username;
    char* _password;
    // void callback(char *topic, byte*payload, unsigned int length);

public:
    IfraSDK(char* _channel, char* username, char* password);
    IfraSDK(char* _channel, char* username, char* password, char* server);
    void addMeasurement(char *name, float value);
    void addActuator(char * measurement, void (*callbackFunc)(char * topic, byte * payload, unsigned int length));
    void send();
    void send(char *topic);
};


