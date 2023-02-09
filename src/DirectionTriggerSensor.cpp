#include "DirectionTriggerSensor.h"

DirectionTriggerSensor::DirectionTriggerSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection)
: TriggerSensor(id, name, type, triggerType)
{
    this->triggerDirection = triggerDirection;
}

DirectionTriggerSensor::~DirectionTriggerSensor()
{
}

SensorTriggerDirection DirectionTriggerSensor::getTriggerDirection() {
  return triggerDirection;
}
