/*
  Feeder.h - Library for performing functions on a feeder module
  Created By Nick Herbert
*/
#ifndef Feeder_h
#define Feeder_h

#include "Arduino.h"
#include "Sweeper.h"
class Feeder{
  public:
    Feeder(int interval, int oAngle, int cAngle);
    void update();
  private:
    Sweeper servo;               // the servo
    int updateInterval;        // interval between updates
    unsigned long lastUpdate;  // last update of position
};
#endif
