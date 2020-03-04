 
#ifndef HARDWAREPLATFORM_H
#define HARDWAREPLATFORM_H

#include "HardWarePlatform.h"

#endif // HARDWAREPLATFORM_H
#include <PubSubClient.h>

class iFraESP8266SDK : public HardWarePlatform
{
   public:
        void Connect() override;
};


 