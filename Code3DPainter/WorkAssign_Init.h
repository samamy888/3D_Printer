#ifndef WORKASSIGN_INIT_H
#define WORKASSIGN_INIT_H

#include "Knob.h"
#include "Temperature.h"
#include "Sdcard.h"
#include "DoBackGround.h"
#include "CharTable.h"
#include "Interrupt.h"
/*
0	 Main
1	 Menu
2	 Stepper
3	 SD
4	 Print
5	 Stepper - Set X
6	 Stepper - Set Y
7	 Stepper - Set Z
8	 Stepper - Set E
9  Moving_10mm
10 Moving_1mm
11 Moving_0.1mm
12
*/
void Work_Assign(int item);
void Lcd_Menu_MOD(String * total_list,int count_value,unsigned char *assigner);

boolean PrinterStatus=LOW;
String StrTmp;
void Lcd_Display( unsigned char x, unsigned char y,String s){
  Lcd.setCursor(x,y);
  Lcd.print(s);
}

void Lcd_Display( unsigned char x, unsigned char y,char ch){
  Lcd.setCursor(x,y);
  Lcd.write(uint8_t(ch));
}


#endif

