#ifndef TriggerSensor_H
#define TriggerSensor_H

#include "Arduino.h"

#include <DebugOut.h>

enum class SensorType : uint8_t {
  Trigger = 0,
  Measure = 1
};

enum class SensorTriggerType: uint8_t {
  Force = 0,
  Info = 1
};

enum class SensorTriggerDirection : uint8_t {
  None = 0,
  Forward = 1,
  Backward = 2,
  Both = 3
};

class TriggerSensor {
public:
  TriggerSensor(uint8_t id, SensorType type, SensorTriggerType triggerType);
  ~TriggerSensor();
  uint8_t getId();
  SensorType getType();
  SensorTriggerType getTriggerType();
  void virtual read() = 0;
  bool virtual isTriggered() = 0;
  bool virtual isStillTriggered() = 0;
  bool virtual wasTriggered() = 0;

  String virtual toString();
protected:
  uint8_t id;
  SensorType type;
  SensorTriggerType triggerType;
};

#endif