#ifndef LCDDISPLAY_MOVING_H
#define LCDDISPLAY_MOVING_H

void Moving_10mm(){
  
     boolean RunStatus = true ;
     boolean Add_Moving = false;
     boolean De_Moving = false;
     unsigned int Moving_tmp , remainder , Moving_over = 0;
     int Multiple = 10;
     do{  
         Interrupt_Display();
         switch(Stepper_Set){
               case 1:
                      Moving_tmp = X_poistion / Multiple;
                      remainder  = X_poistion % Multiple;
                      break;
               case 2:
                      Moving_tmp = Y_poistion / Multiple;
                      remainder  = Y_poistion % Multiple;
                      break;
               case 3:
                      Moving_tmp = Z_poistion / Multiple;
                      remainder  = Z_poistion % Multiple;
                      break;
               case 4:
                      Moving_tmp = E_poistion / Multiple;
                      remainder  = E_poistion % Multiple;
                      break;
               default:
                      break;                      
         }        
         unsigned char Moving; 
         if(Moving_tmp<25){
            Moving = KeyScanner(25, Moving_tmp);
            if(Moving > Moving_tmp)
                Add_Moving = true;
            else if(Moving < Moving_tmp)
                De_Moving = true;
         }else {
            Moving_tmp = 25;
            Moving = KeyScanner(80, Moving_tmp+Moving_over);
            if(Moving > Moving_tmp+Moving_over){
                Add_Moving = true;
                Moving_over++;
            }
            else if(Moving < Moving_tmp+Moving_over){
                De_Moving = true;
                Moving_over--;
            }
         }

         switch(Stepper_Set){
              case 1:
                     X_poistion = Moving*Multiple+remainder;
                     Lcd_Display(2,1,  " X =      " + String(X_poistion) + "." + X_Decimal + "mm" );
                     
                     if(Add_Moving){
                        test_stepper(LOW,Multiple*80,Stepper_Set);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,Multiple*80,Stepper_Set);
                        De_Moving=false;
                     }
                     break;
              case 2:
                     Y_poistion = Moving*Multiple+remainder;
                     Lcd_Display(2,1,  " Y =      " + String(Y_poistion) + "." + Y_Decimal + "mm" );
                     if(Add_Moving){
                        test_stepper(LOW,Multiple*80,Stepper_Set-2);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,Multiple*80,Stepper_Set-2);
                        De_Moving=false;
                     }
                     break;
              case 3:
                     Z_poistion = Moving*Multiple+remainder;
                     Lcd_Display(2,1,  " Z =      " + String(Z_poistion) + "." + Z_Decimal + "mm" );
                     if(Add_Moving){
                        test_stepper(LOW,Multiple*80,Stepper_Set-1);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,Multiple*80,Stepper_Set-1);
                        De_Moving=false;
                     }  
                     break;
              case 4: 
                     E_poistion = Moving*Multiple+remainder;
                     Lcd_Display(2,1,  " E =      " + String(E_poistion) + "." + E_Decimal + "mm" );
                     
                     if(Add_Moving){
                        test_stepper(LOW,Multiple*80,Stepper_Set-1);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,Multiple*80,Stepper_Set-1);
                        De_Moving=false;
                     }                     
                     break;
              default:
                     break;

          }  
        
          if( digitalRead(LCD_KNOB) == LOW ){
              RunStatus=false;
          }                    
       }while(RunStatus);
       
       Lcd.clear();  

       Work_Assign(2);
            
       return;
}
void Moving_1mm(){
     boolean RunStatus = true ;
     boolean Add_Moving = false;
     boolean De_Moving = false;
     unsigned int Moving_tmp ;
     int Multiple = 1;
     do{  
         Interrupt_Display();
         switch(Stepper_Set){
               case 1:
                      Moving_tmp = X_poistion ;
                      break;
               case 2:
                      Moving_tmp = Y_poistion ;
                      break;
               case 3:
                      Moving_tmp = Z_poistion ;
                      break;
               case 4:
                      Moving_tmp = E_poistion ;
                      break;
               default:
                      break;                      
         }         
         unsigned char Moving = KeyScanner(150, Moving_tmp);
         if(Moving > Moving_tmp)
            Add_Moving = true;
         else if(Moving < Moving_tmp)
            De_Moving = true;
         switch(Stepper_Set){
              case 1:
                     X_poistion = Moving ;
                     Lcd_Display(2,1,  " X =      " + String(X_poistion) + "." + X_Decimal + "mm" );
                     if(Add_Moving){
                        
                        test_stepper(LOW,80,Stepper_Set);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        
                        test_stepper(HIGH,80,Stepper_Set);                 
                        De_Moving=false;
                     }
                     break;
              case 2:
                     Y_poistion = Moving;
                     Lcd_Display(2,1,  " Y =      " + String(Y_poistion) + "." + Y_Decimal + "mm" );
                     if(Add_Moving){
                        test_stepper(LOW,80,Stepper_Set-2);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,80,Stepper_Set-2);
                        De_Moving=false;
                     }
                     break;
              case 3:
                     Z_poistion = Moving ;
                     Lcd_Display(2,1,  " Z =      " + String(Z_poistion) + "." + Z_Decimal + "mm" );
                     if(Add_Moving){
                        test_stepper(LOW,80,Stepper_Set-1);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,80,Stepper_Set-1);
                        De_Moving=false;
                     }  
                     break;
              case 4: 
                     E_poistion = Moving ;
                     Lcd_Display(2,1,  " E =      " + String(E_poistion) + "." + E_Decimal + "mm" );                     
                     if(Add_Moving){
                        test_stepper(LOW,80,Stepper_Set-1);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,80,Stepper_Set-1);
                        De_Moving=false;
                     }                     
                     break;
              default:
                     break;

          }  
        
          if( digitalRead(LCD_KNOB) == LOW ){
              RunStatus=false;
          }                    
       }while(RunStatus);
       
       Lcd.clear();  

       Work_Assign(2);
    
       return;
}
void Moving_01mm(){
     boolean RunStatus = true ;
     boolean Add_Moving = false;
     boolean De_Moving = false;
     unsigned int Moving_tmp;
     unsigned int Multiple=1;
     do{  
         Interrupt_Display();
         switch(Stepper_Set){
               case 1:
                      Moving_tmp = X_Decimal;
                      break;
               case 2:
                      Moving_tmp = Y_Decimal;
                      break;
               case 3:
                      Moving_tmp = Z_Decimal;
                      break;
               case 4:
                      Moving_tmp = E_Decimal;
                      break;
               default:
                      break;                      
         }
         unsigned char Moving = KeyScanner(255, Moving_tmp);
         //Serial.println(String(Moving_tmp_Over) +" "+String(Moving_tmp)+" "+String(X_poistion));  
         if(Moving > Moving_tmp)
            Add_Moving = true;
         else if(Moving < Moving_tmp)
            De_Moving = true;
         switch(Stepper_Set){
              case 1:                                             
                     X_Decimal = Moving%10;
                     X_poistion += Moving/10;                    
                     Lcd_Display(2,1,  " X =      " + String(X_poistion) + "." + X_Decimal + "mm" );
                     if(Add_Moving){
                        test_stepper(LOW,8,Stepper_Set);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,8,Stepper_Set);
                        De_Moving=false;
                     }
                     break;
              case 2:
                     Y_Decimal = Moving%10;
                     Y_poistion += Moving/10;  
                     Lcd_Display(2,1,  " Y =      " + String(Y_poistion) + "." + Y_Decimal + "mm" );
                     if(Add_Moving){
                        test_stepper(LOW,8,Stepper_Set-2);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,8,Stepper_Set-2);
                        De_Moving=false;
                     }
                     break;
              case 3:
                     Z_Decimal = Moving%10;
                     Z_poistion += Moving/10;  
                     Lcd_Display(2,1,  " Z =      " + String(Z_poistion) + "." + Z_Decimal + "mm" );
                     if(Add_Moving){
                        test_stepper(LOW,8,Stepper_Set-1);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,8,Stepper_Set-1);
                        De_Moving=false;
                     }  
                     break;
              case 4: 
                     E_Decimal = Moving%10;
                     E_poistion += Moving/10;  
                     Lcd_Display(2,1,  " E =      " + String(E_poistion) + "." + E_Decimal + "mm" );
                     
                     if(Add_Moving){
                        test_stepper(LOW,8,Stepper_Set-1);
                        Add_Moving=false;
                     }
                     if(De_Moving){
                        test_stepper(HIGH,8,Stepper_Set-1);
                        De_Moving=false;
                     }                     
                     break;
              default:
                     break;

          }  
        
          if( digitalRead(LCD_KNOB) == LOW ){
              RunStatus=false;
          }                    
       }while(RunStatus);
       
       Lcd.clear();  

       Work_Assign(2);
  
 
       return;
}


#endif
