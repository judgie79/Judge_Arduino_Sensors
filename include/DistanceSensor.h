#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "Arduino.h"
#include <DebugOut.h>

#include "TriggerSensor.h"
#include "DistanceDevice.h"

class DistanceSensor : public TriggerSensor {
public:
  DistanceSensor(uint8_t id, uint8_t triggerDistance, SensorTriggerType triggerType, DistanceDevice *device);
  ~DistanceSensor();
  void begin();
  void read();
  void setTriggerDistance(uint8_t distance);
  uint8_t getTriggerDistance();
  uint8_t getDistance();
  uint8_t getLastDistance();
  bool isTriggered();
  bool isStillTriggered();
  bool wasTriggered();
  String toString();
private:
  uint8_t triggerDistance;
  DistanceDevice *device;
};

#endif