#include <arduino.h>
#include <environment.h>

void Environment::updateDHT() {
  if (millis() >= lastDHTUpdate + minDHTSamplingPeriod) {
    performDHTUpdate();
  }
};

void Environment::performDHTUpdate() {
  airHumidity = dht.getHumidity();
  airTemperature = dht.getTemperature();
  lastDHTUpdate = millis();
};

void Environment::setUpDHT(uint8_t dht_pin) {
  dht.setup(dht_pin);
  minDHTSamplingPeriod = dht.getMinimumSamplingPeriod();
  delay(minDHTSamplingPeriod);
  performDHTUpdate();
};

String Environment::getDHTStatus() {
  return dht.getStatusString();
};

float Environment::getAirHumidity() {
  updateDHT();
  return airHumidity;
};

float Environment::getAirTemperature() {
  updateDHT();
  return airTemperature;
};

void Environment::setUpWaterTankSensor(uint8_t sensor_pin) {
  waterTankSensorPin = sensor_pin;
  pinMode(waterTankSensorPin, INPUT);
};

bool Environment::tankNeedsWater() {
  return digitalRead(waterTankSensorPin) == LOW;
};

void Environment::setUpSoilMoistureSensor(uint8_t sensor_pin, uint16_t threshold) {
  soilMoistureSensorPin = sensor_pin;
  soilMoistureSensorThreshold = threshold;
};

int Environment::getSoilMoisture() {
  return analogRead(soilMoistureSensorPin);
};

bool Environment::soilNeedsWater() {
  int soilMoisture = getSoilMoisture();
  return soilMoisture > soilMoistureSensorThreshold;
};

void Environment::setUpWaterTraySensor(uint8_t sensor_pin, uint16_t threshold) {
  waterTraySensorPin = sensor_pin;
  waterTraySensorThreshold = threshold;
};

bool Environment::trayNeedsWater() {
  int waterTrayLevel = analogRead(waterTraySensorPin);
  return waterTrayLevel < waterTraySensorThreshold;
};

void Environment::setUpValve(uint8_t sensor_pin) {
  valvePin = sensor_pin;
  pinMode(valvePin, OUTPUT);
  closeValve();
};

void Environment::closeValve() {
  digitalWrite(valvePin, LOW);
};

void Environment::openValve() {
  digitalWrite(valvePin, HIGH);
};
