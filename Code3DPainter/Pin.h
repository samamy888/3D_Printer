#ifndef PIN_H
#define PIN_H

#include <SPI.h>
#include <SD.h>
#include<LiquidCrystal.h>
LiquidCrystal Lcd(16,17,23,25,27,29);

  
//-----------------------------------------甇仿�脤收��雿�

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38 

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56 

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62 

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24 

//-----------------------------------------

#define SDCARDDETECT 49 //sd���
#define BEEPER 37 //��陷�

//-----------------------------------------��

#define LCD_TL  31
#define LCD_KNOB  35 
#define LCD_TR   33
#define LCD_BUTTON  41 

//-----------------------------------------

#define HeatHead 10 //����璉憯�
#define Fan  9  //��憸冽�憯�
#define HeatGround  8  //����摨憯�
#define RejectionX 3 //�����
#define RejectionY 18 //�����
#define RejectionZ 19 //�����
#define nozzle_pin 13 //�
#define bottom_pin 14 //摨�

//---------------------------------------頧��

#define SIZE 64
#define SI 16
#define spd 2
#define l 0.0125
#define ht 10000
#define acnt 4
#define _null -999 
#define t2d 20 

//-----------------------------------------

#define MenuMax 4
#define Stepper_Count_Max 4
#define Acc_step 5    //  80 = 1 mm     3200 = 1 circle
#define Mstep 0.0125
#define espd 7.66 //7.66

//-----------------------------------------皞怠漲��

#define bottom_temp_max 60 
#define bottom_temp_min 50
#define nozzle_temp_max 215
#define nozzle_temp_min 210

#endif

