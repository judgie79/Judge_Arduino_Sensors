#ifndef DistanceDevice_h
#define DistanceDevice_h

#include "Arduino.h"


class DistanceDevice
{
private:
protected:
    uint16_t lastDistance = 0;
    uint16_t distance = 0;
    uint16_t maxLength = 100;
    bool justRead = false;
public:
    DistanceDevice(uint16_t maxLength);
    virtual void begin() = 0;
    virtual void read() = 0;
    virtual void reset();
    uint16_t getDistance();
    uint16_t getLastDistance();
};

#endif