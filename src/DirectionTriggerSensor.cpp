#include "DirectionTriggerSensor.h"

DirectionTriggerSensor::DirectionTriggerSensor(uint8_t id, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection)
: TriggerSensor(id, type, triggerType)
{
    this->triggerDirection = triggerDirection;
}

DirectionTriggerSensor::~DirectionTriggerSensor()
{
}

SensorTriggerDirection DirectionTriggerSensor::getTriggerDirection() {
  return triggerDirection;
}
