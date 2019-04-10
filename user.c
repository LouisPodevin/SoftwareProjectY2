/******************************************************************************/
/* Files to Include
 *
 * Copyright BY © "Attribution" ©  (can be used by others if credited)                                                */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    ANSEL = 0x00;

    TRISA = 0xF8; 
    TRISB = 0x00; 

    IRCF2 = 1; //4MHz
    IRCF1 = 1;
    IRCF0 = 0;

    TMR1ON = 1; //enable TMR1
    TMR1CS = 0; //mode clock

    TMR1IE = 1; //Overflow Interrupt Enable
    PEIE = 1; //Peripheral Interrupt Enable
    GIE = 1; //Global Interrupt Enable
}

