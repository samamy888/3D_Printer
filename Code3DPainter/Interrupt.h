#ifndef INTERRUPT_H
#define INTERRUPT_H

#include"PinMode.h"
#include "DoBackGround.h"

#define maxdata 256
#define read_line_len 1000
#define aspd_len 10
#define aspd_step 3
#define spd_max 20
#define spd_min 50

long X_poistion = 50, X_Decimal = 0 ;
long Y_poistion = 50, Y_Decimal = 0 ;
long Z_poistion = 500, Z_Decimal = 0 ;
long E_poistion = 0, E_Decimal = 0 ;

const int myTOP = 6 ;

volatile unsigned char ncnt = 0 ;
volatile int delays[maxdata] ;
volatile int pin_step[maxdata] ;
volatile bool pin_dir[maxdata] ;

const int stepper_pin_v2[4] = {
  Y_STEP_PIN ,
  X_STEP_PIN ,
  Z_STEP_PIN ,
  E_STEP_PIN 
};

const int stepper_pin[4] = {
   Y_DIR_PIN   ,
   X_DIR_PIN   ,
   Z_DIR_PIN   ,
   E_DIR_PIN  
};

void set_stepper_init(){
  for(int i = 0 ; i < maxdata ; i++ ){
    delays[i]=0;
  }
}

void setMyTimerOne(){
  cli();
  TCCR1A = 0;
  TCCR1B = (1<<WGM12);  
  TCCR1B |= (1<<CS10) | (1<<CS11);
  
  OCR1A = myTOP;
  TCNT1=0;
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void test_stepper( bool Test_Dir , int Multiple, int pin){
  
  const unsigned int ms = 8 ; // max = de*10us min = max - Acc_step * ms
  static unsigned int de = 50 ;
  unsigned int tcnt = 0 ;
  
  while( tcnt <= Multiple ){
    if( delays[ ncnt ]== 0 ){
      if( tcnt > ( Multiple - Acc_step ) ){
        de += ms ;
      }else if( tcnt < Acc_step ){
        de -= ms ;
      }
      delays[ ncnt ] = de ;
      pin_step[ ncnt ] = pin ;
      pin_dir[ ncnt ] = Test_Dir ;
      ncnt++;
      tcnt++;
    }
  }
}

void test_stepper_v2( char data , bool sdir ){
  
  static unsigned char de_v2 = 50 ;
  
  while(true){
    if(delays[ncnt] == 0 ){
      pin_step[ ncnt ] = data - 48 ;
      pin_dir[ ncnt ] = sdir ;
      delays[ ncnt ] = de_v2 ; 
      ncnt++;
      break ;
  }
  }
}

void test_stepper_v2_isr(){
  
  static unsigned char mcnt = 0 ;
  static unsigned char cnt = 0 ;
  
  if( delays[mcnt] != 0 ){
    if( cnt == delays[mcnt] ){
      digitalWrite( stepper_pin[ pin_step[mcnt] ] , pin_dir[mcnt] ) ;
      digitalWrite( stepper_pin_v2[ pin_step[mcnt] ] , HIGH ) ;
      delays[mcnt] = cnt = 0 ;
      digitalWrite( stepper_pin_v2[ pin_step[mcnt] ] , LOW ) ;
      mcnt++;
    }else{
      cnt ++ ;
    }
  }else{
  cnt = 0 ;
  }
}

ISR(TIMER1_COMPA_vect){
  test_stepper_v2_isr(); 
}

#endif



