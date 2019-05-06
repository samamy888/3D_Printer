#ifndef LCDDISPLAY_MAIN_H
#define LCDDISPLAY_MAIN_H

void Lcd_Menu_Main(){

  String title[]={
    "Main",
    "Stepper",
    "Prepare",
    "Print"
  };
  
  unsigned char work_num[]={
    0,2,3,4
  };
  
  Lcd_Menu_MOD(title,sizeof(work_num),work_num);
}

void Lcd_Menu_stepper(){

  String title[]={
    "Menu",
    "Set X  ",
    "Set Y  ",
    "Set Z  ",
    "Set E  "
  };
  
  unsigned char work_num[]={
    1,5,6,7,8
  };
  
  Lcd_Menu_MOD(title,sizeof(work_num),work_num);
}

void Lcd_Main(){
  
  Interrupt_Display();

  Lcd_Display(0,0,"X: " + String(X_poistion) + "." + X_Decimal + "mm" );
  Lcd_Display(11,0,0);
  Lcd_Display(12,0," " + String(Lcd_bottomtemp()) + "/" + String(Lcd_nozzletemp()) );
  Lcd_Display(0,1,"Y: " + String(Y_poistion) + "." + Y_Decimal + "mm" );
  Lcd_Display(11,1,1);
  Lcd_Display(12,1," :--:--");
  Lcd_Display(0,2,"Z: " + String(Z_poistion) + "." + Z_Decimal + "mm" );
  Lcd_Display(10,2," E: " + String(E_poistion) + "mm" );
  if( PrinterStatus == true ){
    Lcd_Display(0,3,"3D Printer is Running");
  }else{
    Lcd_Display(0,3,"3D Printer is Ready");
  }  
  if( digitalRead(LCD_KNOB) == LOW ){
    Work_Assign(1);
  }
  
}
#endif 
