#ifndef DIRECTIONSENSORMANAGER_H
#define DIRECTIONSENSORMANAGER_H

#include "Arduino.h"
// You can control the scope depending on your own flag
#ifdef SENSORMANAGER_ENABLE_DEBUGLOG
#include <DebugLogEnable.h>
#else
#include <DebugLogDisable.h>
#endif  // SENSORMANAGER_ENABLE_DEBUGLOG
#include "TriggerSensor.h"
#include "RegisteredSensors.h"
#include "DistanceDevice.h"
#include "DirectionDistanceSensor.h"

class DirectionSensorManager {
public:
  DirectionSensorManager(DirectionTriggerSensor **sensors, uint16_t sensorCount, DistanceDevice *distanceDevice);
  void begin();
  void end();
  void read();
  uint16_t currentDistance();

  DirectionTriggerSensor *lastTriggeredSensor();
  int16_t lastTriggeredIndex();
  uint16_t getSensorCount();
  RegisteredSensors<DirectionTriggerSensor> getSensors();
  RegisteredSensors<DirectionTriggerSensor> getSensors(SensorTriggerType triggerType);
  RegisteredSensors<DirectionTriggerSensor> getSensors(SensorTriggerType triggerType, SensorTriggerDirection *directions, uint16_t directionsCount);

  void addSensor(DirectionTriggerSensor *newSensor);
  void addDistanceSensor(uint16_t id, String name, uint16_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection);
  void removeSensor(DirectionTriggerSensor *newSensor);
  void removeSensors(SensorType type);
  void removeSensors(SensorTriggerType triggerType);

  void printSensors();

private:

  void onSensorTriggerOnce(DirectionTriggerSensor *sensor);
  void onSensorTrigger(DirectionTriggerSensor *sensor);

  DistanceDevice *distanceDevice;
  DirectionTriggerSensor **sensors;
  uint16_t sensorCount;
  DirectionTriggerSensor *_lastSensor = nullptr;

  uint16_t *steps;
  uint16_t stepCount = 0;
};

#endif