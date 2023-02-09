#include "DirectionButtonSensor.h"

DirectionButtonSensor::DirectionButtonSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, uint8_t sensorPin, uint8_t sensorPinMode)
  : DirectionTriggerSensor(id, name, type, triggerType, triggerDirection), ButtonSensor(id, name, type, triggerType, sensorPin, sensorPinMode) {
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
