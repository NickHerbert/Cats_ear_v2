/*
  Sweeper.h - Library to preform functions on a servo
  created by Nick Herbert
*/
#ifndef Sweeper_h
#define Sweeper_h

#include "Arduino.h"
#include <Servo.h>
#define OPENING 1
#define OPENED 2
#define CLOSING 3
#define CLOSED 4
class Sweeper{
  public:
    Sweeper();
    Sweeper(int interval, int oAngle, int cAngle);
    void attachServo(int pin);
    void detachServo();
    void update();
  private:
    Servo servo;               // the servo
    int pos;                   // current servo position
    int stepSize;              // increment to move for each interval
    int updateInterval;        // interval between updates
    int openedAngle;           // angle at which the servo is considered open
    int closedAngle;           // angle at which the servo is considered closed
    unsigned long lastUpdate;  // last update of position
    boolean sweeperState;      // false is closed true is open
};
#endif
