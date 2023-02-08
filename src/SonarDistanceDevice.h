#ifndef SonarDistanceDevice_h
#define SonarDistanceDevice_h

#include "Arduino.h"
#include "DistanceDevice.h"
#include "NewPing.h"

class SonarDistanceDevice: public DistanceDevice
{
private:
    uint8_t trigPin;
    uint8_t echoPin;
    NewPing sonar;
public:
    SonarDistanceDevice(uint8_t trigPin, uint8_t echoPin, uint8_t maxLength);
    void begin();
    void read(bool init);
    void read();
};

#endif