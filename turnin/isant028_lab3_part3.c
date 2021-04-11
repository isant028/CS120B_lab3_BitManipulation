/*	Author: isant028
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpB = 0x00; 
	unsigned char tmpA = 0x00;
	unsigned char seat = 0x00; 

	while(1) {
		tmpA = PINA & 0x0F; 
		tmpB = 0x00;
		seat = PINA & 0x70; 		
		
		if(tmpA == 0x00) {
		tmpB = tmpB | 0x40;
	}
		else if(tmpA <= 2){
			tmpB = 0x60; 
		}
		else if(tmpA <= 4){
			tmpB = 0x70; 
		}
		else if(tmpA <= 6){
			tmpB = 0x38; 
		}
		else if(tmpA <= 9){
			tmpB = 0x3C; 
		}
		else if(tmpA <= 12){
			tmpB = 0x3E; 
		}
		else if(tmpA <= 15){
			tmpB = 0x3F; 
		}

		if(seat == 0x03){
			tmpB = tmpB | 0x80; 
		}
		PORTC = tmpB; 
	}

	return 0;

}
