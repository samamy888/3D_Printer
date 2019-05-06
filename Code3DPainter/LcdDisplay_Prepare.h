#ifndef LCDDISPLAY_PREPARE_H
#define LCDDISPLAY_PREPARE_H

#include "DoBackGround.h"

void Auto_home(){
  
    while(  interrupt_Z == false ){
      
          test_stepper(LOW,2,2); //下
          
          while( interrupt_Y == false  ){
            
                test_stepper(LOW,2,1); //後

                  while( interrupt_X == false  ){
                    
                       test_stepper(LOW,2,0); //左
                  }
          }
    }
    Serial.println("Done !");
     X_poistion = 0;
     Y_poistion = 0;
     Z_poistion = 0;     
     
     return;
}


void Prepare(){
   String title[]={
    "Menu",
    "Auto home",
    "",
    ""
  };  
  unsigned char work_num[]={
    1,12
  }; 
  Lcd_Menu_MOD(title,sizeof(work_num),work_num);   
  return;
}

#endif
