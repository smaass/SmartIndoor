#include <Wire.h>
#include <DS1307.h>

class Timer {
private:
  DS1307 rtc;   // Uno: A4 (SDA), A5 (SCL)
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  unsigned long lastUpdate;
  const uint16_t MIN_REFRESH_INTERVAL_MILLIS = 1000;
  void update();
  void performUpdate();
public:
  void start();
  void setDateTime(
    uint16_t year,
    uint8_t month,
    uint8_t day,
    uint8_t hour,
    uint8_t min,
    uint8_t sec
  );
  uint8_t getSecond();
  uint8_t getMinute();
  uint8_t getHour();
};
