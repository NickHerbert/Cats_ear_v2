/*
  Light_sensor.h - Library for performing functions on the light sensor
  Created By Nick Herbert
*/
#ifndef Light_sensor_h
#define Light_sensor_h

#include "Arduino.h"
class Light_sensor{
  public:
    Light_sensor();
    int get_light_sensor_value();
    void set_light_sensor_thresh(int threshold);
    void update(unsigned long currentMillis);
  private:
    int light_sensor_thresh;
    int updateInterval;        // interval between updates
    unsigned long lastUpdate;  // last update of position
};
#endif
