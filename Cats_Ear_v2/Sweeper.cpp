/*
  Sweeper.cpp - Library to preform functions on a servo
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Sweeper.h"


Sweeper::Sweeper(){

}
Sweeper::Sweeper(int interval, int oAngle, int cAngle){
  updateInterval = interval;
  openedAngle = oAngle;
  closedAngle = cAngle;
  stepSize = 1;
  sweeperState = false;
}
void Sweeper::attachServo(int pin){
  servo.attach(pin);
}
void Sweeper::detachServo(){
  servo.detach();
}
void Sweeper::update(){
  if((millis() - lastUpdate) > updateInterval)  // time to update
  {
    lastUpdate = millis();
   //get the state of the servo
   switch(sweeperState){
      case OPENING:
        break;
      case OPENED:
        break;
      case CLOSING:
        break;
      case CLOSED:
        break;
      default:
        break;
   }

   if (sweeperState == false){
     pos += stepSize;//if the door is closed then we increment the position until its fully open
   }else{
     pos -= stepSize;//if the door is open then we decrement the position until its fully closed
   }
   servo.write(pos);
   if((pos >= openedAngle)){//door is fully open
      sweeperState = true;
    }else if((pos <= closedAngle)){//door is fully closed
      sweeperState = false;
    }else { // door is stuck somewhere
    }
  }
}
