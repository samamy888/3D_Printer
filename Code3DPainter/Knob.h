#ifndef KNOB_H
#define KNOB_H
#include "PinMode.h"

unsigned char KeyScanner(unsigned char choose_max_val = 4 ,unsigned char choose_init_val = 0 ){

	volatile static boolean  n,encoderLast = LOW;//霈���������
	volatile unsigned char choose = choose_init_val ;
	n = digitalRead(LCD_TL);
	
	if( ( encoderLast == LOW) && (n == HIGH) ){
		if ( digitalRead(LCD_TR) == LOW) {
			choose--;
		}
		else{
			choose++;
		}
	}
	encoderLast = n; 
	if( choose > 250 )
		choose = 0 ; 
	else if( choose > choose_max_val)
		choose = choose_max_val ;
	return choose;
}

#endif

