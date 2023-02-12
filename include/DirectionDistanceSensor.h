#ifndef DIRECTIONDISTANCESENSOR_H
#define DIRECTIONDISTANCESENSOR_H

#include "Arduino.h"
#include <DebugOut.h>

#include "DistanceSensor.h"
#include "DirectionTriggerSensor.h"
#include "DistanceDevice.h"

class DirectionDistanceSensor : public DistanceSensor, public DirectionTriggerSensor {
public:
  DirectionDistanceSensor(uint8_t id, uint8_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, DistanceDevice *device);
  ~DirectionDistanceSensor();
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
};

#endif