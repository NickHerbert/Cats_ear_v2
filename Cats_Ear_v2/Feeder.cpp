/*
  Feeder.cpp - Library for perfomring actions on a feeder module
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Feeder.h"

Feeder::Feeder(int interval, int oAngle, int cAngle):servo(interval,oAngle,cAngle){               // the servo
  updateInterval = 1;        // interval between updates
  lastUpdate = 0;  // last update of position
}
void Feeder::update(){
  if((millis() - lastUpdate) > updateInterval){  // time to update

  }
}
