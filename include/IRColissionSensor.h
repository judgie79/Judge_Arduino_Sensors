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
  unsigned long lastCollisionDuration();
  void SetCollisionDuration(unsigned long t);
private:
  uint8_t _pin;
  byte _reading = HIGH;              // the current reading from the input pin
  byte _lastReading = HIGH;          // the previous reading from the input pin

  unsigned long colissionTimer = 0;
  unsigned long colissionDuration = 0;
};

#endif