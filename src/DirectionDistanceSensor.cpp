#include "DirectionDistanceSensor.h"

DirectionDistanceSensor::DirectionDistanceSensor(uint8_t id, uint8_t triggerDistance, SensorTriggerType triggerType, SensorTriggerDirection triggerDirection, DistanceDevice* device)
  : DistanceSensor(id, triggerDistance, triggerType, device), DirectionTriggerSensor(id, SensorType::Measure, triggerType, triggerDirection) {
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

uint8_t DirectionDistanceSensor::getTriggerDistance()
{
	return DistanceSensor::getTriggerDistance();;
}

uint8_t DirectionDistanceSensor::getDistance() {
	return DistanceSensor::getDistance();
}

uint8_t DirectionDistanceSensor::getLastDistance() {

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
