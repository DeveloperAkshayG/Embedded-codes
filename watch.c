//watchdog timer using atmega128
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define LED PE6

void watch_on()
{
//	WDTCR |= (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0); //enables watchdog with timeout of 1.8sec
//	WDTCR |= (1<<WDE)|(1<<WDP2)|(1<<WDP1); //enables watchdog with timeout of 0.9sec
	WDTCR |= (1<<WDE)|(1<<WDP2)|(1<<WDP0); //enables watchdog with timeout of 0.45sec
}

void watch_off()
{
	WDTCR = (1<<WDCE)|(1<<WDE);
	WDTCR = 0x00;
}

int main()
{
	watch_on();
	DDRE=0XFF;
	PORTE=0b01000000;
	_delay_ms(1000);
	PORTE=0b00000000;
	while(1);
}