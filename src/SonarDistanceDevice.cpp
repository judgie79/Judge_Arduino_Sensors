#include "SonarDistanceDevice.h"

SonarDistanceDevice::SonarDistanceDevice(uint8_t trigPin, uint8_t echoPin, uint8_t maxLength):
    DistanceDevice(maxLength),
    sonar(trigPin, echoPin, maxLength)
{

}

void SonarDistanceDevice::begin()
{
  
    distance = 0;
    // init with 5 pings
    uint8_t counter = 0;
    while (counter < 5)
    {
        lastDistance = distance;

        distance = sonar.ping() / US_ROUNDTRIP_CM;
        while (distance == NO_ECHO)
        {
            distance = sonar.ping() / US_ROUNDTRIP_CM;
        }
        counter++;
    }
}

void SonarDistanceDevice::read()
{
    if (!justRead) {
        lastDistance = distance;
        
        uint16_t newDistance = sonar.ping_median(5) / US_ROUNDTRIP_CM;

        while (newDistance == NO_ECHO)
        {
            newDistance = sonar.ping() / US_ROUNDTRIP_CM;
        }
        distance = newDistance;
        justRead = true;
    } else {
        lastDistance = distance;
    }
}

