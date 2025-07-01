/*
	libdspmodgenproc.c
	Library: DSP
	Module: General Processing
	Authors: SchponzeePlusPlus (GH)
	Created On: 18/08/2024

	Description:
	NOTE: THIS FILE WAS INITIALLY DEVELOPED TO BE A C FILE (LIBRARY MODULE INTERFACE),
	DUE TO MANGLING IN THE ARDUINO IDE / GCC COMPILER, I WOULD HAVE TO ADD SOME EXTRA
	SYNTAX TO MAKE IT WORK PROPERLY.
	FOR NOW IT IS EASIER TO TREAT IT AS A C++ FILE.
*/

#include "Arduino.h"

#include "libdspmodgenproc.h"

//const int 

//	initialisation definitions, to run once:


//	calcs

//	Real-time inputs checks
bool chkDigSigEdgRisng(bool bo_digSigCurrSmpl, bool bo_digSigPrevSmpl)
{
	bool result = false;

	if (bo_digSigCurrSmpl && !(bo_digSigPrevSmpl))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool chkDigSigEdgFallng(bool bo_digSigCurrSmpl, bool bo_digSigPrevSmpl)
{
	bool result = false;

	if (!(bo_digSigCurrSmpl) && bo_digSigPrevSmpl)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool chkDigSigEdgNoChng(bool bo_digSigCurrSmpl, bool bo_digSigPrevSmpl)
{
	bool result = false;
	//	Check if current and previous input equal each-other
	//		regardless if signal is high or low
	if (bo_digSigCurrSmpl == bo_digSigPrevSmpl)
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}

// Latching, or exclusively checking, real-time input checks for processing

bool chkDigSigEdgRisngExclusvly(bool bo_chkdigSigEdgRisng, bool bo_chkdigSigEdgFallng, bool bo_chkdigSigEdgNoChng)
{
	bool result = false;
	//	Rising edge latch
	if ((bo_chkdigSigEdgRisng) && (!bo_chkdigSigEdgFallng) && (!bo_chkdigSigEdgNoChng))
	{
		result = true;
	}
	return result;
}

bool chkDigSigEdgFallngExclusvly(bool bo_chkdigSigEdgRisng, bool bo_chkdigSigEdgFallng, bool bo_chkdigSigEdgNoChng)
{
	bool result = false;
	// falling edge latch
	if ((!bo_chkdigSigEdgRisng) && (bo_chkdigSigEdgFallng) && (!bo_chkdigSigEdgNoChng))
	{
		result = true;
	}
	return result;
}

bool chkDigSigEdgNoChngExclusvly(bool bo_chkdigSigEdgRisng, bool bo_chkdigSigEdgFallng, bool bo_chkdigSigEdgNoChng)
{
	bool result = false;
	//	No Change latch
	//	Latch if signal pulse for current and previous sample
	if ((!bo_chkdigSigEdgRisng) && (!bo_chkdigSigEdgFallng) && (bo_chkdigSigEdgNoChng))
	{
		result = true;
	}
	return result;
}

bool latchDigSigPulsPerUndefnd(bool bo_chkDigSigEdgRisngExclusv, bool bo_chkDigSigEdgFallngExclusv, bool bo_chkDigSigEdgNoChngExclusv)
{
	bool result = false;
	//	Checks if a full pulse has been processed into memory
	if (bo_chkDigSigEdgRisngExclusv && bo_chkDigSigEdgFallngExclusv && bo_chkDigSigEdgNoChngExclusv)
	{
		result = true;	
	}
	return result;
}