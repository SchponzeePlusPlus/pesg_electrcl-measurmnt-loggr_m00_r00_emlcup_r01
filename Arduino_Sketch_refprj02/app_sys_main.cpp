/*
	app_devctypn02_brand0product0_main.c
	Program: (N/A) Arduino Control Program
	Main Source File for Application: <Device Type Name> (Example #02) (<Manufacturer Abbreviation><Product Abbreviation>) (Controller: Arduino Uno Rev. 3 , <Device Type Name>: <Manufacturer Name> <Product Name>)
	Authors: SchponzeePlusPlus (GH)
	Created On: 17/08/202x

	Description:
	... 
*/

#include "Arduino.h"

#include <EEPROM.h>

#include "app_sys_main.h"

#include "libdspmodgenproc.h"

#include "app_devctypn01_brand0product0_main.h"
#include "app_devctypn02_brand0product0_main.h"

//const int PIN_NUM_XXX = A0;

uint8_t u8_incrmntValWRollovr(uint8_t u8_val)
{
	uint8_t result = 0;
	if (u8_val < 255)
	{
		result = u8_val + 1;
	}
	else
	{
		result = 0;
	}
	return result;
}

/**
 * @brief 
 * 
 * Function Imported here from reference project #2's WIP feature branch for considering non-volatile memory usage for calculations
 * 
 * @param u32_val 
 * @return uint8_t 
 */
uint8_t u32_incrmntValWRollovr(uint32_t u32_val)
{
	uint8_t result = 0;
	if (u32_val < 4294967295)
	{
		result = u32_val + 1;
	}
	else
	{
		result = 0;
	}
	return result;
}

/**
 * @brief 
 * 
 * Function Imported here from reference project #2's WIP feature branch for considering non-volatile memory usage for calculations
 * 
 * @param u32_val 
 * @return uint8_t 
 */
uint32_t u32_Add002ValsWOvrflwDetectn(uint32_t u32_valA, uint32_t u32_valB)
{
	uint32_t u32_largerMagnitudeParamVal = 0; //... WIP, selecting greater param value to help with roll over?
	uint32_t result = 0;


	//	https://www.reddit.com/r/cpp_questions/comments/4zym2x/how_to_check_for_overflowunderflow_in_c/
	if (u32_valA < (4294967295 - u32_valB))
	{
		result = u32_valA + u32_valB;
	}
	else
	{
		result = u32_valB; // needs work
	}
	return result;
}

//	initialisation definitions, to run once:

//	all initialisations
void initSysCtrllr()
{
	//	Open serial port and set a baud rate (data rate) to allow for text based output to a connected computer
	Serial.begin(9600);
	//	Wait for up to ~1000 milliseconds for Serial to connect
	int setup_serial_cnt = 1000;     // 
	while (!Serial && setup_serial_cnt > 0)
	{
		delay(1);
		setup_serial_cnt--;
	}

	/**
	 * Here I would call some procedures to setup / configure / iniialise I/O pins, configure them as input or outputs, maybe call procedures to command outputs to default values.
	 * 
	 * Ideally in this reference project I was attempting to move the Arduino setup / configuration / iniialisation statements to module files specific to the peripheral or sub-system, instead of doing it here. Sometimes it was easier to do pinMode() and digitalWrite() here for a quick solution.
	 * 
	 */

	initSysCtrllrPeriphrlIoDevcManuProductEx01(INT_PIN_NUM_DEVCTYPN01_IN);
	initSysCtrllrDevcTypExEAllIo(INT_PIN_NUM_DEVCTYPN02_OUT, INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX05,
		INT_SYSCTRLLR_DINPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX02, INT_SYSCTRLLR_DINPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX03, INT_SYSCTRLLR_DINPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX04);

	// more init / config / setup procedure calls were here

	pinMode(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX03_DEVCSIGTITLEX01, OUTPUT);
	digitalWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX03_DEVCSIGTITLEX01, false);

	pinMode(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, OUTPUT);
	digitalWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, true);
	
	pinMode(LED_BUILTIN, OUTPUT);

	digitalWrite(LED_BUILTIN, false);
	if(Serial)
	{
		delay(1000);
		Serial.println("Program set-up complete");
		delay(1000);
	}
}

// run-time

int execSysCtrllrRunTimeMain()
{
	/**
	 * Declare variables for the run-time (super-loop) here.
	 * 
	 * Generally declare variables for raw Inputs, then any processing / controlling / calculating variables, and then for raw outputs.
	 */
	
	// 
	// Raw input
	bool
		//	Current sample / value of raw input here
		bo_devcTypExKCtrllrInChkEnRaw = true,
		//	Previous sample / value of raw input here
		bo_devcTypExKCtrllrInChkEnRawPrev = true
	;

	// Input Raw Signal Processing here
	//	Input Raw Signal Edge Detection
	bool
		//	Raw input rising edge check
		bo_devcTypExIInProcChkEnRawRisngEdg = false,
		//	Raw input falling edge check
		bo_devcTypExIInProcChkEnRawFallngEdg = false,
		//	Raw input neither rising or falling edge check
		bo_devcTypExIInProcChkEnRawNoChng = false
	;

	//	Input Signal Edge Detection Latching
	bool
		bo_devcTypExIInProcChkEnRawRisngEdgLtchd = false,
		bo_devcTypExIInProcChkEnRawFallngEdgLtchd = false,
		bo_devcTypExIInProcChkEnRawNoChngLtchd = false;

	//	More Input Processing here

	/**
	 * The reference program implemented counters. They were once declared here.
	 * 
	 * These counters were compared to each other to ensure operation was synchronised.
	 * 
	 */

	// Declare variables for request, request approval conditions, request approved, etc.	
	bool
		bo_ssiSubSysExOCtrlRqstSigTitlExH = false,
		//	Note: is bo_ssiSubSysExOCtrlRqstChkDevcTypExEApprvlConds a better name ?
		bo_ssiSubSysExOCtrlRqstSigTitlExHApprvlConds = false,
		bo_ssiSubSysExOCtrlRqstSigTitlExHApprvd = false;
	
	//	Declare Control flags for when the system should do something
	// Declare command flags, for out. processed and raw outputs here

	// Sub-system control / output state variable declaration here
	enm_ssiSubSysXCtrlState enmSSISSXCS_ssiSubSysEx02CtrlState = SSISSXC_STATE_UNASSIGNED;

	// Declare state (enum) variables, assign them unassigned values to start off with
	// Sub-system control state variable declaration here
	enm_ssiPeriphrlXFdbkState enmSSIPXFS_ssiPeriphrlXFdbkState = SSIPXF_STATE_UNASSIGNED;

	bool bo_ssiSubSysExVCtrlRqstSigTitlExB = false;

	// Todo: formalise name
	//bool bo_DevcTypExEIssueCmdEn = false;
	// Todo: formalise name
	//bool bo_DevcTypEx82IssueCmdEn = false;

	// The lines below this line here were imported from reference project #2's WIP feature branch for considering non-volatile memory usage for calculations
	// ---------------------------------------
	uint32_t u32_prjCtrllrAppsRunTmeTickRteCntr_ms = 0;

	uint32_t u32_prjCtrllrAppsTickPerNvmSave_ms = 60000;

	uint32_t u32_prjCtrllrAppsRunTmeTickRteCntrNvmSaveEventNext_ms = 0;
	// ---------------------------------------
	// The lines above this line here were imported from reference project #2's WIP feature branch for considering non-volatile memory usage for calculations

	if(Serial)
	{
		delay(1000);
		Serial.println("Declared variables at start of super-loop...");
		delay(1000);
	}

	enmSSISSXCS_ssiSubSysEx02CtrlState = SSISSXC_STATE_READY;

	//	only want to declare variables once before the functional super-loop
	//	Ideally, program will not exit this for(;;){} loop
	for(;;)
	{
		if(Serial)
		{
			delay(5);
			Serial.println("Beginning of forever super-loop...");
			delay(5);
		}

		//	ensure a certain output is in default state when it is not being commanded to pulse
		CmdSysCtrllrOutSigTitlExN(false, INT_PIN_NUM_DEVCTYPN02_OUT);

		// Read raw inputs here

		bo_devcTypExKCtrllrInChkEnRaw = readSysCtrllrDInDevcManuProductEx01DevcManuProductSigTitl(INT_PIN_NUM_DEVCTYPN01_IN);

		//	Real-time inputs checks
		bo_devcTypExIInProcChkEnRawFallngEdg = chkDigSigEdgFallng(bo_devcTypExKCtrllrInChkEnRaw, bo_devcTypExKCtrllrInChkEnRawPrev);
		bo_devcTypExIInProcChkEnRawRisngEdg = chkDigSigEdgRisng(bo_devcTypExKCtrllrInChkEnRaw, bo_devcTypExKCtrllrInChkEnRawPrev);
		
		//	Check if current and previous input equal each-other
		//		regardless if signal is high or low
		bo_devcTypExIInProcChkEnRawNoChng = chkDigSigEdgNoChng(bo_devcTypExKCtrllrInChkEnRaw, bo_devcTypExKCtrllrInChkEnRawPrev);

		//	Latching real-time input checks for processing
		//	Note: I should review the latching logic for these variables,
		//		the half-a**ed abstraction seems poor to me.
		//		I should either apply a generic latch function somewhere in the abstraction,
		//		or play around with prevResult, or use pointers or memory to only perform check
		//		if current latched result is false.
		// falling edge latch
		if (!(bo_devcTypExIInProcChkEnRawFallngEdgLtchd))
		{
			bo_devcTypExIInProcChkEnRawFallngEdgLtchd = chkDigSigEdgFallngExclusvly(bo_devcTypExIInProcChkEnRawRisngEdg, bo_devcTypExIInProcChkEnRawFallngEdg, bo_devcTypExIInProcChkEnRawNoChng);
		}

		//	Rising edge latch
		if (!(bo_devcTypExIInProcChkEnRawRisngEdgLtchd))
		{
			bo_devcTypExIInProcChkEnRawRisngEdgLtchd = chkDigSigEdgRisngExclusvly(bo_devcTypExIInProcChkEnRawRisngEdg, bo_devcTypExIInProcChkEnRawFallngEdg, bo_devcTypExIInProcChkEnRawNoChng);
		}

		//	No Change latch
		//	Latch if signal pulse for current and previous sample
		if (!(bo_devcTypExIInProcChkEnRawNoChngLtchd))
		{
			bo_devcTypExIInProcChkEnRawNoChngLtchd = chkDigSigEdgNoChngExclusvly(bo_devcTypExIInProcChkEnRawRisngEdg, bo_devcTypExIInProcChkEnRawFallngEdg, bo_devcTypExIInProcChkEnRawNoChng);
		}

		//	Checks if a full pulse has been processed into memory

		bo_ssiSysSysExJChkSigTitlExD = latchDigSigPulsPerUndefnd(bo_devcTypExIInProcChkEnRawRisngEdgLtchd, bo_devcTypExIInProcChkEnRawFallngEdgLtchd, bo_devcTypExIInProcChkEnRawNoChngLtchd);

		if (bo_ssiSysSysExJChkSigTitlExD)
		{
			// reset latching
			bo_devcTypExIInProcChkEnRawRisngEdgLtchd = false;
			bo_devcTypExIInProcChkEnRawFallngEdgLtchd = false;
			bo_devcTypExIInProcChkEnRawNoChngLtchd = false;
			digitalWrite(LED_BUILTIN, bo_ssiSysSysExJChkSigTitlExD);
			if(Serial)
			{
				delay(5);
				Serial.println("Input pulse read successfully");
				delay(5);
			}
		}
		else
		{
			digitalWrite(LED_BUILTIN, bo_ssiSysSysExJChkSigTitlExD);
			if(Serial)
			{
				delay(5);
				Serial.println("Input pulse not read");
				delay(5);
			}
		}

		//	process a certain feedback signal from a peripheral to the core device into buffer
		// increment a counter if a pulse was successfully detected
		if (bo_ssiSysSysExJChkSigTitlExD)
		{
			u8_devcTypXPulsCntrEx01 = u8_incrmntValWRollovr(u8_devcTypXPulsCntrEx01);
			bo_ssiSysSysExJChkSigTitlExD = false;
		}

		// Previously did some counter variable comparisons here.

		bo_ssiSubSysExVCtrlRqstSigTitlExB = (u8_ssiSubSysYRqstCntPendngExB != 0);

		bo_sysCtrllrDInDevcManuProductEx02SigTitlExP = readSysCtrllrDInDevcManuProductEx02SigTitlExP(INT_SYSCTRLLR_DINPINNUM_DEVCMANUPRODUCTABBREVEX02_DEVCSIGTITLEX02);

		//	Note: active xxx input
		//	Todo: Review processing algorithm (raw Input -> PI In Pr -> SI In Pr (?)) for a certain input signal
		//	Todo: implement automatic zzzz control, attempt to command reset X number of times before "giving up"  
		// Another raw input used to be read here 

		//	Note: active xxx input
		//	Todo: Review processing algorithm (raw Input -> PI In Pr -> SI In Pr (?)) for a certain feedback signal
		// Another raw input used to be read here

		//	Note: This statement appears to act like an PI or SI InPr signal,
		//		and is the naming too broad / generic? Can it be confused with
		//		the other signals?
		bo_diDevcTypExEHwInPrChkSigTitlExA = !(bo_sysCtrllrDInDevcManuProductEx02SigTitlExP);

		//	Note: use Approval Conditions flag when implementing a certain input and a certain input
		// Approval Conditions check was here

		// Approved flag was calculated here

		//	No real need for request approval conditions for a certain peripheral to the core device (Signal Title) in this program revision ?

		//	Todo: Consider using states seperately, like as feedback
		//		in the below selection statement, I could use flag/s to indicate YYYer (state)
		//		is either ready to actuation (awaiting request), request approved (processing request),
		//		actuating in progress, or something further in the control state
		if (bo_ssiSubSysExOCtrlRqstSigTitlExHApprvd && (enmSSISSXCS_ssiSubSysEx02CtrlState == SSISSXC_STATE_READY))
		{
			enmSSISSXCS_ssiSubSysEx02CtrlState = SSISSXC_STATE_RQSTCMDAPPRVD;
		}

		// Command pulse to YYYer
		//if (bo_ssiSubSysExOCtrlRqstSigTitlExHApprvd)
		if (enmSSISSXCS_ssiSubSysEx02CtrlState == SSISSXC_STATE_RQSTCMDAPPRVD)
		{
			//	Note: need to figure out a better way to control command pulse to YYYer
			//		this function will 'blindly' command n-second pulse out.
			//		While YYYing is being commanded, the system won't be able to read inputs (XXX, YYYing feedback, etc.)

			// Commanding an actuation via core device output pin used to be here
			
			//	note: could add something here to ensure acknowledgement of YYYe and (User Interaction) is successful.
			//		If I checked ZZZ over time (pulsing) then it would indicate successful operation
			enmSSISSXCS_ssiSubSysEx02CtrlState = SSISSXC_STATE_CMDNG;
		}

		//	Note: Below is a quick implementation of the 2nd above note:
		//		re-read inputs at this process stage, functions should ideally be read once per super-loop though
		
		// re-checking inputs from above used to be here too
		
		// Re-checking of approval conditions from above used to be here too

		if (bo_ssiSubSysExOCtrlRqstSigTitlExHApprvlConds && (enmSSISSXCS_ssiSubSysEx02CtrlState == SSISSXC_STATE_CMDNG))
		{
			enmSSISSXCS_ssiSubSysEx02CtrlState = SSISSXC_STATE_CMDCOMPSUCC;
		}

		if (enmSSISSXCS_ssiSubSysEx02CtrlState == SSISSXC_STATE_CMDCOMPSUCC)
		{
			//	If input is not a certain value, then there is an issue
			//	Program will try again next super-loop
			//	Note: States might be good for this in future (e.g. pending actuation, actuation complete)
			
			bo_ssiSubSysExOCtrlRqstSigTitlExH = false;
			// incrementing a certain counter used to be here

			enmSSISSXCS_ssiSubSysEx02CtrlState = SSISSXC_STATE_READY;
		}

		// Commanding a pulse + incremeting a counter to a certain peripheral to the core device used to be here
		
			//	Note: need to figure out a better way to control command pulse to a certain peripheral to the core device
			//		this function will pause the program.
			//		While(Signal Title) is being commanded, the system won't be able to read inputs (XXX, YYYing feedback, etc.)

		
		if ((bo_sysCtrllrDInDevcManuProductEx02SigTitlExS) && !(bo_sysCtrllrDInDevcManuProductEx02RqstSigTitlExT))
		{
			enmSSIPXFS_ssiPeriphrlXFdbkState = SSIPXF_STATE_SUBSYSOP_STATE01;
		}
		else if (!(bo_sysCtrllrDInDevcManuProductEx02SigTitlExS) && (bo_sysCtrllrDInDevcManuProductEx02RqstSigTitlExT))
		{
			enmSSIPXFS_ssiPeriphrlXFdbkState = SSIPXF_STATE_SUBSYSOP_STATE02;
		}
		else if ((bo_sysCtrllrDInDevcManuProductEx02SigTitlExS) && (bo_sysCtrllrDInDevcManuProductEx02RqstSigTitlExT))
		{
			enmSSIPXFS_ssiPeriphrlXFdbkState = SSIPXF_STATE_SUBSYSOP_STATE03;
		}
		else
		{
			enmSSIPXFS_ssiPeriphrlXFdbkState = SSIPXF_STATE_NULL;
		}
		
		// Do Something
		switch (enmSSIPXFS_ssiPeriphrlXFdbkState)
		{
			// Case State 01:
			case (SSIPXF_STATE_SUBSYSOP_STATE01):
				analogWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, (0U - U8_C_PREPROC_MCRO_CONST_EX01));
				break;
			// Case State 02:
			case (SSIPXF_STATE_SUBSYSOP_STATE02):
				analogWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, (0U - U8_C_PREPROC_MCRO_CONST_EX04));
				break;
			// Default Case:
			default:
				digitalWrite(INT_SYSCTRLLR_DIGxSOUTPINNUM_DEVCMANUPRODUCTABBREVEX04_DEVCSIGTITLEX01, true);
				break;
		}

		digitalWrite(LED_BUILTIN, bo_ssiSysSysExJChkSigTitlExD);

		bo_devcTypExKCtrllrInChkEnRawPrev = bo_devcTypExKCtrllrInChkEnRaw;

		// The line below this comment here was imported from reference project #2's WIP feature branch for considering non-volatile memory usage for calculations
		if (u32_prjCtrllrAppsRunTmeTickRteCntr_ms > u32_prjCtrllrAppsRunTmeTickRteCntrNvmSaveEventNext_ms)
		u32_Add002ValsWOvrflwDetectn

		delay(1);

		// The line below this comment here was imported from reference project #2's WIP feature branch for considering non-volatile memory usage for calculations
		u32_prjCtrllrAppsRunTmeTickRteCntr_ms = u32_incrmntValWRollovr(u32_prjCtrllrAppsRunTmeTickRteCntr_ms);
	}

	return 0;
}
