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

uint8_t led_state = 0;  ///0:off, 1:on/blinking

// Main application
void main(void)
{
    SYSTEM_Initialize();    // Initialize the device
    
    //Configure RA0 for button
    TRISAbits.TRISA0 = 1;   // Set Channel RA0 as input
    WPUAbits.WPUA0 = 1;     // Enable weak pull up
    ANSELAbits.ANSA0 = 0;   //Digital I/O
    OPTION_REGbits.nWPUEN = 0;  //Clear weak pull enable
    IOCANbits.IOCAN0 = 1;       //Enable interrupt on negative edge
    IOCAPbits.IOCAP0 = 0;       //Disable interrupt on positive edge
    INTCONbits.IOCIE = 1;       //Enable IOC interrupt
            
    //Configure RA2 for LED
    TRISAbits.TRISA2 = 0;   // Set Channel RA2 as output
    LATAbits.LATA2 = 0;     // Set RA2 (LED D1) high

    while (1)
    {
        //TEST CODE FOR BLINKING LED
//        if(IOCAFbits.IOCAF0==1 && led_state==0) {
//            IOCAFbits.IOCAF0 = 0; //clear IOC flag
//            led_state = 1;
//            TMR2_StartTimer();
//            LATAbits.LATA2 = 1;
//            //debouncing timer?
//        }
//        else if (IOCAFbits.IOCAF0==1 && led_state==1) {
//            IOCAFbits.IOCAF0 = 0; //clear IOC flag
//            led_state = 0;
//            TMR2_StopTimer();
//            LATAbits.LATA2 = 0;
//        }
//        
//        //blink LED
//        if(PIR1bits.TMR2IF == 1)
//        {
//            //toggle LED
//            if (LATAbits.LATA2 == 0)
//            {
//                LATAbits.LATA2 = 1;
//            }
//            else
//            {
//                LATAbits.LATA2 = 0;
//            }
//            
//            //reset timer2
//            TMR2 = 0x00;
//            PIR1bits.TMR2IF = 0;
//        }
        //TEST CODE FOR BLINKING LED
        
        
        
        //TEST CODE FOR BASIC ON/OFF
        if(IOCAFbits.IOCAF0==1 && led_state==0) {
            LATAbits.LATA2 = 1;
            
//            //delay for button debounce
//            TMR2_StartTimer();
//            if(PIR1bits.TMR2IF == 1)
//            {
                IOCAFbits.IOCAF0 = 0; //clear IOC flag
                led_state = 1;
//                TMR2 = 0x00;
//                PIR1bits.TMR2IF = 0;
//                TMR2_StopTimer();
//            }
        }
        else if (IOCAFbits.IOCAF0==1 && led_state==1) {
            LATAbits.LATA2 = 0;
            
//            //delay for button debounce
//            TMR2_StartTimer();
//            if(PIR1bits.TMR2IF == 1)
//            {
                IOCAFbits.IOCAF0 = 0; //clear IOC flag
                led_state = 0;
//                TMR2 = 0x00;
//                PIR1bits.TMR2IF = 0;
//                TMR2_StopTimer();
//            }
        }
        //TEST CODE FOR BASIC ON/OFF
    }
}
// End of File
