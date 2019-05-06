#ifndef LCDDISPLAY_H
#define LCDDISPLAY_H

#include "WorkAssign_Init.h"
#include "LcdDisplay_stepper.h"
#include "LcdDisplay_Moving.h"
#include "LcdDisplay_Prepare.h"
#include "LcdDisplay_PrintSet.h"
#include "LcdDisplay_Main.h"
#include "WorkAssign.h"
#include "BlueTooth.h"

void Lcd_Init(){
  Serial.begin(9600);
  Lcd.begin(20,4);
}

#endif


