
#include "TriggerSensor.h"

TriggerSensor::TriggerSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType) {
  this->id = id;
  this->name = name;
  this->type = type;
  this->triggerType = triggerType;
}

TriggerSensor::~TriggerSensor()
{
  LOGD_DEBUG("TriggerSensor destroyed " + String(name));
}

uint16_t TriggerSensor::getId() {
  return id;
}

String TriggerSensor::getName() {
  return name;
}

String TriggerSensor::toString()
{
	return String(id) + " - " + name;// +" - " + String(SensorTypeNames[(int)getType()]) + " - " + String(SensorTriggerTypeNames[(int)getTriggerType()]) + " - " + String(SensorTriggerDirectionNames[(int)getTriggerDirection()]) + " - " + String(TriggerdNames[isTriggered()]);
}

SensorType TriggerSensor::getType() {
  return type;
}

SensorTriggerType TriggerSensor::getTriggerType() {
  return triggerType;
}
