/*
  Feeder.h - Library for performing functions on a feeder module
  Created By Nick Herbert
*/
#ifndef Feeder_h
#define Feeder_h

#include "Arduino.h"
#include "Sweeper.h"
#include "Flasher.h"
#include <Servo.h>
#include "Bitmask.h"


class Feeder{
  public:
    Feeder(int led_pos, int servo_pin, unsigned long interval, int oAngle, int cAngle,int pmin,int pmax, int duration, int close_delay,int l_s_pos);
    void init_servo();
    void servo_open();
    void servo_close();
    void set_indicator_light(Bitmask8 &out_bits);
    void clear_indicator_light(Bitmask8 &out_bits);
    int get_vib_sensor_value();
    void set_vib_sensor_thresh(int threshold);
    int get_light_sensor_value();
    int number_of_opens();
    void set_light_sensor_thresh(int threshold);
    void update(unsigned long currentMillis, Bitmask8 &output_bits, Bitmask16 &in_bits);
  private:
    Sweeper servo;               // the servo

    int led_position;
    int servo_open_duration;
    int servo_close_delay;
    int close_timer;
    int vib_count_threshold;
    int vib_count;
    int open_count;
    int light_sensor_pos;
    bool count_down_timer;
    bool sensorSeesBeam;
    unsigned long updateInterval;        // interval between updates
    unsigned long lastUpdate;  // last update of position
};
#endif
