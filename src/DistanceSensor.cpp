#include "Arduino.h"
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(uint16_t id, String name, uint16_t triggerDistance, SensorTriggerType triggerType, DistanceDevice* device)
	: TriggerSensor(id, name, SensorType::Measure, triggerType) {
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

uint16_t DistanceSensor::getTriggerDistance()
{
	return triggerDistance;
}

uint16_t DistanceSensor::getDistance() {
	return device->getDistance();
}

uint16_t DistanceSensor::getLastDistance() {

	return device->getLastDistance();
}

void DistanceSensor::read() {
	this->device->read();
}

bool DistanceSensor::isTriggered() {
	uint16_t lastDistance = getLastDistance();
	uint16_t currentDistance = getDistance();

	uint16_t offsetToTriggerDistance = abs(triggerDistance - currentDistance);
	uint16_t lastOffsetToTriggerDistance = abs(triggerDistance - lastDistance);

	return offsetToTriggerDistance == 0 && lastOffsetToTriggerDistance != 0;
}

bool DistanceSensor::isStillTriggered() {
	uint16_t lastDistance = getLastDistance();
	uint16_t currentDistance = getDistance();

	uint16_t offsetToTriggerDistance = abs(triggerDistance - currentDistance);
	uint16_t lastOffsetToTriggerDistance = abs(triggerDistance - lastDistance);

	return offsetToTriggerDistance == 0 && lastOffsetToTriggerDistance == 0;
}

String DistanceSensor::toString()
{
	return String(getId()) + " - " + getName();// +" - " + String(SensorTypeNames[(int)getType()]) + " - " + String(SensorTriggerTypeNames[(int)getTriggerType()]) + " - " + String(SensorTriggerDirectionNames[(int)getTriggerDirection()]) + " - " + String(getTriggerDistance());
}

bool DistanceSensor::wasTriggered() {
	uint16_t lastDistance = getLastDistance();
	uint16_t currentDistance = getDistance();

	LOGD_DEBUG(String(currentDistance) + " - " + String(lastDistance) + " - " + String(triggerDistance));
	uint16_t offsetToTriggerDistance = abs(triggerDistance - currentDistance);
	uint16_t lastOffsetToTriggerDistance = abs(triggerDistance - lastDistance);

	return offsetToTriggerDistance != 0 && lastOffsetToTriggerDistance == 0;
}