#include "Arduino.h"
#include "DirectionSensorManager.h"


DirectionSensorManager::DirectionSensorManager(DirectionTriggerSensor **sensors, uint8_t sensorCount, DistanceDevice *distanceDevice) {
  this->sensors = sensors;
  this->sensorCount = sensorCount;
  this->distanceDevice = distanceDevice;
}

void DirectionSensorManager::begin() {

  distanceDevice->begin();
}

uint8_t DirectionSensorManager::currentDistance()
{
  return distanceDevice->getDistance();
}

void DirectionSensorManager::addSensor(DirectionTriggerSensor *newSensor)
{
  DirectionTriggerSensor **newArray = new DirectionTriggerSensor*[sensorCount + 1];
  for (size_t i = 0; i < sensorCount; i++)
  {
    newArray[i] = sensors[i];
  }
  newArray[sensorCount] = newSensor;
  sensors = NULL;
  sensors = newArray;
  sensorCount++;
}

void DirectionSensorManager::addDistanceSensor(uint8_t id, uint8_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection)
{
  DirectionDistanceSensor *newSensor = new DirectionDistanceSensor(id, triggerDistance, triggerType, triggerDirection, this->distanceDevice);
  addSensor(newSensor);
}

  void DirectionSensorManager::removeSensor(DirectionTriggerSensor *sensorToRemove)
  {
    DirectionTriggerSensor **newArray = new DirectionTriggerSensor*[sensorCount - 1];
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

  void DirectionSensorManager::removeSensors(SensorType type)
  {
    
    uint8_t skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getType() == type)
      {
        skipCounter++;
      }
    }

    DirectionTriggerSensor **newArray = new DirectionTriggerSensor*[sensorCount - skipCounter];
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

void DirectionSensorManager::removeSensors(SensorTriggerType triggerType)
  {
     uint8_t skipCounter = 0;
    for (size_t i = 0; i < sensorCount; i++)
    {
      if (sensors[i]->getTriggerType() == triggerType)
      {
        skipCounter++;
      }
    }

    DirectionTriggerSensor **newArray = new DirectionTriggerSensor*[sensorCount - skipCounter];
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


void DirectionSensorManager::onSensorTriggerOnce(DirectionTriggerSensor *sensor) {
  _lastSensor = sensor;
}

void DirectionSensorManager::onSensorTrigger(DirectionTriggerSensor *sensor) {
  _lastSensor = sensor;
}

void DirectionSensorManager::end() {
}

void DirectionSensorManager::read() {
  distanceDevice->reset();
  for (size_t i = 0; i < sensorCount; i++)
  {
    DirectionTriggerSensor *sensor = sensors[i];
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

DirectionTriggerSensor *DirectionSensorManager::lastTriggeredSensor() {
  return _lastSensor;
}

int16_t DirectionSensorManager::lastTriggeredIndex() {

    int16_t returnValue = -1;
    DirectionTriggerSensor *lastSensor = lastTriggeredSensor();
  if (lastSensor != NULL && lastSensor != nullptr)
  {
    for (size_t i = 0; i < sensorCount; i++)
    {
      DirectionTriggerSensor *sensor = sensors[i];
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

uint8_t DirectionSensorManager::getSensorCount()
{
  return sensorCount;
}

RegisteredSensors<DirectionTriggerSensor> DirectionSensorManager::getSensors() {
  RegisteredSensors<DirectionTriggerSensor> rSensors;
  rSensors.sensorCount = sensorCount;
  rSensors.sensors = sensors;
  return rSensors;
}

RegisteredSensors<DirectionTriggerSensor> DirectionSensorManager::getSensors(SensorTriggerType triggerType)
{
  return getSensors(triggerType, NULL, 0);
}


RegisteredSensors<DirectionTriggerSensor> DirectionSensorManager::getSensors(SensorTriggerType triggerType, SensorTriggerDirection *directions, uint8_t directionsCount)
{
  uint16_t foundSensors = 0;
  for (size_t i = 0; i < sensorCount; i++)
  {
    DirectionTriggerSensor *sensor = sensors[i];
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
  
  DirectionTriggerSensor **found = new DirectionTriggerSensor*[foundSensors];
  foundSensors = 0;
  for (size_t i = 0; i < sensorCount; i++)
  {
    DirectionTriggerSensor *sensor = sensors[i];
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
  
  
  RegisteredSensors<DirectionTriggerSensor> rSensors;
  rSensors.sensorCount = foundSensors;
  rSensors.sensors = found;
  return rSensors;
}

void DirectionSensorManager::printSensors()
{
  for (size_t i = 0; i < sensorCount; i++)
  {
    LOGD_INFO(sensors[i]->toString() );
  }
  
}