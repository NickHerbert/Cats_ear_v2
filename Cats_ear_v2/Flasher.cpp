/*
  Flasher.cpp - Library to preform functions on an LED
  created by Nick Herbert
*/
#include "Arduino.h"
#include "Flasher.h"
Flasher::Flasher(){

}
Flasher::Flasher(int pin, long on, long off){
  ledPin = pin;
  pinMode(ledPin, OUTPUT);

  set_on_time(on);
  set_off_time(off);

  ledState = LOW;
  lastUpdate = 0;
}
void Flasher::set_on_time(long on){
  on_time = on;
}
void Flasher::set_off_time(long off){
  off_time = off;
}
void Flasher::update(unsigned long currentMillis){
  if((ledState == HIGH) && (currentMillis - lastUpdate >= on_time))
  {
    ledState = LOW;  // Turn it off
    lastUpdate = currentMillis;  // Remember the time
    digitalWrite(ledPin, ledState);  // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - lastUpdate >= off_time))
  {
    ledState = HIGH;  // turn it on
    lastUpdate = currentMillis;   // Remember the time
    digitalWrite(ledPin, ledState);	  // Update the actual LED
  }
}
