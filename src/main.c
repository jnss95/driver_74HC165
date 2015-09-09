//This file is only to debug the library
#include "main.h"
#include <util/delay.h>

int main(void)
{
	DDRB = 0xff;
	PORTB = 0xff;
	while(1){
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(1000);
		PORTB = 0xff;
	}
	return 1;
}
