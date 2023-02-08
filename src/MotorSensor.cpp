
#include "MotorSensor.h"

MotorSensor::MotorSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection) {
  this->id = id;
  this->name = name;
  this->type = type;
  this->triggerType = triggerType;
  this->triggerDirection = triggerDirection;

  // LOGD_DEBUG("MotorSensor created " + String(id) + " - " + name + " - " + String((uint8_t)type) + " - " + String((uint8_t)triggerType) + " - " + String((uint8_t)triggerDirection));
}

MotorSensor::~MotorSensor()
{
  LOGD_DEBUG("MotorSensor destroyed " + String(name));
}

bool MotorSensor::haltOnTrigger()
{
  ASSERTM(this != nullptr, "this is nullptr");
  return this->triggerType == SensorTriggerType::ForceStop;
}

uint16_t MotorSensor::getId() {
  return id;
}

String MotorSensor::getName() {
  return name;
}

String MotorSensor::toString()
{
	return String(id) + " - " + name;// +" - " + String(SensorTypeNames[(int)getType()]) + " - " + String(SensorTriggerTypeNames[(int)getTriggerType()]) + " - " + String(SensorTriggerDirectionNames[(int)getTriggerDirection()]) + " - " + String(TriggerdNames[isTriggered()]);
}

SensorType MotorSensor::getType() {
  return type;
}

SensorTriggerType MotorSensor::getTriggerType() {
  return triggerType;
}

SensorTriggerDirection MotorSensor::getTriggerDirection() {
  return triggerDirection;
}
