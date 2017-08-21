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
