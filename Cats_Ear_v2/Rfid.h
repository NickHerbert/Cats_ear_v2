/*
  Sweeper.h - Library to preform functions on a servo
  created by Nick Herbert
*/
#ifndef Rfid_h
#define Rfid_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class Rfid{
  public:
    Rfid(int pins[],String message, int starting_antenna);
    void switch_to_antenna(int antenna_id);
    bool match(String input_string);
    void update(unsigned long currentMillis);
  private:
    SoftwareSerial rfid;
    String msg;
    int antenna;
    unsigned long updateInterval;
    unsigned long lastUpdate;     // last update of read

};
#endif
