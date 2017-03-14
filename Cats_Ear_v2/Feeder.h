/*
  Feeder.h - Library for performing functions on a feeder module
  Created By Nick Herbert
*/
#ifndef Feeder_h
#define Feeder_h

#include "Arduino.h"
#include "Sweeper.h"
#include "Flasher.h"
class Feeder{
  public:
    Feeder(int led_pin, long on, long off, int servo_pin, int interval, int oAngle, int cAngle);
    void servo_open();
    void servo_close();
    void set_indicator_light(bool is_on);
    float get_vib_sensor();
    void set_vib_sensor_thresh(int threshold);
    float get_light_sensor();
    void set_light_sensor_thresh(int threshold);
    void update(unsigned long currentMillis);
  private:
    Sweeper servo;               // the servo
    Flasher led;
    int light_sensor_thresh;
    int vib_sensor_thresh;
    bool indicator_light;
    int updateInterval;        // interval between updates
    unsigned long lastUpdate;  // last update of position
};
#endif
