#include "Arduino.h"
#include "SensorManager.h"


SensorManager::SensorManager(TriggerSensor **sensors, uint8_t sensorCount, DistanceDevice *distanceDevice) {
  this->sensors = sensors;
  this->sensorCount = sensorCount;
  this->distanceDevice = distanceDevice;
}

void SensorManager::begin() {

  distanceDevice->begin();
}

uint8_t SensorManager::currentDistance()
{
  return distanceDevice->getDistance();
}

void SensorManager::addSensor(TriggerSensor *newSensor)
{
  TriggerSensor **newArray = new TriggerSensor*[sensorCount + 1];
  for (size_t i = 0; i < sensorCount; i++)
  {
    newArray[i] = sensors[i];
  }
  newArray[sensorCount] = newSensor;
  sensors = NULL;
  sensors = newArray;
  sensorCount++;
}

void SensorManager::removeSensor(TriggerSensor *sensorToRemove)
  {
    TriggerSensor **newArray = new TriggerSensor*[sensorCount - 1];
    uint8_t skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i] != sensorToRemove)
      {
        newArray[i-skipCounter] = sensors[i];
      } else {
        skipCounter++;
      }
    }
    sensors = newArray;
    sensorCount -= skipCounter;
  }

  void SensorManager::removeSensors(SensorType type)
  {
    
    uint8_t skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getType() == type)
      {
        skipCounter++;
      }
    }

    TriggerSensor **newArray = new TriggerSensor*[sensorCount - skipCounter];
    skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getType() != type)
      {
        newArray[i-skipCounter] = sensors[i];
      } else {
        skipCounter++;
      }
    }
    sensors = newArray;
    sensorCount -= skipCounter;
  }

void SensorManager::removeSensors(SensorTriggerType triggerType)
  {
     uint8_t skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getTriggerType() == triggerType)
      {
        skipCounter++;
      }
    }

    TriggerSensor **newArray = new TriggerSensor*[sensorCount - skipCounter];
    skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getTriggerType() != triggerType)
      {
        newArray[i-skipCounter] = sensors[i];
      } else {
        skipCounter++;
      }
    }
    sensors = newArray;
    sensorCount -= skipCounter;
  }


void SensorManager::onSensorTriggerOnce(TriggerSensor *sensor) {
  _lastSensor = sensor;
}

void SensorManager::onSensorTrigger(TriggerSensor *sensor) {
  _lastSensor = sensor;
}

void SensorManager::end() {
}

void SensorManager::read() {
  distanceDevice->reset();
  for (size_t i = 0; i < sensorCount; i++)
  {
    TriggerSensor *sensor = sensors[i];
    ASSERTM(sensor != nullptr, "sensor is nullptr");
    sensor->read();
    if (sensor->isTriggered() && sensor->isStillTriggered() == false)
    {
      onSensorTriggerOnce(sensor);
    } else if (sensor->isStillTriggered())
    {
      onSensorTrigger(sensor);
    }
  }
}

TriggerSensor *SensorManager::lastTriggeredSensor() {
  return _lastSensor;
}

int16_t SensorManager::lastTriggeredIndex() {

    int16_t returnValue = -1;
    TriggerSensor *lastSensor = lastTriggeredSensor();
  if (lastSensor != NULL && lastSensor != nullptr)
  {
    for (size_t i = 0; i < sensorCount; i++)
    {
      TriggerSensor *sensor = sensors[i];
      if (sensor != NULL)
      {
        if (sensor->getId() == lastSensor->getId())
        {
          returnValue = i;
        }
      }
    }
  }
  return returnValue;
}

uint8_t SensorManager::getSensorCount()
{
  return sensorCount;
}

RegisteredSensors<TriggerSensor> SensorManager::getSensors() {
  RegisteredSensors<TriggerSensor> rSensors;
  rSensors.sensorCount = sensorCount;
  rSensors.sensors = sensors;
  return rSensors;
}

RegisteredSensors<TriggerSensor> SensorManager::getSensors(SensorTriggerType triggerType)
{
  uint8_t foundSensors = 0;
  for (size_t i = 0; i < sensorCount; i++)
  {
    TriggerSensor *sensor = sensors[i];
    if (sensor->getTriggerType() == triggerType)
    {
      foundSensors++;
    }
  }
  
  TriggerSensor **found = new TriggerSensor*[foundSensors];
  foundSensors = 0;
  for (size_t i = 0; i < sensorCount; i++)
  {
    TriggerSensor *sensor = sensors[i];
    if (sensor->getTriggerType() == triggerType)
    {
      found[foundSensors] = sensor;
      foundSensors++;
    }
  }
  
  
  RegisteredSensors<TriggerSensor> rSensors;
  rSensors.sensorCount = foundSensors;
  rSensors.sensors = found;
  return rSensors;
}