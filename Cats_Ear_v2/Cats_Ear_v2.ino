#include <Arduino.h>

/*
Cats Ear Version 2

software for cat feeder hardware
Modules used
pcf8574n
74hc165
74hc595
Id3la
lcd
DPDT Relay


Nicholas Herbert
*/
#include <Feeder.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>

//required for ID3LA
SoftwareSerial rfid = SoftwareSerial(5, 6);
String rfid_msg;

//required for the pcf8574n
LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

//required for 74hc165n
const int clock_pin_165 = 12;
const int clockEnable_Pin_165 = 9;
const int load_pin_165 = 8;
const int data_pin_165 = 11;
const int led_pin = 13;
byte incoming_bytes_165;

//required for 74hc595
const byte latch_pin_595 =11;
const byte clock_pin_595 = 12;
const byte data_pin_595 = 8;


//required for Relay
const int relayTogglePin = 2;

enum feline{kaylee,minna};

struct stat{
  feline catName;
  String rfid;
  int opens;
  unsigned long canFeedFor;
};

struct stat Kaylee;
struct stat Minna;

class Feeder;




//LCD display helper function
int lcdOffsetByDigit(int opens);

//LCD display feeding info
void printFeedStat(int opens,int myCat);







Feeder feeder1(13,100,500,3,10,105,0);


void setup(){

  lcd.init();
  lcd.backlight();

  // Timer0 is already used for millis() - we'll just interrupt somewhere
  // in the middle and call the "Compare A" function below
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);



}

// Interrupt is called once a millisecond,
SIGNAL(TIMER0_COMPA_vect)
{
  unsigned long currentMillis = millis();
  feeder1.update(currentMillis);

}




void loop(){

}

//LCD display feeding info
void printFeedStat(int opens,int myCat){
  switch(myCat){
    case kaylee:
      lcd.setCursor(0, 0);
      lcd.print(opens,DEC);
      lcd.print("  <- Kaylee");
      break;
    case minna:
      lcd.setCursor(lcdOffsetByDigit(opens), 1);
      lcd.print("Minna ->  ");
      lcd.print(opens,DEC);
      break;
  }
}

//LCD display helper function
int lcdOffsetByDigit(int opens){
  int distance = 0;
  if(opens >= 0 && opens < 10){
     distance = 5;
  }
  else if(opens >= 10 && opens < 100){
    distance = 4;
  }
  else if(opens >= 100){
    distance = 3;
  }
  else{
     distance = 1;
  }
  return distance;
}
