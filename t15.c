//timer1 20ms delay with 1024 prescalar
#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define LED PE6
unsigned long overflow;

/*
	TCNTVALUE=(MAX_VALUE_OF_TIMER-(CRYSTAL_FREQ*(REQUIRED_DELAY/PRESCALAR)))+1
	8MHZ=8*10^6
	20MS=20*10^-3
	PRESCALAR=1024
*/


ISR (TIMER1_OVF_vect)
{
//	TCNT1=65419;    //again load tcnt1 value for 15ms delay
	TCNT1=65379;    //again load tcnt1 value for 20ms delay
	PORTE ^= (0x01 << LED);
	/*overflow++;      
	if(overflow>=50) //to generate 1s delay by loading tcnt value
	{
		PORTE ^= (0x01 << LED);
		overflow=0;
	}*/
}

void timer1_init()
{
//	TCNT1=65419;     //from calculation for 15ms delay
	TCNT1=65379;     //from calculation for 20ms delay
//	overflow=0;
	TCCR1B |= (1<<CS10) | (1<<CS12);   //prescalar of 1024 for atmega128 
	TIMSK |= (1<<TOIE1);    //INTERRUPT FOR TIMER1 OVERFLOW
}


int main(void)
{
	DDRE=0XFF;   //PORTE AS OUTPUT
	timer1_init();  //TIMER1 STARTS FROM HERE WITH TCNT1=65457
	sei();
	while(1)
	{
		//do nothing
	}
}