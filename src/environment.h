#include <DHT.h>

class Environment {

private:
  uint8_t waterTankSensorPin, waterTraySensorPin, valvePin, soilMoistureSensorPin;
  int waterTraySensorThreshold, soilMoistureSensorThreshold;
  float airHumidity, airTemperature;
  unsigned long lastDHTUpdate;
  unsigned long minDHTSamplingPeriod;
  DHT dht;
  void updateDHT();
  void performDHTUpdate();

public:
  void setUpDHT(uint8_t dht_pin);
  String getDHTStatus();
  float getAirHumidity();
  float getAirTemperature();

  void setUpWaterTankSensor(uint8_t sensor_pin);
  bool tankNeedsWater();

  void setUpSoilMoistureSensor(uint8_t sensor_pin, uint16_t threshold);
  int getSoilMoisture();
  bool soilNeedsWater();

  void setUpWaterTraySensor(uint8_t sensor_pin, uint16_t threshold);
  bool trayNeedsWater();

  void setUpValve(uint8_t sensor_pin);
  void closeValve();
  void openValve();
};
