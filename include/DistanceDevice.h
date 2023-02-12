#ifndef DistanceDevice_h
#define DistanceDevice_h

#include "Arduino.h"


class DistanceDevice
{
private:
protected:
    uint8_t lastDistance = 0;
    uint8_t distance = 0;
    uint8_t maxLength = 100;
    bool justRead = false;
public:
    DistanceDevice(uint8_t maxLength);
    virtual void begin() = 0;
    virtual void read() = 0;
    virtual void reset();
    uint8_t getDistance();
    uint8_t getLastDistance();
};

#endif