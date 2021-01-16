//timer1 no prescalar i.e prescalar=1 and 5ms delay
#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define LED PE6

/*
	TCNTVALUE=(MAX_VALUE_OF_TIMER-(CRYSTAL_FREQ*(REQUIRED_DELAY/PRESCALAR)))+1
	8MHZ=8*10^6
	5MS=10*10^-3
	PRESCALAR=1
*/


ISR (TIMER1_OVF_vect)
{
	TCNT1=25536;    //again load tcnt1 value
	PORTE ^= (0x01 << LED);
	
}

void timer0_init()
{
	TCNT0=25536;     //from calculation 
	TCCR0 |= (1<<CS00);   //no prescalar 
	TIMSK |= (1<<TOIE0);    //INTERRUPT FOR TIMER1 OVERFLOW
}


int main(void)
{
	DDRE=0XFF;   //PORTE AS OUTPUT
	timer0_init();  //TIMER1 STARTS FROM HERE WITH TCNT1=65457
	sei();
	while(1)
	{
		//do nothing
	}
}