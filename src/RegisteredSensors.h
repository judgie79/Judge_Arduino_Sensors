#ifndef __RegisteredSensors_h
#define __RegisteredSensors_h

#include "Arduino.h"

#include "MotorSensor.h"

struct RegisteredSensors
{
    MotorSensor **sensors;
    uint16_t sensorCount;
};


#endif