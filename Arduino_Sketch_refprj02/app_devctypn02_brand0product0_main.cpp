/*
	app_devctypn02_brand0product0_main.c
	Program: (N/A) Arduino Control Program
	Main Source File for Application: <Device Type Name> (Example #02) (<Manufacturer Abbreviation><Product Abbreviation>) (Controller: Arduino Uno Rev. 3 , <Device Type Name>: <Manufacturer Name> <Product Name>)
	Authors: SchponzeePlusPlus (GH)
	Created On: 17/08/202x

	Description:
	... 
*/

//	NOTE: I DO NOT WANT THIS LIBRARY MODULE TO BE ARDUINO-C++ SPECIFIC!
#include "Arduino.h"

#include "app_devctypn02_brand0product0_main.h"

//const int PIN_NUM_XXX = A0;

//	initialisation definitions, to run once:
void initSysCtrllrOutDevcTypExESig(int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN)
{
	pinMode(int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN, OUTPUT);
	//	Initial state of output
	//	Thinking of creating an individual procedure for this but right now it works best here
	//	Active X output
	//	default output is Y
	digitalWrite(int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN, value);
}

//	Signal Title Example: U: (Signal Type Ex: R)
//	NOTE: Signal Type Ex: R Output requires pull-YYY resistor
void initSysCtrllrDInDevcManuProductEx02SigTitlExP(int int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP)
{
	pinMode(int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP, INPUT);
}

//	all initialisations
//	Todo: Consider putting pin configurations (e.g. INPUT, INPUT_PULLUP, OUTPUT, etc.) in a config file
void initSysCtrllrDevcTypExEAllIo
(
	int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN,
	int int_sysCtrllrDigHsOutPinNumDevcManuProductEx02SigTitlExS,
	int int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP,
	int int_sysCtrllrDinAlPinNumDevcManuProductEx02SigTitlExS,
	int int_sysCtrllrDigHsOutPinNumDevcManuProductEx02RqstSigTitlExT
)
{
	initSysCtrllrOutDevcTypExESig(int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN);

	//	Todo: wrap a certain output pin config in a function
	pinMode(int_sysCtrllrDigHsOutPinNumDevcManuProductEx02SigTitlExS, OUTPUT);
	digitalWrite(int_sysCtrllrDigHsOutPinNumDevcManuProductEx02SigTitlExS, value);

	initSysCtrllrDInDevcManuProductEx02SigTitlExP(int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP);

	//	Todo: wrap a certain input config in a function
	pinMode(int_sysCtrllrDinAlPinNumDevcManuProductEx02SigTitlExS, INPUT);
	//	Todo: wrap a certain input config in a function
	pinMode(int_sysCtrllrDigHsOutPinNumDevcManuProductEx02RqstSigTitlExT, INPUT);
}

//	boolean could be better renamed
void CmdSysCtrllrOutSigTitlExN
(
	bool bo_sysCtrllrOutCmdSigTitlExN,
	int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN
)
{
	//	active XX output
	digitalWrite(int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN, bo_sysCtrllrOutCmdSigTitlExN);
}

void CmdSysCtrllrOutDevcTypExEPuls(int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN)
{
	digitalWrite(int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN, false);
	//	rising edge
	digitalWrite(int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN, true);
	//	need to delay falling edge by specified period
	delay(5);
	//	falling edge
	digitalWrite(int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN, false);
}

bool readSysCtrllrDInDevcManuProductEx02SigTitlExP(int int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP)
{
	//	active XX input
	return (digitalRead(int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP));
}