#include <avr/io.h>
#include "board_io.h"

void _in(volatile uint8_t* port, uint8_t pin) {
	*(port - 1) |= (0 << pin);
}

void _out(volatile uint8_t* port, uint8_t pin) {
	*(port - 1) |= (1 << pin);
}

int _write(volatile uint8_t* port, uint8_t pin, int value) {
	if (value != 0 || value != 1) {
		return 0;
	}
	*port |= (value << pin);
	return 1;
}

int _read(volatile uint8_t* port, uint8_t pin) {
	return (*port & (1 << pin)) >> pin;
}