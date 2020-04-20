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
// //declare states
enum States {LOCKED, L1, L2, UNLOCKED, UL1, UL2} state;

void Tick() {
	//transitions
	switch (state) {
		case LOCKED:
			if (PINA == 0x04) {
				state = L1;
			}
			else {
				state = LOCKED;
			}
			break;
		case L1:
			if (PINA == 0x00) {
				state = L2;
			}
			// else if (PINA == 0x04) {
			// 	state = L1;
			// }
			else {
				state = L1;
			}
			break;
		case L2:
			if (PINA == 0x02) {
				state = UNLOCKED;
			}
			else {
				state = L2;
			}
			break;
		case UNLOCKED:
			if (PINA >= 0x80) {
				state = LOCKED;
			}
			break;
		// case UL1:
		// 	if (PINA == 0x04) {
		// 		state = L1;
		// 	}
		// 	else {
		// 		state = LOCKED;
		// 	}
		// 	break;
		// 	break;
		// case UL2:
		// 	break;
		default:	
			state = LOCKED;	
	}

	//state actions
	switch (state) {
		case LOCKED:
			PORTB = 0X00;
			break;
		case L1:
			PORTB = 0X00;

			break;
		case L2:
			PORTB = 0X00;

			break;
		case UNLOCKED:
			PORTB = 0X01;

			break;
		// case UL1:
		// 	PORTB = 0x01;
		// 	break;
		// case UL2:
		// 	PORTB = 0x01;
		// 	break;
		default:
			PORTB = 0x00;

	}	
}

int main(void) {
    // /* Insert DDR and PORT initializations */
		// 0x00 == input, 0xFF == output
		DDRA = 0x00; PORTA = 0xFF;
		DDRB = 0xFF; PORTB = 0x00;
		DDRC = 0xFF; PORTC = 0x00;
    // /* Insert your solution below */    	
		// //initialize state and output
		state = LOCKED;

    	while (1) {
			Tick();
    	}
    return 1;
}
