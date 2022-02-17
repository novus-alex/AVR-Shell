#ifndef BAUD
#define BR 103
#endif

/*
 * Baudrates for f = 16MHz
 */

#define BR_2400 416
#define BR_4800 207
#define BR_9600 103
#define BR_14400 68
#define BR_19200 51
#define BR_28800 34
#define BR_38400 25

void USART_Init();
void USART_Transmit(unsigned char data);
uint8_t USART_Receive();
void print(char * data);
char input();