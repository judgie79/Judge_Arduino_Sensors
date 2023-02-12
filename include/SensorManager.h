#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "Arduino.h"
#include "TriggerSensor.h"
#include "RegisteredSensors.h"
#include "DistanceDevice.h"
#include "DirectionDistanceSensor.h"

class SensorManager {
public:
  SensorManager(TriggerSensor **sensors, uint8_t sensorCount, DistanceDevice *distanceDevice);
  void begin();
  void end();
  void read();
  uint8_t currentDistance();

  TriggerSensor *lastTriggeredSensor();
  int16_t lastTriggeredIndex();
  uint8_t getSensorCount();
  RegisteredSensors<TriggerSensor> getSensors();
  RegisteredSensors<TriggerSensor> getSensors(SensorTriggerType triggerType);

  void addSensor(TriggerSensor *newSensor);
  void removeSensor(TriggerSensor *newSensor);
  void removeSensors(SensorType type);
  void removeSensors(SensorTriggerType triggerType);
private:

  void onSensorTriggerOnce(TriggerSensor *sensor);
  void onSensorTrigger(TriggerSensor *sensor);

  DistanceDevice *distanceDevice;
  TriggerSensor **sensors;
  uint8_t sensorCount;
  TriggerSensor *_lastSensor = nullptr;

  uint8_t *steps;
  uint8_t stepCount = 0;
};

#endif