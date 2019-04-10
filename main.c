/******************************************************************************/
/* Files to Include
 *
 * Copyright BY "Attribution" ©  (can be used by others if credited)                                        */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

#define HIGH 1
#define LOW 0

#define _XTAL_FREQ 4000000
#define segment PORTB
#define digit PORTA

unsigned char count = 0;
unsigned char buffer = 0;

unsigned char heartbeat = 0;
unsigned char prevValue = 0;

unsigned char temp = 0;
unsigned char temp2 = 0;

unsigned char DISPLAY;

void display(int DISPLAY) {

    switch (DISPLAY) {
        case 0:
            segment = 0x40;
            break;
        case 1:
            segment = 0x79;
            break;
        case 2:
            segment = 0x24;
            break;
        case 3:
            segment = 0x30;
            break;
        case 4:
            segment = 0x19;
            break;
        case 5:
            segment = 0x12;
            break;
        case 6:
            segment = 0x02;
            break;
        case 7:
            segment = 0x78;
            break;
        case 8:
            segment = 0x00;
            break;
        case 9:
            segment = 0x10;
            break;

    }
}


void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    while(1)
    {

        //For detection of rising edge
        if ( (RA4 == HIGH)&&(prevValue == LOW) )
        {
        heartbeat ++;
        prevValue = HIGH;
        }

        if ((RA4 == LOW)&&(prevValue == HIGH))
        {
            prevValue = LOW;
        }

        
        if (count >= 200) {
            buffer++;
            count = 0;
        }
         
        if (buffer >= 1) { // 3 for 30 sec - 6 is about a minute
                
            count = 0;
            temp = 6*heartbeat;

            while (count <= 200) {

                digit = 0b100;
                DISPLAY = (temp%10);
                display(DISPLAY);
                __delay_ms(100);

                digit = 0b010;
                DISPLAY = temp - DISPLAY;
                DISPLAY = (DISPLAY / 10);
                temp2 = DISPLAY;
                DISPLAY = (DISPLAY % 10);
                display(DISPLAY);
                __delay_ms(100);

                digit = 0b001;
                DISPLAY = temp2 - DISPLAY;
                DISPLAY = (DISPLAY / 10);
                display(DISPLAY);
                __delay_ms(100);
            }

            heartbeat = 0;
            count = 0;
            buffer = 0;
            
        }

    }

}


