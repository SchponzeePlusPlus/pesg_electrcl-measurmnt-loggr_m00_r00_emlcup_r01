/*
	libdspmodgenproc.h
	Library: DSP
	Module: General Processing
	Authors: SchponzeePlusPlus (GH)
	Created On: 18/08/2024

	Description:
	... 
*/

#ifndef INCLUDES_LIBDSPMODGENPROC_H_
#define INCLUDES_LIBDSPMODGENPROC_H_

// Call necessary modules/libraries via header files here

#include "Arduino.h"

// Call component specific program modules
// Relevant modules are called in .cpp file

// Specify a namespace here
// No namespaces are specified in this file

// Declare class objects here
// No objects are created in this file

// Declare enumerators here

// Declare global constants here
// "Magic numbers" are assigned as global constants
//	const float GLOBAL_CONST_EX01 = 0.0;

// Define records or structs


/**
	@brief 
*/
bool chkDigSigEdgRisng(bool bo_digSigCurrSmpl, bool bo_digSigPrevSmpl);

/**
	@brief
	@param
	@return
*/

bool chkDigSigEdgFallng(bool bo_digSigCurrSmpl, bool bo_digSigPrevSmpl);

bool chkDigSigEdgNoChng(bool bo_digSigCurrSmpl, bool bo_digSigPrevSmpl);

bool chkDigSigEdgRisngExclusvly(bool bo_chkdigSigEdgRisng, bool bo_chkdigSigEdgFallng, bool bo_chkdigSigEdgNoChng);

bool chkDigSigEdgFallngExclusvly(bool bo_chkdigSigEdgRisng, bool bo_chkdigSigEdgFallng, bool bo_chkdigSigEdgNoChng);

bool chkDigSigEdgNoChngExclusvly(bool bo_chkdigSigEdgRisng, bool bo_chkdigSigEdgFallng, bool bo_chkdigSigEdgNoChng);

bool latchDigSigPulsPerUndefnd(bool bo_chkDigSigEdgRisngExclusv, bool bo_chkDigSigEdgFallngExclusv, bool bo_chkDigSigEdgNoChngExclusv);

#endif