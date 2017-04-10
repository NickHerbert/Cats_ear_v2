/*
  Sweeper.h - Library to preform functions on a servo
  created by Nick Herbert
*/
#ifndef Sweeper_h
#define Sweeper_h

#include "Arduino.h"
#include <Servo.h>
#define CLOSED  0
#define OPENED  1
#define OPENING 2
#define CLOSING 3
#define RESET   4

class Sweeper{
  public:
    Sweeper();
    Sweeper(int servo_pin,int interval, int oAngle, int cAngle,int pwm_min, int pwn_max);
    void init_servo_position();
    void activate_servo();
    void deactivate_servo();
    void set_state(int state);
    int get_state();
    void set_speed (int speed);
    void set_close_angle (int angle);
    void set_open_angle (int angle);
    void update(unsigned long currentMillis);
  private:
    void open_servo();
    void close_servo();
    Servo servo;                  // the servo
    int pwm_min;
    int pwn_max;
    int servo_pin;
    int sweeperState;             // 0 closed, 1 opened, 2 opening, 3 closing
    int pos;                      // current servo position
    int stepSize;                 // increment to move for each interval
    unsigned long updateInterval; // interval between updates
    int openedAngle;              // angle at which the servo is considered open
    int closedAngle;              // angle at which the servo is considered closed
    unsigned long lastUpdate;     // last update of position

};
#endif
