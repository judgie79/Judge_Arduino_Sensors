#include "DistanceDevice.h"

DistanceDevice::DistanceDevice(uint8_t maxLength){
    this->maxLength = maxLength;
}

uint8_t DistanceDevice::getDistance()
{
    return distance;
}
uint8_t DistanceDevice::getLastDistance()
{
    return lastDistance;
}

void DistanceDevice::reset()
{
  justRead = false;
}
