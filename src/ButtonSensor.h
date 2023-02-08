#ifndef ButtonSensor_h
#define ButtonSensor_h

#include "Arduino.h"
#include "MotorSensor.h"
#include <DebouncedButton.h>

class ButtonSensor : public MotorSensor {
public:
  ButtonSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, uint8_t sensorPin, uint8_t sensorPinMode);
  void read();
  bool isTriggered();
  bool isStillTriggered();
  bool wasTriggered();
private:
  DebouncedButton _button;
};

#endif