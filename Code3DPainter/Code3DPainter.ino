#include "Sdcard.h"
#include "LcdDisplay.h"

void setup(){
  set_stepper_init();
	PinMode_Init();
	Lcd_Init();    
  Interrupt_Init();
  lcd_createChar();
	SD_Init();
  setMyTimerOne();
   BT_init();
}

void loop(){ 
	  Lcd_Main();    
//   BT_read();
}



