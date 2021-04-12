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
	DDRD = 0x00; PORTD = 0xFF; 
	DDRB = 0xFE; PORTB = 0x01;

	unsigned char tmpB = 0x00; 
	unsigned char tmpD = 0x00;

	while(1) {
		tmpD = 0x00;
		tmpB = 0x00;

		tmpD = PIND; 
		tmpD = (tmpD <<1) | PINB; 
		
		

		if(tmpD >=70){
			tmpB = tmpB | 0x02;
		}
		else if (tmpD < 70 && tmpD > 5){
			tmpB = tmpB | 0x04;
		}
		PORTB = tmpB; 
	}

	return 0;

}
