/*
	app_devctypn01_brand0product0_main.c
	Program: (N/A) Arduino Control Program
	Main Source File for Application: <Device Type Name> (Example #01) (<Manufacturer Abbreviation><Product Abbreviation>) (Controller: Arduino Uno Rev. 3 , <Device Type Name>: <Manufacturer Name> <Product Name>)
	Authors: SchponzeePlusPlus (GH)
	Created On: 18/08/2024

	Description:
	... 
*/

#include "Arduino.h"

#include "app_devctypn01_brand0product0_main.h"

//const int PIN_NUM_XX = A0;

//	initialisation definitions, to run once:
void initSysCtrllrDInDevcManuProductEx01DevcManuProductSigTitl(int int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl)
{
	pinMode(int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl, INPUT);
}

//	all initialisations
void initSysCtrllrPeriphrlIoDevcManuProductEx01(int int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl)
{
	initSysCtrllrDInDevcManuProductEx01DevcManuProductSigTitl(int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl);
}

bool readSysCtrllrDInDevcManuProductEx01DevcManuProductSigTitl(int int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl)
{
	//	active X input
	return (digitalRead(int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl));
}