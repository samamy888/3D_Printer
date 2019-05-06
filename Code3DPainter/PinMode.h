#ifndef PINMODE_H
#define PINMODE_H

#include"Pin.h"

void PinMode_Init(){
	pinMode(X_STEP_PIN		, OUTPUT);
	pinMode(X_DIR_PIN		, OUTPUT);
	pinMode(X_ENABLE_PIN	, OUTPUT);

	pinMode(Y_STEP_PIN		, OUTPUT);
	pinMode(Y_DIR_PIN		, OUTPUT);
	pinMode(Y_ENABLE_PIN	, OUTPUT);

	pinMode(Z_STEP_PIN		, OUTPUT);
	pinMode(Z_DIR_PIN		, OUTPUT);
	pinMode(Z_ENABLE_PIN	, OUTPUT);

	pinMode(E_STEP_PIN		, OUTPUT);
	pinMode(E_DIR_PIN		, OUTPUT);
	pinMode(E_ENABLE_PIN	, OUTPUT);

	pinMode(HeatHead		, OUTPUT);
	pinMode(Fan				, OUTPUT);
	pinMode(HeatGround		, OUTPUT);

	pinMode(LCD_KNOB		,INPUT_PULLUP);
	pinMode(LCD_TL			,INPUT_PULLUP);
	pinMode(LCD_TR			,INPUT_PULLUP);
	pinMode(LCD_BUTTON		,INPUT_PULLUP);//black
  
	pinMode(RejectionX		,INPUT_PULLUP);
	pinMode(RejectionY		,INPUT_PULLUP); //������
	pinMode(RejectionZ		,INPUT_PULLUP); //������

	pinMode(nozzle_pin		, INPUT);
	pinMode(bottom_pin		, INPUT);

	digitalWrite(X_ENABLE_PIN    , LOW);
	digitalWrite(Y_ENABLE_PIN    , LOW);
	digitalWrite(Z_ENABLE_PIN    , LOW);
	digitalWrite(E_ENABLE_PIN    , LOW);
}

#endif

