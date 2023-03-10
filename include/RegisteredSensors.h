#ifndef __RegisteredSensors_h
#define __RegisteredSensors_h

#include "Arduino.h"

#include "TriggerSensor.h"


template <class T>
struct RegisteredSensors
{
    T **sensors;
    uint8_t sensorCount;
};


#endif