/*	Author: isant028
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00; 

	unsigned char tmpA = 0x00;
	unsigned char tmpB =0x00;
	unsigned char tmpC = 0x00;
	while(1){
		tmpA = PINA;
		tmpB = 0x00;
		tmpC= 0x00; 
		
		tmpB = PINA >> 4;
		PORTB = tmpB;

		tmpC = (tmpA & 0x0F)<<4;
		PORTC = tmpC;
	
	}

	return 0;

}
