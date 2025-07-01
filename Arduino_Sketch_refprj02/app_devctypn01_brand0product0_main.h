/*
	app_devctypn01_brand0product0_main.h
	Program: (N/A) Arduino Control Program
	Main Source File for Application: <Device Type Name> (Example #01) (<Manufacturer Abbreviation><Product Abbreviation>) (Controller: Arduino Uno Rev. 3 , <Device Type Name>: <Manufacturer Name> <Product Name>)
	Authors: SchponzeePlusPlus (GH)
	Created On: 18/08/2024

	Description:
	... 
*/

#ifndef INCLUDES_APP_DEVCTYPN01_BRAND0PRODUCT0_MAIN_H_
#define INCLUDES_APP_DEVCTYPN01_BRAND0PRODUCT0_MAIN_H_

// Call necessary modules/libraries via header files here
// Call hardware specific libraries here
#include "Arduino.h"

// Call component specific program modules
// Relevant modules are called in .cpp file

// Specify a namespace here
// No namespaces are specified in this file

// Declare class objects here
// No objects are created in this file

// Declare Pre-Processor Macro Constants Here:
//	Arduino Pin Numbers
//#define PIN_NUM_XXX A0

//	#define INT_PIN_NUM_DEVCTYPN01_IN ((int) 2)

// Declare enumerators

// Declare global constants here
// "Magic numbers" are assigned as global constants
//	const int PIN_NUM_XXX = A8;

//	const float GLOBAL_CONST_EX01 = 0.0;

// Define records or structs


/**
	@brief 
*/
void initSysCtrllrDInDevcManuProductEx01DevcManuProductSigTitl(int int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl);

/**
	@brief
	@param
	@return
*/

void initSysCtrllrPeriphrlIoDevcManuProductEx01(int int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl);

bool readSysCtrllrDInDevcManuProductEx01DevcManuProductSigTitl(int int_sysCtrllrDInPinNumDevcManuProductEx01DevcManuProductSigTitl);

#endif