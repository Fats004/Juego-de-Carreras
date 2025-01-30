/// Universidad del Valle de Guatemala
// Electrónica Digital 2
// main.c
// Proyecto: Prelab1
// Hardware: ATMEGA328P
// Created: 1/23/2025
// Author : Fatima Urrutia
//********************************************************************************************************************************************

//********************************************************************************************************************************************
// Librerias
//********************************************************************************************************************************************

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "C:\Users\Fatima\Documents\4to año\1er ciclo\Digital2\GccApplication1\GccApplication1\Display\Display.h"
#include <util/delay.h>

//********************************************************************************************************************************************
// Variables Globales
//********************************************************************************************************************************************

uint8_t cont = 5;
uint8_t init = 0;
uint8_t jugador1 = 0;
uint8_t jugador2 = 0;
uint8_t win = 0;

//********************************************************************************************************************************************
// Declarar Funciones
//********************************************************************************************************************************************

void setup(void);
void juno(uint8_t contador); // Funcion de incrementol de decadas jugador 1
void jdos(uint8_t contadors); // Funcion de incrementol de decadas jugador 2

//********************************************************************************************************************************************
// Main
//********************************************************************************************************************************************

int main(void)
{
	setup();
	display(cont); //mostrar el numero actual en el display
	
	while (1){
		
		//verificar que ya empezo el contador
		if (init){
			while (cont != 0){
				display(cont);
				_delay_ms(1000);
				cont = cont - 1; //decrementar el display hasta llegar a cero
			}
			display(cont);
			while (win == 0){
				juno(jugador1);
				jdos(jugador2); //Dejar a los jugadores jugar hasta que alguno gane
			}
			init =0; //reiniciar la variable de inicio
			win = 0; //Reiniciar la variable de ganadores
			
			
			
		}
	}
	
}

//********************************************************************************************************************************************
// Funciones
//********************************************************************************************************************************************

void setup(void){
	DDRB &= ~(1 << DDB4); //Setear los pines de los botones como entradas
	DDRC &= ~((1 << DDC5) | (1 << DDC4));
	PORTB |= (1 << PORTB4); //Activar pullups
	PORTC |= (1 << PORTC5) | (1 << PORTC4);

	DDRD = 0xFF;  //Setear las salidas en puerto d
	DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3);
	
	PCICR |= (1<<PCIE0) | (1 << PCIE1); //Encender el registro de control de portc
	PCMSK0 |= (1 << PCINT4); //Encender la mascara de PC4 y PC5
	PCMSK1 |= (1 << PCINT13) | (1 << PCINT12);

	
	sei(); //Activar interrupciones globales
}

void juno(uint8_t contador){
	switch (contador){ //Mostrar en las leds como van avanzando los jugadores segun su coontador
		case 0:
			PORTB &= ~((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2) | (1 << PORTB3));
			break;
		case 1:
			PORTB &= ~((1 << PORTB1) | (1 << PORTB2) | (1 << PORTB3));
			PORTB |= (1 << PORTB0);
			break;
		case 2:
			PORTB &= ~((1 << PORTB0) | (1 << PORTB2) | (1 << PORTB3));
			PORTB |= (1 << PORTB1);
			break;
		case 3:
			PORTB &= ~((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB3));
			PORTB |= (1 << PORTB2);
			break;
		case 4:
			PORTB &= ~((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2));
			PORTB |= (1 << PORTB3);
			break;
		case 5:
			PORTB |= (1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2) | (1 << PORTB3);
			break;
		default:
			break;
	}
	
	//verificar si ya gano el jugador segun su contador
	if(contador == 5){
		win = 1; //activar la variable de ganadores
		cont = 1; //poner en el display el numero del jugador
		display(cont);
	}
}


// Lo mismo pero con el segundo jugador
void jdos(uint8_t contadors){
	switch (contadors){
		case 0:
			PORTC &= ~((1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3));
			break;
		case 1:
			PORTC &= ~((1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3));
			PORTC |= (1 << PORTC0);
			break;
		case 2:
			PORTC &= ~((1 << PORTC0) | (1 << PORTC2) | (1 << PORTC3));
			PORTC |= (1 << PORTC1);
			break;
		case 3:
			PORTC &= ~((1 << PORTC0) | (1 << PORTC1) | (1 << PORTC3));
			PORTC |= (1 << PORTC2);
			break;
		case 4:
			PORTC &= ~((1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2));
			PORTC |= (1 << PORTC3);
			break;
		case 5: 
			PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3);
			break;
		default:
		break;
	}
	
	if(contadors == 5){
		win = 1;
		cont = 2;
		display(cont);
	}
}

//********************************************************************************************************************************************
// Interrupciones
//********************************************************************************************************************************************

ISR(PCINT0_vect){
	uint8_t bttnP = PINB & (1 << PINB4); //Variable del boton de Empezar
	
	//verificar si se presiono el boton
	if (bttnP == 0){
		init = 1;//avisar el inicio de contador
		cont = 5;
		
		// reiniciar valores iniciales
		jugador1 =0;
		jugador2 = 0;
		
		juno(jugador1);
		jdos(jugador2);
	}
	
	PCIFR |= (1 << PCIF0); //Apagar la bandera del pinchange
}

ISR(PCINT1_vect){
	uint8_t bttn1 = PINC & (1 << PINC5);
	uint8_t bttn2 = PINC & (1 << PINC4);
	
	// verificar el boton de cual jugador se presiono e incrementar contador del mismo
	if (bttn1 == 0){
		if (cont == 0){
			++jugador1;
		}
	}
	else if (bttn2 == 0){
		if (cont == 0){
			++jugador2;
		}
	}
	
	PCIFR |= (1 << PCIF1); // reiniciar bandera
}
