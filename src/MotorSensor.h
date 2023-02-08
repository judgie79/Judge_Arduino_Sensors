#ifndef MOTORSENSOR_H
#define MOTORSENSOR_H

#include "Arduino.h"

#include <DebugOut.h>

enum class SensorType : uint8_t {
  Trigger = 0,
  Distance = 1
};
// static const char* SensorTypeNames[] = { "Trigger", "Distance" };

enum class SensorTriggerType: uint8_t {
  ForceStop = 0,
  Position = 1
};
// static const char* SensorTriggerTypeNames[] = { "ForceStop", "Position" };

enum class SensorTriggerDirection : uint8_t {
  None = 0,
  Forward = 1,
  Backward = 2,
  Both = 3
};
// static const char* SensorTriggerDirectionNames[] = { "None", "Forward", "Backward", "Both" };

// static const char* TriggerdNames[] = { "off", "on" };

class MotorSensor {
public:
  MotorSensor(uint16_t id, String name, SensorType type, SensorTriggerType triggerType, SensorTriggerDirection sensorTriggerDirection);
  ~MotorSensor();
  uint16_t getId();
  String getName();
  SensorType getType();
  SensorTriggerType getTriggerType();
  SensorTriggerDirection getTriggerDirection();
  bool virtual haltOnTrigger();
  void virtual read() = 0;
  bool virtual isTriggered() = 0;
  bool virtual isStillTriggered() = 0;
  bool virtual wasTriggered() = 0;

  String virtual toString();
protected:
  uint16_t id;
  String name;
  SensorType type;
  SensorTriggerType triggerType;
  SensorTriggerDirection triggerDirection;
};

#endif