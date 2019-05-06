#ifndef LCDDISPLAY_STEPPER_H
#define LCDDISPLAY_STEPPER_H

unsigned char Stepper_Set;
void Stepper_X_Set(){
   Stepper_Set = 1;
   String title[]={
    "Go Back(Now X)",
    "Moving_10mm",
    "Moving_1mm",
    "Moving_0.1mm",
  };
  
  unsigned char work_num[]={
    2,9,10,11
  };  
  Lcd_Menu_MOD(title,sizeof(work_num),work_num);   
  return;
}

void Stepper_Y_Set(){
   Stepper_Set=2;
   String title[]={
    "Go Back(Now Y)",
    "Moving_10mm",
    "Moving_1mm",
    "Moving_0.1mm",
  };
  
  unsigned char work_num[]={
    2,9,10,11
  };  
  Lcd_Menu_MOD(title,sizeof(work_num),work_num);   
  return;
}

void Stepper_Z_Set(){
   Stepper_Set = 3;
   String title[]={
    "Go Back(Now Z)",
    "Moving_10mm",
    "Moving_1mm",
    "Moving_0.1mm",
  };
  
  unsigned char work_num[]={
    2,9,10,11
  };  
  Lcd_Menu_MOD(title,sizeof(work_num),work_num);   
  return;
}

void Stepper_E_Set(){
     Stepper_Set = 4;
     String title[]={
            "Go Back(Now E)",
            "Moving_10mm",
            "Moving_1mm",
            "Moving_0.1mm",
    };  
    unsigned char work_num[]={
             2,9,10,11
    };  
    Lcd_Menu_MOD(title,sizeof(work_num),work_num);   
    return;
}

#endif
