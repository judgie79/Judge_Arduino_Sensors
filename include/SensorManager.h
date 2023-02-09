#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

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

class SensorManager {
public:
  SensorManager(TriggerSensor **sensors, uint16_t sensorCount, DistanceDevice *distanceDevice);
  void begin();
  void end();
  void read();
  uint16_t currentDistance();

  TriggerSensor *lastTriggeredSensor();
  int16_t lastTriggeredIndex();
  uint16_t getSensorCount();
  RegisteredSensors<TriggerSensor> getSensors();
  RegisteredSensors<TriggerSensor> getSensors(SensorTriggerType triggerType);

  void addSensor(TriggerSensor *newSensor);
  void removeSensor(TriggerSensor *newSensor);
  void removeSensors(SensorType type);
  void removeSensors(SensorTriggerType triggerType);

  void printSensors();

private:

  void onSensorTriggerOnce(TriggerSensor *sensor);
  void onSensorTrigger(TriggerSensor *sensor);

  DistanceDevice *distanceDevice;
  TriggerSensor **sensors;
  uint16_t sensorCount;
  TriggerSensor *_lastSensor = nullptr;

  uint16_t *steps;
  uint16_t stepCount = 0;
};

#endif