#ifndef DOBACKGROUND_H
#define DOBACKGROUND_H
#include "PinMode.h"

volatile boolean 
	interrupt_default = false,
	interrupt_X = false,
	interrupt_Y = false,
	interrupt_Z = false;

void X_Reject(){
  interrupt_X = true;
}	

void Y_Reject(){
	interrupt_Y = true;
}

void Z_Reject(){
	interrupt_Z = true;
}

void Interrupt_Init(){
	attachInterrupt( digitalPinToInterrupt( RejectionX ), X_Reject , CHANGE );
	attachInterrupt( digitalPinToInterrupt( RejectionY ), Y_Reject , CHANGE );
	attachInterrupt( digitalPinToInterrupt( RejectionZ ), Z_Reject , CHANGE );
}

void Interrupt_Display(){
 /* if( interrupt_Z == true || interrupt_Y == true || interrupt_X == true ||  digitalRead(LCD_BUTTON)==LOW){
    Lcd.clear();
  }
  while(interrupt_Z == true || interrupt_Y == true  || interrupt_X == true || digitalRead(LCD_BUTTON)==LOW){
    Lcd.setCursor(3,1);
    Lcd.print("Please Reset!!");
    if( digitalRead( LCD_KNOB ) == LOW ){
        interrupt_default = false,
        interrupt_X = false,
        interrupt_Y = false,
        interrupt_Z = false;
        digitalWrite( E_ENABLE_PIN , LOW);
        Lcd.clear();
        delay(200);
    }
  }
  */
}
#endif

