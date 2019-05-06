#ifndef CHARTABLE_H
#define CHARTABLE_H

#include "Pin.h"

const uint8_t ch_thermometer[]=
{
	  B00100,
	  B01010,
	  B01010,
    B01010,
	  B01010,
	  B10001,
	  B10001,
	  B01110,
};

const uint8_t ch_clock[]=
{
    B00000,
	  B00000,
	  B01110,
	  B10101,
	  B10111,
	  B10001,
	  B01110,
	  B00000,
};

const uint8_t ch_direction[]=
{
    B00000,
	  B00000,
	  B00100,
	  B00010,
	  B11111,
	  B00010,
	  B00100,
	  B00000,
};

const uint8_t ch_return[]=
{
    B00000,
	  B00100,
	  B01110,
	  B11111,
	  B00100,
	  B00100,
	  B11100,
	  B00000,
};

void lcd_createChar(){
  
	Lcd.createChar( 0 , ch_thermometer );
	Lcd.createChar( 1 , ch_clock );
	Lcd.createChar( 2 , ch_direction );
	Lcd.createChar( 3 , ch_return );
  
}

#endif

