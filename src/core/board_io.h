void _in(volatile uint8_t* port, uint8_t pin);
void _out(volatile uint8_t* port, uint8_t pin);
int _write(volatile uint8_t* port, uint8_t pin, int value);
int _read(volatile uint8_t* port, uint8_t pin);