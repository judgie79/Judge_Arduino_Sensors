
#include "TriggerSensor.h"

TriggerSensor::TriggerSensor(uint8_t id, SensorType type, SensorTriggerType triggerType) {
  this->id = id;
  this->type = type;
  this->triggerType = triggerType;
}

TriggerSensor::~TriggerSensor()
{
  LOGD_DEBUG("TriggerSensor destroyed");
}

uint8_t TriggerSensor::getId() {
  return id;
}

String TriggerSensor::toString()
{
	return String(id);
}

SensorType TriggerSensor::getType() {
  return type;
}

SensorTriggerType TriggerSensor::getTriggerType() {
  return triggerType;
}
