#ifndef ButtonSensor_h
#define ButtonSensor_h

#include "Arduino.h"
#include "TriggerSensor.h"
#include <DebouncedButton.h>

class ButtonSensor : public TriggerSensor {
public:
  ButtonSensor(uint8_t id, SensorType type, SensorTriggerType triggerType, uint8_t sensorPin, uint8_t sensorPinMode);
  void read();
  bool isTriggered();
  bool isStillTriggered();
  bool wasTriggered();
private:
  DebouncedButton _button;
};

#endif