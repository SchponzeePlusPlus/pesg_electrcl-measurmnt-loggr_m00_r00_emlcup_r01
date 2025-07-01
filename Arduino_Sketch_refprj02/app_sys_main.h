/*
	app_sys_main.h
	Program: (N/A) Arduino Control Program
	Main Header File for Application: <Device Type Name> (Example #02) (<Manufacturer Abbreviation><Product Abbreviation>) (Controller: Arduino Uno Rev. 3 , <Device Type Name>: <Manufacturer Name> <Product Name>)
	Authors: SchponzeePlusPlus (GH)
	Created On: 17/08/202x

	Description:
	... 
*/

#ifndef INCLUDES_APP_SYS_MAIN_H_
#define INCLUDES_APP_SYS_MAIN_H_

// Call necessary modules/libraries via header files here
// Call hardware specific libraries here
#include "Arduino.h"

// Pre-Processor Macros
// Pre-Processor Macro Constants Here

#define U8_C_PREPROC_MCRO_CONST_EX01 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX02 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX03 ((uint8_t) 0U)

#define U8_C_PREPROC_MCRO_CONST_EX04 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX05 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX06 ((uint8_t) 0U)

#define U8_C_PREPROC_MCRO_CONST_EX07 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX08 ((uint8_t) 0U)
#define U8_C_PREPROC_MCRO_CONST_EX09 ((uint8_t) 0U)


// Call component specific program modules
// Relevant modules are called in .cpp file

// Specify a namespace here
// No namespaces are specified in this file

// Declare class objects here
// No objects are created in this file

// Declare global constants here
// "Magic numbers" are assigned as global constants

//	Arduino Pin Numbers
const int INT_PIN_NUM_DEVCTYPN01_IN = 2;
const int INT_PIN_NUM_DEVCTYPN02_OUT = 3;
//	note: pin number not finalised yet
const int INT_SYSCTRLLR_DINPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX02 = 4;
//	Todo: Finalise pin
const int INT_SYSCTRLLR_DINPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX03 = 5;
//	Todo: finaluse pin
const int INT_SYSCTRLLR_DINPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX04 = 6;
//	Todo: finalise pin
const int INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX05 = 7;
//	note: pin number not finalised yet
const int INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX03_DEVCSIGTITLEX01 = 8;
//	Todo: finalise pin
const int INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01 = 9;
//	Todo: finalise pin
const int INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX02 = 11;
const int INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX03 = 10;

// Declare enumerators

enum enm_ssiSubSysXCtrlState
{
	SSISSXC_STATE_UNASSIGNED,
	SSISSXC_STATE_NULL,
	SSISSXC_STATE_READY,
	SSISSXC_STATE_RQSTCMDAPPRVD,
	SSISSXC_STATE_CMDNG,
	SSISSXC_STATE_CMDNGERR,
	SSISSXC_STATE_CMDCOMPSUCC
};

enum enm_ssiPeriphrlXFdbkState
{
	SSIPXF_STATE_UNASSIGNED,
	SSIPXF_STATE_NULL,
	SSIPXF_STATE_SUBSYSOP_STATE01,
	SSIPXF_STATE_SUBSYSOP_STATE02,
	SSIPXF_STATE_SUBSYSOP_STATE03,
	SSIPXF_STATE_SUBSYSOP_MISC
};

// Declare a global constant

// Define records or structs

uint8_t u8_incrmntValWRollovr(uint8_t u8_val);

/**
	@brief 
*/
void initSysCtrllr();

/**
	@brief
	@param
	@return
*/
int execSysCtrllrRunTimeMain();

#endif