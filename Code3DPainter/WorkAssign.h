#ifndef WORKASSIGN_H
#define WORKASSIGN_H
void Work_Assign(int item = 0){

  long bounce_time = 0 ;
  boolean bounce_knob_enable = false ;
  
  if(digitalRead(LCD_KNOB)==LOW){
    bounce_time = millis() + 200;
  }
  
  while(!bounce_knob_enable){
    if( millis()>= bounce_time ){
      bounce_knob_enable = true;
    }
  }
 
  Lcd.clear();  
  
  switch(item){
    
    case 0:         
            Lcd_Main();
            break ;           
    case 1:  
            Lcd_Menu_Main();
            break ;         
    case 2:
            Lcd_Menu_stepper();
            break ;
    case 3:
            Prepare();
            break ;
    case 4:
            PrintSet();
            break ;
    case 5:
            Stepper_X_Set();
            break ;
    case 6:
            Stepper_Y_Set();
            break ;
    case 7:
            Stepper_Z_Set();
            break ;
    case 8:
            Stepper_E_Set();
            break ;
     case 9:
            Moving_10mm();
            break ;
     case 10:
            Moving_1mm();
             break ;
     case 11:
            Moving_01mm();
            break ;
     case 12:
            Auto_home();
            break;
     case 13:
            Gcode_Print();
    default :
      break ;
  }
}

void Lcd_Menu_MOD(String * total_list,int count_value,unsigned char *assigner){

  Lcd.clear();
  
  long bounce_time = 0 ;
  boolean bounce_knob_enable = false ;
  unsigned char Choose = 0 ;
  boolean RunStatus = true ;
  unsigned char over_flow = 0 ;
  
  bounce_time=(digitalRead( LCD_KNOB ) == LOW)?(millis() + 200):0; // jump
  
  do{
    Interrupt_Display();
    
    if( millis() >= bounce_time ){
      bounce_knob_enable = true ;
    }
    
    if( bounce_knob_enable == true ){
      Choose = KeyScanner ( count_value - 1 , Choose ) ;
      
    }
    
    if( ( Choose - 4 ) >= over_flow ){
      over_flow = Choose - 3 ;
    }
    else if( Choose < over_flow ){
      over_flow = Choose ;
    }
    
    for(int a = 0 ; a < 4 ; a++ ){
      if( ( Choose - over_flow ) == a)
        Lcd_Display( 0 , Choose - over_flow , ">" );
      else
        Lcd_Display( 0 , a , " " );
        
      Lcd_Display( 1 , a, " " + total_list[ over_flow + a ] );
      
      if( over_flow == 0 && a == 0)
        Lcd_Display( 19 , 0 , 3 );
      else
        Lcd_Display( 19 , a , 2 );
    }
    
    if( digitalRead( LCD_KNOB ) == LOW ){
      RunStatus = false ;
      GFile = Filelist[Choose];
      Work_Assign( assigner[ Choose ] );
    }
    
  }while(RunStatus);
}

#endif
