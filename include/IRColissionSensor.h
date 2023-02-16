#ifndef IRColissionSensor_h
#define IRColissionSensor_h

#include "Arduino.h"
#include "TriggerSensor.h"

class IRColissionSensor : public TriggerSensor {
public:
  IRColissionSensor(uint8_t id, SensorType type, SensorTriggerType triggerType, uint8_t sensorPin);
  void read();
  bool isTriggered();
  bool isStillTriggered();
  bool wasTriggered();
  long lastCollisionDuration();
private:
  uint8_t _pin;
  byte _reading = LOW;              // the current reading from the input pin
  byte _lastReading = LOW;          // the previous reading from the input pin

  long colissionTimer = 0;
  long colissionDuration = 0;
};

#endif