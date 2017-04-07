/*
  Light_sensor.cpp - Library to preform functions on the light sensor
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Light_sensor.h"

Light_sensor::Light_sensor(int interval){
  light_sensor_thresh = 5;
}
int Light_sensor::get_light_sensor_value(){
  return light_sensor_thresh;
}
void Light_sensor::set_light_sensor_thresh(int threshold){
  light_sensor_thresh = threshold;
}
void Light_sensor::update(unsigned long currentMillis){
  if((currentMillis - lastUpdate) > updateInterval){  // time to update

  }
}
