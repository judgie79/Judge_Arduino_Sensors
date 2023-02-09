
#include <ButtonSensor.h>
#include <DistanceDevice.h>
#include <SonarDistanceDevice.h>
#include <SensorManager.h>
#include <DistanceSensor.h>

#include <DebugOut.h>

const int distanceEchoPin = 12;    // the number of the echo pin connected to the distance sensor
const int distanceTriggerPin = 13; // the number of the trigger pin connected to the distance sensor
SonarDistanceDevice sonar(distanceTriggerPin, distanceEchoPin, 30);

const int backEndSensorPin = 11; // the number of the pushbutton pin of the backend sensor
const int frontEndSensorPin = 7; // the number of the pushbutton pin of the front end sensor
ButtonSensor backEndSensor(0, "START", SensorType::Trigger, SensorTriggerType::ForceStop, SensorTriggerDirection::Backward, backEndSensorPin, INPUT_PULLUP);
ButtonSensor frontEndSensor(3, "END", SensorType::Trigger, SensorTriggerType::ForceStop, SensorTriggerDirection::Forward, frontEndSensorPin, INPUT_PULLUP);
DistanceSensor pos1Sensor(1, "POS1", SensorTriggerType::Position, SensorTriggerDirection::Both, &sonar );

TriggerSensor **defaultSensors = new TriggerSensor*[3]{ &backEndSensor, &pos1Sensor, &frontEndSensor };

SensorManager sManager(defaultSensors, 3, &sonar);

int steps[2] = {7, 15};
const int defaultPos = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  DebugOut.setOutput(&Serial);
  DebugOut.enable();
  sManager.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  sManager.read();

  Serial.println(sManager.currentDistance());
  
  if (sManager.lastTriggeredSensor() != NULL)
  {
  	  Serial.println(sManager.lastTriggeredSensor()->getId());
      Serial.println(sManager.lastTriggeredSensor()->getName());
      Serial.println((int)sManager.lastTriggeredSensor()->getTriggerDirection());
      Serial.println((int)sManager.lastTriggeredSensor()->getTriggerType());
  }
  
  

}
