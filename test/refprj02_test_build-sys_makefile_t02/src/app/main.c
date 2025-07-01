/********************************************
*
*  Name:
*  Section:
*  Assignment:
*
********************************************/

/**
 * <redacted>.ino
 * @brief 
 * 
 */

//	Pre-Processor Macros

//  #include "Arduino.h"

//	Include Directory Headers
#include "app_sys_main.h"
//#include "randomtestfile_doesntexist_lol.h"

//	Global constants

//	put your setup code here, to run once:

#include <avr/io.h>

int main(void)
{
    // Your program goes here

    initSysCtrllr();

    execSysCtrllrRunTimeMain();

    //	put your main code here, to run repeatedly (like Arduino's loop() ?):
    while(1)
    {
        if(Serial)
        {
            Serial.println("(High-Level) System Application Run-Time Exited. Program Out of Bounds!!");
            delay(10000);
        }
    }

    return 0;   /* never reached */
}
