#include "ButtonSensor.h"

ButtonSensor::ButtonSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, uint8_t sensorPin, uint8_t sensorPinMode)
  : MotorSensor(id, name, type, triggerType, triggerDirection), _button(sensorPin, sensorPinMode) {
}

void ButtonSensor::read() {
  _button.read();
}

bool ButtonSensor::isTriggered() {
  return _button.pressDownStarted();
}

bool ButtonSensor::isStillTriggered() {
  return _button.isPressed();
}

bool ButtonSensor::wasTriggered() {
  return _button.wasReleased();
}
