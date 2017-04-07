/*
  Feeder.cpp - Library for perfomring actions on a feeder module
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Feeder.h"

Feeder::Feeder(Bitmask8& output_bits, int led_pos, long on, long off, int servo_pin, int interval, int oAngle, int cAngle, int duration):servo(servo_pin,interval,oAngle,cAngle),led(output_bits,led_pos,on,off),light(interval),vib(interval){
  updateInterval = interval;        // interval between updates
  servo_open_duration = duration;
  open_count = 0;
  lastUpdate = 0;  // last update of position
}
void Feeder::servo_open(){
  servo.activate_servo();
  servo.set_state(OPENING);
  open_count++;
}
void Feeder::servo_close(){
  servo.activate_servo();
  servo.set_state(CLOSING);
}
void Feeder::set_indicator_light(boolean is_on){
  led.set_state(is_on);
}
int Feeder::get_vib_sensor_value(){
  vib.get_vib_sensor_value();
}
void Feeder::set_vib_sensor_thresh(int threshold){
  vib.set_vib_sensor_thresh(threshold);
}
int Feeder::get_light_sensor_value(){
  light.get_light_sensor_value();
}
void Feeder::set_light_sensor_thresh(int threshold){
  light.set_light_sensor_thresh(threshold);
}
int Feeder::number_of_opens(){
  return open_count;
}
void Feeder::update(unsigned long currentMillis){

  if((currentMillis - lastUpdate) > updateInterval){  // time to update

    servo.update(currentMillis);
    led.update(currentMillis);
    light.update(currentMillis);
    vib.update(currentMillis);

  }
}
