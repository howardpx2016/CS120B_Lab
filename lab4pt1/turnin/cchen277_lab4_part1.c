/*	Author: cchen277
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { LED0R, LED1P, LED1R, LED0P } state;

void Tick() {
	//transitions
	switch (state) {
		case LED0R:
			if (PINA & 0x01 == 0x01) {
				PORTB = 0x02;
				state = LED1P;	
			}
			else if (PINA & 0x01 == 0x00) {
				state = LED0R;
			}
			break;
		case LED1P:
			if (PINA & 0x01 == 0x00) {
				state = LED1R;
			}
			else if (PINA & 0x01 == 0x01) {
				state = LED1P;
			}
			break;
		case LED1R:
			if (PINA & 0x01 == 0x01) {
				PORTB = 0x01;
				state = LED0P;
			}
			else if (PINA & 0x01 == 0x00) {
				state = LED1R;
			}
			break;
		case LED0P:
			if (PINA & 0x01 == 0x00) {
				state = LED0R;
			}
			else if (PINA & 0x01 == 0x01) {
				state = LED0P;
			}
			break;
		default:
			PORTB = 0x01;
			state = LED0R;			
	}			
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x01;
    /* Insert your solution below */    	
	state = LED0R;

    while (1) {
	Tick();
    }
    return 1;
}
