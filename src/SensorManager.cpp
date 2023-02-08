#include "Arduino.h"
#include "SensorManager.h"


SensorManager::SensorManager(MotorSensor **sensors, uint16_t sensorCount, DistanceDevice *distanceDevice) {
  this->sensors = sensors;
  this->sensorCount = sensorCount;
  this->distanceDevice = distanceDevice;
}

void SensorManager::begin() {

  distanceDevice->begin();
}

uint16_t SensorManager::currentDistance()
{
  return distanceDevice->getDistance();
}

void SensorManager::addSensor(MotorSensor *newSensor)
{
  MotorSensor **newArray = new MotorSensor*[sensorCount + 1];
  for (size_t i = 0; i < sensorCount; i++)
  {
    newArray[i] = sensors[i];
  }
  newArray[sensorCount] = newSensor;
  sensors = NULL;
  sensors = newArray;
  sensorCount++;
}

void SensorManager::addDistanceSensor(uint16_t id, String name, uint16_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection)
{
  DistanceSensor *newSensor = new DistanceSensor(id, name, triggerDistance, triggerType, triggerDirection, this->distanceDevice);
  addSensor(newSensor);
}

  void SensorManager::removeSensor(MotorSensor *sensorToRemove)
  {
    MotorSensor **newArray = new MotorSensor*[sensorCount - 1];
    uint16_t skipCounter = 0;
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
    
    uint16_t skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getType() == type)
      {
        skipCounter++;
      }
    }

    MotorSensor **newArray = new MotorSensor*[sensorCount - skipCounter];
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
     uint16_t skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getTriggerType() == triggerType)
      {
        skipCounter++;
      }
    }

    MotorSensor **newArray = new MotorSensor*[sensorCount - skipCounter];
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


void SensorManager::onSensorTriggerOnce(MotorSensor *sensor) {
  _lastSensor = sensor;
}

void SensorManager::onSensorTrigger(MotorSensor *sensor) {
  _lastSensor = sensor;
}

void SensorManager::end() {
}

void SensorManager::read() {
  distanceDevice->reset();
  for (size_t i = 0; i < sensorCount; i++)
  {
    MotorSensor *sensor = sensors[i];
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

MotorSensor *SensorManager::lastTriggeredSensor() {
  return _lastSensor;
}

int16_t SensorManager::lastTriggeredIndex() {

    int16_t returnValue = -1;
    MotorSensor *lastSensor = lastTriggeredSensor();
  if (lastSensor != NULL && lastSensor != nullptr)
  {
    for (size_t i = 0; i < sensorCount; i++)
    {
      MotorSensor *sensor = sensors[i];
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

uint16_t SensorManager::getSensorCount()
{
  return sensorCount;
}

RegisteredSensors SensorManager::getSensors() {
  RegisteredSensors rSensors;
  rSensors.sensorCount = sensorCount;
  rSensors.sensors = sensors;
  return rSensors;
}

RegisteredSensors SensorManager::getSensors(SensorTriggerType triggerType)
{
  return getSensors(triggerType, NULL, 0);
}


RegisteredSensors SensorManager::getSensors(SensorTriggerType triggerType, SensorTriggerDirection *directions, uint16_t directionsCount)
{
  uint16_t foundSensors = 0;
  for (size_t i = 0; i < sensorCount; i++)
  {
    MotorSensor *sensor = sensors[i];
    if (sensor->getTriggerType() == triggerType)
    {
      if (directionsCount > 0)
      {
        for (size_t d = 0; d < directionsCount; d++)
        {
          if (sensor->getTriggerDirection() == directions[d])
          {
            foundSensors++;
          }
        }
      } else
      {
        foundSensors++;
      }    
    }
  }
  
  MotorSensor **found = new MotorSensor*[foundSensors];
  foundSensors = 0;
  for (size_t i = 0; i < sensorCount; i++)
  {
    MotorSensor *sensor = sensors[i];
    ASSERTM(sensor != nullptr, "sensor is nullptr");
    if (sensor->getTriggerType() == triggerType)
    {
      if (directionsCount > 0)
      {
        for (size_t d = 0; d < directionsCount; d++)
        {
          if (sensor->getTriggerDirection() == directions[d])
          {
            found[foundSensors] = sensor;
            foundSensors++;
          }
        }
      } else
      {
        found[foundSensors] = sensor;
        foundSensors++;
      }    
    }
  }
  
  
  RegisteredSensors rSensors;
  rSensors.sensorCount = foundSensors;
  rSensors.sensors = found;
  return rSensors;
}

void SensorManager::printSensors()
{
  for (size_t i = 0; i < sensorCount; i++)
  {
    LOGD_INFO(sensors[i]->toString() );
  }
  
}