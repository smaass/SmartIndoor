#include <timer.h>
#include <arduino.h>

void Timer::start() {
  rtc.start();
  performUpdate();
};

void Timer::performUpdate() {
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  lastUpdate = millis();
};

void Timer::update() {
  if (millis() >= lastUpdate + MIN_REFRESH_INTERVAL_MILLIS) {
    performUpdate();
  }
}

void Timer::setDateTime(
  uint16_t year,
  uint8_t month,
  uint8_t day,
  uint8_t hour,
  uint8_t min,
  uint8_t sec
) {
  rtc.set(sec, min, hour, day, month, year); //sec, min, hour, day, month, year
};

uint8_t Timer::getSecond() {
  update();
  return sec;
}

uint8_t Timer::getMinute() {
  update();
  return min;
}

uint8_t Timer::getHour() {
  update();
  return hour;
}
