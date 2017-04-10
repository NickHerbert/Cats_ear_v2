/*
  Feeder.cpp - Library for perfomring actions on a feeder module
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Feeder.h"

enum component_input_bits { EXTRA_P0 = 0,
                      EXTRA_P1 = 1,
                      EXTRA_P2 = 2,
                      EXTRA_P3 = 3,
                      VIB_P4 = 4,
                      LASER_P5 = 5,
                      LASER_P6 = 6,
                      VIB_P7 = 7,
};

enum component_output_bits { RED   = 8,
                            GREEN = 7,
                            BLUE  = 6,
                            EXTRA = 5,
                            LASER = 4,
                            LED = 3,
                            FEED2 = 2,
                            FEED1 = 1};

Feeder::Feeder(int led_pos, int servo_pin, unsigned long interval, int oAngle, int cAngle,int pmin,int pmax, int duration, int close_delay,int l_s_pos):servo(servo_pin,interval,oAngle,cAngle,pmin,pmax){
  updateInterval = interval;        // interval between updates
  servo_open_duration = duration;    //how long the servo will stay open
  servo_close_delay = close_delay;
  close_timer = close_delay * interval;
  vib_count = 0;
  vib_count_threshold = 2;
  open_count = 0;
  lastUpdate = 0;  // last update of position
  led_position = led_pos;
  light_sensor_pos = l_s_pos;
  count_down_timer = false;
  sensorSeesBeam = true;
}
void Feeder::init_servo(){
  servo.init_servo_position();
}
void Feeder::servo_open(){
  servo.set_state(OPENING);
  open_count++;
}
void Feeder::servo_close(){
  servo.set_state(CLOSING);
}
void Feeder::set_indicator_light(Bitmask8 &out_bits){
  out_bits.Set(led_position);
}
void Feeder::clear_indicator_light(Bitmask8 &out_bits){
  out_bits.Clear(led_position);
}
int Feeder::number_of_opens(){
  return open_count;
}

void Feeder::update(unsigned long currentMillis, Bitmask8 &output_bits, Bitmask16 &in_bits){

  if((currentMillis - lastUpdate) > updateInterval){  // time to update

    lastUpdate = currentMillis;

    if (sensorSeesBeam == true){
      if (!in_bits.IsSet(light_sensor_pos)){
        if(servo.get_state() == OPENED){

        }
        count_down_timer = false;
        sensorSeesBeam = false;
      }
    }
    else{
      if (in_bits.IsSet(light_sensor_pos)){
        if(servo.get_state()==OPENED){
          count_down_timer = true;
          close_timer = servo_close_delay*updateInterval;
        }
        sensorSeesBeam = true;
      }
    }
    if (count_down_timer == true){
      close_timer--;
    }
    if (close_timer <= 0){
      servo_close();
      count_down_timer = false;
    }

    servo.update(currentMillis);
  }




}
