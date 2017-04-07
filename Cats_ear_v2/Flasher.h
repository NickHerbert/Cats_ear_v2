/*
  Flasher.h - Library for performing functions on a led light
  Created By Nick Herbert
*/

#ifndef Flasher_h
#define Flasher_h

#include "Arduino.h"
#include "Bitmask.h"
class Flasher{
  public:
    Flasher();
    Flasher( int pos, long on, long off);
    void set_on_time(long on);
    void set_off_time(long off);
    void set_state(bool is_on);
    void update(unsigned long currentMillis);
  private:
  	// Class Member Variables
  	// These are initialized at startup
  	long on_time;     // milliseconds of on-time
  	long off_time;    // milliseconds of off-time

  	// These maintain the current state
  	bool ledState;             		// ledState used to set the LED
    int bit_pos;                //this is the position of the bit which controlls the led
  	unsigned long lastUpdate;  	// will store last time LED was updated
};
#endif
