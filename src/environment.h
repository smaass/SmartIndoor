#include <DHT.h>

class Environment {
private:
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
};
