/*
  Rfid.cpp - Library to preform functions with the rfid module
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Rfid.h"

Rfid::Rfid(int pins[], String message,int starting_antenna):rfid(pins[0],pins[1]){
  msg = message;
  antenna = starting_antenna;
}
void Rfid::switch_to_antenna(int antenna_id){
  antenna = antenna_id;
}
bool Rfid::match(String input_string){
  return(msg == input_string);
}
void Rfid::update(unsigned long currentMillis){
  if((currentMillis - lastUpdate) > updateInterval)  // time to update
  {
    while(rfid.available() > 0){
      msg += char(rfid.read());
    }
  }
}
