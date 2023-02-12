#include "DirectionButtonSensor.h"

DirectionButtonSensor::DirectionButtonSensor(uint8_t id, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, uint8_t sensorPin, uint8_t sensorPinMode)
  : DirectionTriggerSensor(id, type, triggerType, triggerDirection), ButtonSensor(id, type, triggerType, sensorPin, sensorPinMode) {
}

void DirectionButtonSensor::read() {
  ButtonSensor::read();
}

bool DirectionButtonSensor::isTriggered() {
  return ButtonSensor::isTriggered();
}

bool DirectionButtonSensor::isStillTriggered() {
  return ButtonSensor::isStillTriggered();
}

bool DirectionButtonSensor::wasTriggered() {
  return ButtonSensor::wasTriggered();
}
