/*
	app_devctypn02_brand0product0_main.h
	Program: (N/A) Arduino Control Program
	Main Header File for Application: <Device Type Name> (Example #02) (<Manufacturer Abbreviation><Product Abbreviation>) (Controller: Arduino Uno Rev. 3 , <Device Type Name>: <Manufacturer Name> <Product Name>)
	Authors: SchponzeePlusPlus (GH)
	Created On: 17/08/202x

	Description:
	... 
*/

#ifndef INCLUDES_APP_DEVCTYPN02_BRAND0PRODUCT0_MAIN_H_
#define INCLUDES_APP_DEVCTYPN02_BRAND0PRODUCT0_MAIN_H_

// Call necessary modules/libraries via header files here
// Call hardware specific libraries here
//	NOTE: I DO NOT WANT THIS LIBRARY MODULE TO BE ARDUINO-C++ SPECIFIC!
#include "Arduino.h"

// Call component specific program modules
// Relevant modules are called in .cpp file

// Specify a namespace here
// No namespaces are specified in this file

// Declare class objects here
// No objects are created in this file

// Declare global constants here
// "Magic numbers" are assigned as global constants
//#define PIN_NUM_XXX A0
//	const int PIN_NUM_XXX = A8;

//	#define INT_PIN_NUM_DEVCTYPN02_OUT ((int) 3)

//	const float GLOBAL_CONST_EX01 = 0.0;

// Declare enumerators

// Declare a global constant

// Define records or structs

/**
	@brief 
*/
void initSysCtrllrOutDevcTypExESig(int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN);

/**
	@brief
	@param
	@return
*/
void initSysCtrllrDInDevcManuProductEx02SigTitlExP(int int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP);

void initSysCtrllrDevcTypExEAllIo
(
	int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN,
	int int_sysCtrllrDigHsOutPinNumDevcManuProductEx02SigTitlExS,
	int int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP,
	int int_sysCtrllrDinAlPinNumDevcManuProductEx02SigTitlExS,
	int int_sysCtrllrDigHsOutPinNumDevcManuProductEx02RqstSigTitlExT
);

void CmdSysCtrllrOutSigTitlExN(bool bo_sysCtrllrOutCmdSigTitlExN, int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN);

void CmdSysCtrllrOutDevcTypExEPuls(int int_sysCtrllrDOutPinNumDevcManuProductEx02SigTitlExN);

/**
	@brief
	@param
	@return	: Signal Title Example: W Signal.
		Signal is considered an active xxx.
*/
bool readSysCtrllrDInDevcManuProductEx02SigTitlExP(int int_sysCtrllrDInPinNumDevcManuProductEx02SigTitlExP);

#endif