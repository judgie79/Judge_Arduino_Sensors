#ifndef DirectionTriggerSensor_H
#define DirectionTriggerSensor_H

#include "Arduino.h"
#include "TriggerSensor.h"

class DirectionTriggerSensor : public TriggerSensor
{
private:
  /* data */
public:
  DirectionTriggerSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection sensorTriggerDirection);
  ~DirectionTriggerSensor();
  SensorTriggerDirection getTriggerDirection();
protected:
  SensorTriggerDirection triggerDirection;
};

#endif
