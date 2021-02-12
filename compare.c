#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define LED PE6

ISR (TIMER0_COMP_vect)
{
	PORTE ^= (0x01 << LED);
	//OCR0=0;
}

void timer0_init ( )        //timer0 initialization
{

	TCNT0=0X00; //LOAD THE VALUE OF COUNTER REGISTER
	TCCR0 = (1 << WGM01) ; //CTC MODE
	//TCCR0 |= (1<<CS00);
	TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02) ;
	OCR0=245;
	TIMSK |=(1<<OCIE0);
}

int main(void)
{
	DDRE=0XFF;
	timer0_init();
	sei();
	while(1)
	{
	
	}
}