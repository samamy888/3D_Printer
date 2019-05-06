#ifndef LCDDISPLAY_PRINTSET_H
#define LCDDISPLAY_PRINTSET_H

#include "PinMode.h"
#include "Buzzer.h"

String GFile;
double x_poistion = 90 , y_poistion = 90 , z_poistion = 0.3 , e_poistion = 0 , E_spd = 0;
unsigned int File_Column = 0,Tmpcnt = 0;
boolean Xd,Yd,Zd,Ed=true;

volatile boolean data_status, Initxy = false;
void Heat_Up(){
  while(bottom_val<bottom_temp_min && nozzle_val< nozzle_temp_min){
       Heat_bottomtemp();
       Heat_nozzletemp();
       Lcd_Display(5,1,0);
       Lcd_Display(6,1," " + String(Lcd_nozzletemp())  + "/" +  String(Lcd_bottomtemp()) );
  }
  digitalWrite(Fan,HIGH);
  return;
}
void draw(double *nu  ){  
  
  if( nu[0]==_null && nu[1] == _null && nu[2] == _null)  return;       
  double xl,yl,el,zl,Init_m,x_step,y_step,z_step=0.0002;     
  static int e_count = 0 ;
  if(Initxy ==false){
     x_poistion = nu[0] ;
     y_poistion = nu[1] ;
     z_poistion = nu[2] ;
     Initxy = true;
  }
  
  xl=fabs(nu[0]-x_poistion);
  yl=fabs(nu[1]-y_poistion);  
  zl=fabs(nu[2]-z_poistion); 
  el=fabs(nu[3]-e_poistion);    
  double es = 0;
  
  if(nu[0]-x_poistion>0){
     x_step = Mstep;
     Xd=false;
  }else{
     x_step = -Mstep;
     Xd=true;
  }
  if(nu[1]-y_poistion>0){
     y_step = Mstep;
     Yd=true;
  }else{
     y_step = -Mstep;
     Yd=false;
  }if(nu[2]-z_poistion>0){   
    z_step = z_step;
    Zd=true;
  }else{
    z_step = -z_step;
    Zd=false;
  }  
  
  Init_m =yl/xl;  
  E_spd=( (xl+yl)/el )/espd;    

    if(nu[3]!=_null)
     e_poistion=nu[3];
  while( (xl>Mstep && yl>Mstep) &&  ( nu[0]!=_null && nu[1] != _null) ){
      xl=fabs(nu[0]-x_poistion);
      yl=fabs(nu[1]-y_poistion);    
      if( (yl/xl) >= Init_m){
         y_poistion+=y_step; 
         test_stepper_v2('0',Yd);
      }else if( (yl/xl) < Init_m ){
         x_poistion+=x_step; 
          test_stepper_v2('1',Xd); 
      }
    if(nu[3]!=_null){
       es++;
       if(es>3){
          test_stepper_v2('3',Ed);
          es = 0 ; 
       }                 
    }
    xl=fabs(nu[0]-x_poistion);
    yl=fabs(nu[1]-y_poistion);     
  }      
  while( (yl>=Mstep && xl<Mstep) &&  ( nu[0]!=_null && nu[1] != _null) ){
 
     
      y_poistion+=y_step;
      yl=fabs(nu[1]-y_poistion);  
      test_stepper_v2('0',Yd);
    if(nu[3]!=_null){
       es++;
       if(es>3){
          test_stepper_v2('3',Ed);
          es = 0 ; 
       }                 
    }    
  }     
 while( (xl>=Mstep  &&  yl<Mstep) &&  ( nu[0]!=_null && nu[1] != _null) ){     
 //  Serial.println("5"); 
    x_poistion+=x_step;
    xl=fabs(nu[0]-x_poistion);
    test_stepper_v2('1',Xd);
    if(nu[3]!=_null){
       es++;
       if(es>4){
          test_stepper_v2('3',Ed);
          es = 0 ; 
       }                 
    }
  }
  
  while( zl>fabs(z_step) && nu[2]!=_null ){     
    //  Serial.println(String(z_poistion)+"0"+String(nu[0])); 
     z_poistion = z_poistion + z_step ;
     zl=fabs(nu[2]-z_poistion);    
     test_stepper_v2('2',Zd);       
  }
 
}


void G_Print(char *line) { 
    //14
  
    static long li=0;
    char nu[SI];
    char ch[]={88,89,90,69,70};
    double num[5];
    int a,b,c,d;    
    for(a=0;a<SI;a++)
        nu[a]='\0';    
    for(a=0;a<5;a++)
       num[a] = _null;
    
    for(a=0;line[a]!='\0';a++)
    {
      for(b=0;b<5;b++)
      {
        if(line[a]==ch[b])
        {
          for(c=a+1;line[c]!='\0' && line[c]!=' ';c++)
          {
            nu[c-a-1]=line[c];
        }       
        num[b]=atof(nu);        
        for(d=0;d<SI;d++)
              nu[d]='\0';
      }
    }
  }
  
  Serial.println(String(num[0])+"  "+String(num[1])+"  "+String(num[2])+"  "+String(num[3]));   
  draw(num);
  Lcd_Display(6,1," " + String(Lcd_bottomtemp()) + "/" + String(Lcd_nozzletemp()) );
  Lcd_Display(6,2,String(li));
 // Serial.println(li);
  li++;
 // Interrupt_Display();  
//  Heat_bottomtemp();
//  Heat_nozzletemp();
  
}

void Gcode_Print() { //13



//  Heat_Up();
   
  char data[SIZE],line[SIZE];
  int number;
  Serial.print(GFile);
  File Gcode_Prin = SD.open(GFile);
  while (Gcode_Prin.available()) {
    for (int a = 0; a < SIZE; a++)
      data[a] = '\0';
    number = 0 ;
    while (true) {
      data[number] = '\0';
      data[number] = Gcode_Prin.read();
      if (data[number] == '\n')
        break;
      else number++;
    }
    number = 0;
    while(number<SIZE){
          if(data[number]!='(' && data[number]!=';'&& data[number]!='M' && data[2]==' ' && (data[1]=='1' || data[1]=='0')){
             line[number]=data[number];
          }else{
               break;
          }
          number++;
    }
    while(number<5){
         line[number]='\0';
         number++;
    }
    if(line[0]!='\0'){
       G_Print(line);                                     
    }
  } 
  
  Serial.println("Done!");

  test_stepper(HIGH,16000,2);
  Play_Music();
  Gcode_Prin.close();
}

void PrintSet() {

  //String Filelist[FileMax];
  //unsigned char FileMax;
  String title[FileMax + 1];
  unsigned char work_num[FileMax + 1];
  title[0] = "Menu        ";
  work_num[0] = 1;
  for (int i = 1; i <= FileMax; i++) {
    title[i] = Filelist[i] + "   ";
    work_num[i] = 13;
  }
  if (FileMax > 0)
    Lcd_Menu_MOD(title, sizeof(work_num), work_num);
  else {
    delay(200);
    Lcd.clear();
    while ( digitalRead( LCD_KNOB ) == HIGH )
      Lcd_Display( 1 , 1 , "SD is not Ready !" );
  }
  return;
}

#endif
