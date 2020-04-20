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
enum States {Init, ADD_P, SUBTRACT_P, RESET_P, ADD, SUBTRACT, RESET} state;


void Tick() {
	//transitions	
	switch (state) {
		case Init:
			if (PINA == 0x01) { // press A0
				state = ADD;
			}
			else if (PINA == 0x02) { // press A1
				state = SUBTRACT;
			}	
			else if (PINA == 0x03) {
				state = RESET;
			}
			break;
		case ADD:
			if ((PINA == 0x01) && PINC < 9) {
				state = ADD;
			}	
			break;
		case SUBTRACT:
			if ((PINA == 0x02) && PINC > 0) {
				state = SUBTRACT;
			}
		default:
			state = Init;
	}	
	//states
	switch (state) {
		case Init:
			PORTC = 0x07;
			break;
		case ADD:
			PORTC += 1;
			break;
		case SUBTRACT:
			PORTC -= 1;
			break;
		case RESET:
			PORTC = 0;
			break;
				
		default:
			state = Init;
			
	}
		
}

int main(void) {
    // /* Insert DDR and PORT initializations */
		// 0x00 == input, 0xFF == output
		DDRA = 0x00; PORTA = 0xFF;
		DDRC = 0xFF; PORTC = 0x07;
    // /* Insert your solution below */    	
		// //initialize state and output
		state = Init;

    	while (1) {
			Tick();
    	}
    return 1;
}
