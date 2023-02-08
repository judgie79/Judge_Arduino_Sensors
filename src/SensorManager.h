#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "Arduino.h"
// You can control the scope depending on your own flag
#ifdef SENSORMANAGER_ENABLE_DEBUGLOG
#include <DebugLogEnable.h>
#else
#include <DebugLogDisable.h>
#endif  // SENSORMANAGER_ENABLE_DEBUGLOG
#include "MotorSensor.h"
#include "RegisteredSensors.h"
#include "DistanceDevice.h"
#include "DistanceSensor.h"

class SensorManager {
public:
  SensorManager(MotorSensor **sensors, uint16_t sensorCount, DistanceDevice *distanceDevice);
  void begin();
  void end();
  void read();
  uint16_t currentDistance();

  MotorSensor *lastTriggeredSensor();
  int16_t lastTriggeredIndex();
  uint16_t getSensorCount();
  RegisteredSensors getSensors();
  RegisteredSensors getSensors(SensorTriggerType triggerType);
  RegisteredSensors getSensors(SensorTriggerType triggerType, SensorTriggerDirection *directions, uint16_t directionsCount);

  void addSensor(MotorSensor *newSensor);
  void addDistanceSensor(uint16_t id, String name, uint16_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection);
  void removeSensor(MotorSensor *newSensor);
  void removeSensors(SensorType type);
  void removeSensors(SensorTriggerType triggerType);

  void printSensors();

private:

  void onSensorTriggerOnce(MotorSensor *sensor);
  void onSensorTrigger(MotorSensor *sensor);

  DistanceDevice *distanceDevice;
  MotorSensor **sensors;
  uint16_t sensorCount;
  MotorSensor *_lastSensor = nullptr;

  uint16_t *steps;
  uint16_t stepCount = 0;
};

#endif