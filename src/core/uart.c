#define F_CPU 16000000UL

#include <avr/io.h>
#include "uart.h"

char str_digits[] = "abcdefghijklmnopqrstuvwxyz";

void USART_Init() {
	unsigned int ubrr = BR;
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
	UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);
}

void USART_Transmit(unsigned char data) {
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

uint8_t USART_Receive() {
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void print(char * data) {
	unsigned char c = *data;
	while (c) {
		USART_Transmit(c);
		c = *(++data);
	}
}

char input() {
	char data[] = "";
	unsigned int c = USART_Receive();
	int j = 0;
	for (int i = 0; i<sizeof(str_digits); i++) {
		if ((unsigned int)str_digits[i] != c) {
			return -1;
		}
		data[j++] = c;
	}
	return *data;
}