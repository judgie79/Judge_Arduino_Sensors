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
        SetCollisionDuration(0);
    } else if (wasTriggered()) {
        Serial.println("released");
        unsigned long t = millis() - colissionTimer;
        SetCollisionDuration(t);
        colissionTimer = 0;
    }
}

  void IRColissionSensor::SetCollisionDuration(unsigned long t)
  {
    colissionDuration = t; 
    Serial.println("IRColissionSensor::SetCollisionDuration");
    Serial.println(colissionDuration);
  }

unsigned long IRColissionSensor::lastCollisionDuration() {
  Serial.println("IRColissionSensor::lastCollisionDuration");
  Serial.println(colissionDuration);
  return colissionDuration;
}

bool IRColissionSensor::isTriggered() {
  return _reading == LOW && _lastReading == HIGH;
}

bool IRColissionSensor::isStillTriggered() {
  return _reading == LOW && _lastReading == LOW;
}

bool IRColissionSensor::wasTriggered() {
  return _reading == HIGH && _lastReading == LOW;
}
