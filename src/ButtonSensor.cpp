#include "ButtonSensor.h"

ButtonSensor::ButtonSensor(uint8_t id, SensorType type, SensorTriggerType triggerType, uint8_t sensorPin, uint8_t sensorPinMode)
  : TriggerSensor(id, type, triggerType), _button(sensorPin, sensorPinMode) {
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
