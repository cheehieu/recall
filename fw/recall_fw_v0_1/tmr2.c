/****************************************************************************
;*	Microchip Technology Inc. 2007                                      *
;*	Assembler version:  XC8 v1.34                                       *
;*	Filename:                                                           *
;*		tmr2.c                                                      *
;*	Dependents:                                                         *
;*                                                                          *
;*	April 13, 2015                                                      *
;*      PIC10(L)32X Developmental Board                                     *
;*      Demonstration program:                                              *
;*          After applying power to the PIC10(L)F32X Development Board,     *
;*          LED (D1) will automatically turn on.  Turn POT1 clockwise       *
;*          to increase the brightness of LED (D2).  Press switch (SW1)     *
;*          to turn both LEDs D1 and D2 off, release switch (SW1) and       *
;*          LEDs D1 and D2 will turn on.                                    *
;*                                                                          *
;****************************************************************************/

// Section: Included Files

#include <xc.h>
#include "tmr2.h"

void TMR2_Initialize(void)
{
    // TOUTPS 1:16; TMR2ON off; T2CKPS 1:64;
    T2CON = 0xF7;
  
    //31kHz LFINTOSC
    //0x08 = ~1 second
    //0x20 = ~4 seconds
    //0xFF = ~32 seconds
    PR2 = 0x08;
//    PR2 = 0x03; //shorter for button debounce

    // TMR2 0x00;
    TMR2 = 0x00;

    // Clearing IF flag.
    PIR1bits.TMR2IF = 0;
}

void TMR2_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}

void TMR2_StopTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}

// End of File

