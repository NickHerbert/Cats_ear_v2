/*
  Feeder.cpp - Library for perfomring actions on a feeder module
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Feeder.h"

Feeder::Feeder(int led_pin, long on, long off, int servo_pin, int interval, int oAngle, int cAngle):servo(servo_pin,interval,oAngle,cAngle),led(led_pin,on,off){
  updateInterval = interval;        // interval between updates
  lastUpdate = 0;  // last update of position
}
void Feeder::servo_open(){
  servo.activate_servo();
  servo.set_state(OPENING);
}
void Feeder::servo_close(){
  servo.activate_servo();
  servo.set_state(CLOSING);
}
void Feeder::set_indicator_light(boolean is_on){

}
float Feeder::get_vib_sensor(){

}
void Feeder::set_vib_sensor_thresh(int threshold){

}
float Feeder::get_light_sensor(){

}
void Feeder::set_light_sensor_thresh(int threshold){

}
void Feeder::update(unsigned long currentMillis){
  if((currentMillis - lastUpdate) > updateInterval){  // time to update

    servo.update(currentMillis);
    led.update(currentMillis);
  }
}
