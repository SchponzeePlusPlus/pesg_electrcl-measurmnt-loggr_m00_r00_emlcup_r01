/**
 * Arduino_Sketch_refprj02.ino
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
void setup()
{
    initSysCtrllr();
}

//	put your main code here, to run repeatedly:
void loop()
{
    execSysCtrllrRunTimeMain();
    for(;;)
    {
        if(Serial)
        {
            Serial.println("(High-Level) System Application Run-Time Exited. Program Out of Bounds!!");
            delay(10000);
        }
    }
}
