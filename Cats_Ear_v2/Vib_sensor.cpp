/*
  Vib_sensor.cpp - Library to preform functions on the vibration sensor
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Vib_sensor.h"

Vib_sensor::Vib_sensor(int interval){
  updateInterval = interval;
  vib_sensor_thresh = 5;
}
int Vib_sensor::get_vib_sensor_value(){
  return vib_sensor_thresh;
}
void Vib_sensor::set_vib_sensor_thresh(int threshold){
  vib_sensor_thresh = threshold;
}
void Vib_sensor::update(unsigned long currentMillis){
  if((currentMillis - lastUpdate) > updateInterval){  // time to update

  }
}
