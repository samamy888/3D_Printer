#ifndef SDCARD_H
#define SDCARD_H

#include "PinMode.h"

#define SetFileMax 20  //Max file

String Filelist[SetFileMax];
unsigned char FileMax=0;
void SD_Init(){

	if (!SD.begin()){
		return;
	}
 
 /*if(SD.exists("tmp.txt")) 
    SD.remove("tmp.txt");*/

  
 Serial.println("Sd is Begin");
 
 File SDjudge=SD.open("/");
	unsigned char a=0; 
	
	while(true){
	
	 File Entry=SDjudge.openNextFile();
		
		if(!Entry){
      Entry.close();
			break;
		}

		Filelist[a]=String(Entry.name());
		
		Serial.println(Filelist[a]);
		FileMax=a;
		a++;
	}

	SDjudge.close();

}

#endif

