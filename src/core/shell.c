/*
 * This is a basic shell for microcontrollers
 *
 * Author: Alexandre Hachet
 * Date: started the 17/02/2022
 *
 */

#define F_CPU 16000000UL
#define BAUD 9600

#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "board_io.h"

#define MYUBRR 103

int main(void) {
	USART_Init();
	_out(&DDRB, DDB5);
	_write(&PORTB, PB5, 0);

	print("Starting a new session\n");
	print("Running on ATMega328P\n");
	print("AVRShell@test:");

	while(1) {
		char data = USART_Receive();
		print(&data);
	}
}