#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "Arduino.h"
#include <DebugOut.h>

#include "MotorSensor.h"
#include "DistanceDevice.h"

class DistanceSensor : public MotorSensor {
public:
  DistanceSensor(uint16_t id, String name, uint16_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, DistanceDevice *device);
  ~DistanceSensor();
  void begin();
  void read();
  void setTriggerDistance(uint8_t distance);
  uint16_t getTriggerDistance();
  uint16_t getDistance();
  uint16_t getLastDistance();
  bool isTriggered();
  bool isStillTriggered();
  bool wasTriggered();
  String toString();
private:
  uint16_t triggerDistance;
  DistanceDevice *device;
};

#endif