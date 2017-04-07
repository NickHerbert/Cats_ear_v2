/*
  Flasher.cpp - Library to preform functions on an LED
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Flasher.h"
Flasher::Flasher(){

}
Flasher::Flasher(Bitmask8& o_bits, int pos, long on, long off){
  output_bits = o_bits;
  bit_pos = pos;
  set_on_time(on);
  set_off_time(off);

  output_bits.Set(bit_pos);
  lastUpdate = 0;
}
void Flasher::set_on_time(long on){
  on_time = on;
}
void Flasher::set_off_time(long off){
  off_time = off;
}
void Flasher::set_state(bool is_on){
  output_bits.SetOrClear(bit_pos,is_on);
}
void Flasher::update(unsigned long currentMillis){
  if((output_bits.IsSet(bit_pos)) && (currentMillis - lastUpdate >= on_time))
  {
    lastUpdate = currentMillis;  // Remember the time
    output_bits.Clear(bit_pos);
  }
  else if (!(output_bits.IsSet(bit_pos)) && (currentMillis - lastUpdate >= off_time))
  {
    lastUpdate = currentMillis;   // Remember the time
    output_bits.Set(bit_pos);
  }
}
