#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <SoftwareSerial.h>
#include "Pin.h"

#define MAX_BT_buf 64

char* BT_buf;
int BT_pos;

//SoftwareSerial BT(40, 42);

void resetData(){
   for (int i=0; i<=BT_pos; i++) BT_buf[i] = 0; 
   BT_pos = 0;
}

void BT_init(){
	Serial1.begin(9600);	
	BT_buf = new char[ MAX_BT_buf ] ;
  if(SD.exists("BT.txt"))
     SD.remove("BT.txt");
}

char* BT_read(){

	char mdata ;
	static boolean receiving = false ,DoR = false,DoP = false;

	
	if( Serial1.available() ){
    File BTSD = SD.open ("BT.txt", FILE_WRITE);
		mdata = Serial1.read() ;
		switch(mdata) {
			//3: End of transmission
			case 3 : 
				receiving = false;  
				Serial.print(BT_buf);
         BTSD.print(BT_buf);
         
				break ; //end message
			case 4 :
				receiving = false ;
				Serial1.write('a') ;
				break ;
			default : 
				if( receiving == false){
					resetData() ;
				}
				BT_buf[BT_pos] = mdata ;
				BT_pos++ ;
				receiving = true ;
		}
    BTSD.close();
	}
 

  if(digitalRead(LCD_KNOB) == LOW){
    File BT_SD = SD.open ("BT.txt");  
    char data[SIZE],line[SIZE];
    int number;

    while (BT_SD.available()) {
        for (int a = 0; a < SIZE; a++)
            data[a] = '\0';
            number = 0 ;
        while (true) {
           data[number] = '\0';
           data[number] = BT_SD.read();
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
     //  Serial.print(line);
       G_Print(line);                                  
    }
  } 
  
  Serial.println("Done!");
  }
}

#endif
