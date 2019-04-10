#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"

#define _XTAL_FREQ 4000000
#define segment PORTB
#define digit PORTA

unsigned char DISPLAY;
unsigned char temp = 0;
unsigned char temp2 = 0;

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
