/*
  Vib_sensor.h - Library for performing functions on the vibration sensor
  Created By Nick Herbert
*/
#ifndef Vib_sensor_h
#define Vib_sensor_h

#include "Arduino.h"
class Vib_sensor{
  public:
    Vib_sensor(int interval);
    int get_vib_sensor_value();
    void set_vib_sensor_thresh(int threshold);
    void update(unsigned long currentMillis);
  private:
    int vib_sensor_thresh;
    int updateInterval;        // interval between updates
    unsigned long lastUpdate;  // last update of position
};
#endif
