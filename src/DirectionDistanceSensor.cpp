#include "DirectionDistanceSensor.h"

DirectionDistanceSensor::DirectionDistanceSensor(uint16_t id, String name,  uint16_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, DistanceDevice* device)
  : DirectionTriggerSensor(id, name, SensorType::Measure, triggerType, triggerDirection), DistanceSensor(id, name, triggerDistance, triggerType, device) {
}

DirectionDistanceSensor::~DirectionDistanceSensor()
{

}

void DirectionDistanceSensor::begin() {
}

void DirectionDistanceSensor::setTriggerDistance(uint8_t distance)
{
	DistanceSensor::setTriggerDistance(distance);
}

uint16_t DirectionDistanceSensor::getTriggerDistance()
{
	return DistanceSensor::getTriggerDistance();;
}

uint16_t DirectionDistanceSensor::getDistance() {
	return DistanceSensor::getDistance();
}

uint16_t DirectionDistanceSensor::getLastDistance() {

	return DistanceSensor::getLastDistance();
}

void DirectionDistanceSensor::read() {
	this->DistanceSensor::read();
}

bool DirectionDistanceSensor::isTriggered() {
	return DistanceSensor::isTriggered();
}

bool DirectionDistanceSensor::isStillTriggered() {
	return DistanceSensor::isStillTriggered();
}

String DirectionDistanceSensor::toString()
{
	return DistanceSensor::toString();
}

bool DirectionDistanceSensor::wasTriggered() {
	return DistanceSensor::wasTriggered();
}
