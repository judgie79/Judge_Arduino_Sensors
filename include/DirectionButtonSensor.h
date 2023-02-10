#ifndef DirectionButtonSensor_h
#define DirectionButtonSensor_h

#include "Arduino.h"
#include "DirectionTriggerSensor.h"
#include <DebouncedButton.h>
#include <ButtonSensor.h>

class   DirectionButtonSensor : public DirectionTriggerSensor, public ButtonSensor {
public:
  DirectionButtonSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, uint8_t sensorPin, uint8_t sensorPinMode);
  void read();
  bool isTriggered();
  bool isStillTriggered();
  bool wasTriggered();
};

#endif