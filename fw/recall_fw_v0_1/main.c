/****************************************************************************
;*	Microchip Technology Inc. 2007                                      *
;*	Assembler version:  XC8 v1.34                                       *
;*	Filename:                                                           *
;*		main.c (main routine)                                       *
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


/*
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/


#include "device_initialize.h"

//uint16_t dutycycle; // define variable - unsigned integer
uint8_t led_state = 0;  ///0:off, 1:on/blinking

// Main application
void main(void)
{
    SYSTEM_Initialize();    // Initialize the device
    
    //set weak pull on RA0, configure for input

//    TRISAbits.TRISA0 = 0;   // Set Channel RA0 as output
//    TRISAbits.TRISA1 = 0;   // Set Channel RA1 as output
//    LATAbits.LATA0 = 0;     // Set RA0 (LED D0) high
//    LATAbits.LATA1 = 0;     // Set RA1 (LED D1) high
    
    TRISAbits.TRISA0 = 1;   // Set Channel RA0 as input
    WPUAbits.WPUA0 = 1;     // Enable weak pull up
    OPTION_REGbits.nWPUEN = 0;  //Clear weak pull enable
    ANSELAbits.ANSA0 = 0;       //Digial I/O
    
    TRISAbits.TRISA2 = 0;   // Set Channel RA2 as output
    LATAbits.LATA2 = 0;     // Set RA2 (LED D1) high
    
    // Set Channel RA0 as input (SW)
    // Set Channel RA1 as output (D1)
    // Set Channel RA2 as timer
    
//    MR2_StartTimer();

    while (1)
    {
        //trigger on interrupt instead of IO value
//        if(PORTAbits.RA0 == 0)
//        {
//            led_state = 1;
//            LATAbits.LATA2 = 1;
//        }
//        else if (PORTAbits.RA0 == 1)
//        {
//            led_state = 0;
//            LATAbits.LATA2 = 0;
//        }
        
        
        if(PORTAbits.RA0==0 && led_state==0) {
            TMR2_StartTimer();
            led_state = 1;
        }
        else if (PORTAbits.RA0==0 && led_state==1) {
            TMR2_StopTimer();
            LATAbits.LATA2 = 0;
            led_state = 0;
        }
        
        //blink LED
        if(PIR1bits.TMR2IF == 1)
        {
            //toggle LED
            if (LATAbits.LATA2 == 0)
            {
                LATAbits.LATA2 = 1;
            }
            else
            {
                LATAbits.LATA2 = 0;
            }
            
            //reset timer2
            TMR2 = 0x00;
            PIR1bits.TMR2IF = 0;
        }
    }
}
// End of File
