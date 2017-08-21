#include <Arduino.h>
#include <timer.h>
#include <environment.h>

const uint8_t VALVE_PIN = 3;
const uint8_t DHT_PIN = 4;
const uint8_t WATER_LEVEL_PIN = A2;

Environment environment;
Timer timer;  // A4 (SDA), A5 (SCL)

void openValve() {
  digitalWrite(VALVE_PIN, HIGH);
}

void closeValve() {
  digitalWrite(VALVE_PIN, LOW);
}

void initValve() {
  pinMode(VALVE_PIN, OUTPUT);
  closeValve();
}

void setup() {
  Serial.begin(9600);
  // Do only once
  // timer.setDateTime(currentTime)
  timer.start();
  environment.setUpDHT(DHT_PIN);
  initValve();
}

void loop() {
  // Serial.print(timer.getHour(), DEC);
  delay(1000);
  int waterLevel = analogRead(WATER_LEVEL_PIN);
  Serial.println(waterLevel);
  if (waterLevel < 550) {
    openValve();
  }
  else {
    closeValve();
  }
}
