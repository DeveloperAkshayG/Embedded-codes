//start timer and display how many times it overflow
#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include "lcd.c"
#define LED PE6
unsigned long overflow=0;
char overflowres[20]={0};
ISR (TIMER1_OVF_vect)
{
	overflow++;
//	PORTE ^= (0x01 << LED);
	if(overflow >= 2500)
	{
		PORTE ^= (0x01 << LED);
		TCCR1B=0X00;
	}
	
}

void timer1_init()
{
	TCNT1=0;     //from calculation 
	TCCR1B |= (1<<CS10);   //no prescalar 8.200ms 
	overflow=0;
	TIMSK |= (1<<TOIE1);    //INTERRUPT FOR TIMER1 OVERFLOW
}

int main(void)
{
	LCD_Init();
	DDRE=0xFF;
	timer1_init();
	sei();
	while(1)
	{
		sprintf(overflowres,"ov=%lu",overflow);
		LCD_String_xy(0,0,overflowres);
	
	}
	
	
	
}