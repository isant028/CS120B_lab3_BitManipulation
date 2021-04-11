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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; 
	
	unsigned char tmpB = 0x00; 
	unsigned char tmpA = 0x00;
	unsigned char count = 0x00;  
	
	while(1) {
		unsigned int i = 0; 	
		tmpA = PINA;
		tmpB = PINB;
		count = 0x00;

		for( i = 0; i < 8;  i++){
			if ((tmpA & 0x01)==0x01){
				count++; 
			}
			tmpA = tmpA >> 1; //move to next bit 
		}
		
		for(i = 0; i < 8;  i++){
			if ((tmpB & 0x01)==0x01){
				count++; 
			}
			tmpB = tmpB >> 1; //move to next bit 
		}
		PORTC = count; 
	}
	return 0;

}
