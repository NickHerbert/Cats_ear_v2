/*
  Sweeper.cpp - Library to preform functions on a servo
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Sweeper.h"

Sweeper::Sweeper(){

}
Sweeper::Sweeper(int s_pin, int interval, int oAngle, int cAngle, int pmin, int pmax){
  servo_pin = s_pin;
  updateInterval = interval;
  lastUpdate = 0;
  openedAngle = oAngle;
  closedAngle = cAngle;
  stepSize = 20;
  sweeperState = CLOSING;
  pwm_min = pmin;
  pwn_max = pmax;
}
void Sweeper::init_servo_position(){
  activate_servo();
  delay(15);
  servo.write(closedAngle);
  delay(200);
  deactivate_servo();
}
void Sweeper::activate_servo(){
  servo.attach(servo_pin, pwm_min, pwn_max);
}
void Sweeper::deactivate_servo(){
  servo.detach();
}
void Sweeper::set_state(int state){
  sweeperState = state;
}
int Sweeper::get_state(){
  return sweeperState;
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
    Serial.println("updating");
    lastUpdate = currentMillis;
   //get the state of the servo
   switch(sweeperState){
      case OPENING:
      Serial.print("OpenPOS: ");
      Serial.println(pos);
      Serial.print("openedAngle: ");
      Serial.println(openedAngle);
        if (pos <= openedAngle){
          open_servo();
        }
        else{
          sweeperState = OPENED;
          deactivate_servo();
        }
        break;
      case OPENED:
        //we can have some logic happening when the door is open
        break;
      case CLOSING:
      Serial.print("ClosePOS: ");
      Serial.println(pos);
      Serial.print("closedAngle: ");
      Serial.println(closedAngle);
        if (pos >= closedAngle){
          close_servo();
        }
        else{
          sweeperState = CLOSED;
          deactivate_servo();
        }
        break;
      case CLOSED:
        //we can have some logic happening when the door is closed
        break;
      default:
        break;
   }
  }
}
void Sweeper::open_servo(){
  Serial.println("Writing open");
  Serial.println(pos);
  pos += stepSize;
  activate_servo();
  servo.write(pos);
}
void Sweeper::close_servo(){
  Serial.println("Close Write");
  Serial.println(pos);
  pos -= stepSize;
  activate_servo();
  servo.write(pos);

}
