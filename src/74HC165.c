#include "74HC165.h"

void shift_init(void)
{
	PORT_CLK_INH &= ~(1<<BIT_CLK_INH);
	PORT_LD |= (1<<BIT_LD);

	DDR_CLK |= (1<<BIT_CLK);
	DDR_CLK_INH |= (1<<BIT_CLK_INH);
	DDR_LD |= (1<<BIT_LD);
	DDR_SER_IN &= ~(1<<BIT_SER_IN);
}

uint8_t shift_in(void)
{
	PORT_LD |= (1<<BIT_LD);
	PORT_LD &= ~(1<<BIT_LD);
	uint8_t ret;
	for(int i=0;i<8;i++){
		PORT_CLK |= (1<<BIT_CLK);
		if (PIN_SER_IN & (1<<BIT_SER_IN))
			ret |= (1<<i);
		PORT_CLK &= ~(1<<BIT_CLK);
	}
	return ret;
}