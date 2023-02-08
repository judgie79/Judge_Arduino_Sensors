#include "DistanceDevice.h"

DistanceDevice::DistanceDevice(uint16_t maxLength){
    this->maxLength = maxLength;
}

uint16_t DistanceDevice::getDistance()
{
    return distance;
}
uint16_t DistanceDevice::getLastDistance()
{
    return lastDistance;
}

void DistanceDevice::reset()
{
  justRead = false;
}
