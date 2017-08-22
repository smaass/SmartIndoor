#include <Arduino.h>
#include <timer.h>
#include <environment.h>

const uint8_t VALVE_PIN = 3;
const uint8_t DHT_PIN = 4;
const uint8_t WATER_TANK_PIN = 5;
const uint8_t WATER_LEVEL_PIN = A2;

Environment environment;
Timer timer;  // A4 (SDA), A5 (SCL)

void setup() {
  Serial.begin(9600);
  // timer.setDateTime(currentTime) // Do only once
  timer.start();
  environment.setUpDHT(DHT_PIN);
  environment.setUpValve(VALVE_PIN);
  environment.setUpWaterTankSensor(WATER_TANK_PIN);
  environment.setUpWaterTraySensor(WATER_LEVEL_PIN, 500);
}

void loop() {
  // Serial.print(timer.getHour(), DEC);
  delay(1000);
  if (environment.trayNeedsWater()) {
    environment.openValve();
  }
  else {
    environment.closeValve();
  }
}
