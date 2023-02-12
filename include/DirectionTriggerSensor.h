#ifndef DirectionTriggerSensor_H
#define DirectionTriggerSensor_H

#include "Arduino.h"
#include "TriggerSensor.h"

class DirectionTriggerSensor : public TriggerSensor
{
private:
  /* data */
public:
  DirectionTriggerSensor(uint8_t id, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection sensorTriggerDirection);
  ~DirectionTriggerSensor();
  SensorTriggerDirection getTriggerDirection();
protected:
  SensorTriggerDirection triggerDirection;
};

#endif
