/*
  Sweeper.cpp - Library to preform functions on a servo
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Sweeper.h"


Sweeper::Sweeper(){

}
Sweeper::Sweeper(int servo_pin, int interval, int oAngle, int cAngle){
  servo_pin = servo_pin;
  updateInterval = interval;
  openedAngle = oAngle;
  closedAngle = cAngle;
  stepSize = 1;
  sweeperState = CLOSED;
}
void Sweeper::activate_servo(){
  servo.attach(servo_pin);
}
void Sweeper::deactivate_servo(){
  servo.detach();
}
void Sweeper::set_state(int state){
  sweeperState = state;
}
void Sweeper::set_speed(int speed){
  stepSize = speed;
}
void Sweeper::set_close_angle(int angle){
  closedAngle = angle;
}
void Sweeper::set_open_angle(int angle){
  openedAngle = angle;
}
void Sweeper::update(unsigned long currentMillis){
  if((currentMillis - lastUpdate) > updateInterval)  // time to update
  {
    lastUpdate = millis();
   //get the state of the servo
   switch(sweeperState){
      case OPENING:
        pos += stepSize;
        servo.write(pos);
        if((pos >= openedAngle)){
          sweeperState = OPENED;
        }
        break;
      case OPENED:
        deactivate_servo();
        //we can have some logic happening when the door is open
        break;
      case CLOSING:
        pos -= stepSize;
        servo.write(pos);
        if((pos <= closedAngle)){
          sweeperState = CLOSED;
        }
        break;
      case CLOSED:
        deactivate_servo();
        //we can have some logic happening when the door is closed
        break;
      default:
        break;
   }
  }
}
