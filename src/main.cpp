#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
#include <ESP8266HTTPClient.h>

#include <Arduino.h>
#include <timer.h>
#include <environment.h>

const uint8_t VALVE_PIN = D3;
const uint8_t DHT_PIN = D4;
const uint8_t WATER_TANK_PIN = D5;
const uint8_t WATER_LEVEL_PIN = A0;
const uint8_t WATER_MOISTURE_PIN = A0;

Environment environment;
Timer timer;  // D2 (SDA), D1 (SCL)
WiFiClient client;

void setWiFi() {
  WiFiManager wifiManager;
  // wifiManager.resetSettings();
  wifiManager.autoConnect("SmartIndoor");
}

void setup() {
  Serial.begin(9600);
  // setWiFi();
  // timer.setDateTime(2018, 1, 14, 17, 29, 0); // Do only once
  timer.start();
  environment.setUpDHT(DHT_PIN);
  environment.setUpSoilMoistureSensor(WATER_MOISTURE_PIN, 500);
  // environment.setUpValve(VALVE_PIN);
  // environment.setUpWaterTankSensor(WATER_TANK_PIN);
  // environment.setUpWaterTraySensor(WATER_LEVEL_PIN, 500);
}

void showTime() {
  Serial.print(timer.getHour(), DEC);
  Serial.print(":");
  Serial.print(timer.getMinute(), DEC);
  Serial.print(":");
  Serial.print(timer.getSecond(), DEC);
  Serial.print("\n");
}

void loop() {
  // Serial.print(environment.getAirTemperature());
  // Serial.print("\n");
  Serial.print(environment.getSoilMoisture());
  Serial.print("\n");
  delay(1000);
  // if (environment.trayNeedsWater()) {
  //   environment.openValve();
  // }
  // else {
  //   environment.closeValve();
  // }
}
