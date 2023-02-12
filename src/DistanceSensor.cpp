#include "Arduino.h"
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(uint8_t id, uint8_t triggerDistance, SensorTriggerType triggerType, DistanceDevice* device)
	: TriggerSensor(id, SensorType::Measure, triggerType) {
	this->device = device;
	this->triggerDistance = triggerDistance;
}

DistanceSensor::~DistanceSensor()
{

}

void DistanceSensor::begin() {
}

void DistanceSensor::setTriggerDistance(uint8_t distance)
{
	triggerDistance = distance;
}

uint8_t DistanceSensor::getTriggerDistance()
{
	return triggerDistance;
}

uint8_t DistanceSensor::getDistance() {
	return device->getDistance();
}

uint8_t DistanceSensor::getLastDistance() {

	return device->getLastDistance();
}

void DistanceSensor::read() {
	this->device->read();
}

bool DistanceSensor::isTriggered() {
	return abs(triggerDistance - getDistance()) == 0 && abs(triggerDistance - getLastDistance()) != 0;
}

bool DistanceSensor::isStillTriggered() {
	return abs(triggerDistance - getDistance()) == 0 && abs(triggerDistance - getLastDistance()) == 0;
}

String DistanceSensor::toString()
{
	return String(getId());
}

bool DistanceSensor::wasTriggered() {
	return abs(triggerDistance - getDistance()) != 0 && abs(triggerDistance - getLastDistance()) == 0;
}