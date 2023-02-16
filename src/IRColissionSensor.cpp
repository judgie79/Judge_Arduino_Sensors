#include "IRColissionSensor.h"

IRColissionSensor::IRColissionSensor(uint8_t id, SensorType type, SensorTriggerType triggerType, uint8_t sensorPin)
  : TriggerSensor(id, type, triggerType) {
     pinMode(sensorPin, INPUT);
    _pin = sensorPin;
}

void IRColissionSensor::read() {
    _lastReading = _reading;
    _reading = digitalRead(_pin);

    if (isTriggered()) {
            Serial.println("triggered");
        colissionTimer = millis();
        colissionDuration = 0;
    } else if (wasTriggered()) {
        Serial.println("released");
        colissionDuration = millis() - colissionTimer;
    }
}

long IRColissionSensor::lastCollisionDuration() {
  return colissionDuration;
}

bool IRColissionSensor::isTriggered() {
  return _reading == HIGH && _lastReading == LOW;
}

bool IRColissionSensor::isStillTriggered() {
  return _reading == HIGH && _lastReading == HIGH;
}

bool IRColissionSensor::wasTriggered() {
  return _reading == LOW && _lastReading == HIGH;
}
