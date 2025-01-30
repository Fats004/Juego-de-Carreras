/*
 * Display.c
 *
 * Created: 1/23/2025 7:13:48 PM
 *  Author: Fatima
 */ 
#include "C:\Users\Fatima\Documents\4to año\1er ciclo\Digital2\GccApplication1\GccApplication1\Display\Display.h"

void display(uint8_t numero){
	
	const uint8_t tabla[] = {0x03, 0xE7, 0x92, 0xC2, 0x66, 0x4A, 0x0A, 0xE3, 0x02, 0x62};
	
	switch(numero){
		case 0:
			PORTD = tabla[0];
			break;
		case 1:
			PORTD = tabla[1];
			break;
		case 2:
			PORTD = tabla[2];
			break;
		case 3:
			PORTD = tabla[3];
			break;
		case 4:
			PORTD = tabla[4];
			break;
		case 5:
			PORTD = tabla[5];
			break;
		default:
			break;
	}	
}
