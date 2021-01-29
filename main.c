//led brightness using pwm
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

void pwm_init()     //FAST PWM INIT
{
	TCCR0 |= (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS00);
	DDRB |= (1<<PB4); //SET OC0 AS OUTPUT PIN
}


int main()
{
	uint8_t duty;
	pwm_init();
	while(1)
	{
		for(duty=0;duty<255;duty++)
		{
			OCR0 = duty;
			_delay_ms(10);
		}
		for(duty=255; duty>1; duty--)
		{
			OCR0 = duty;  
			_delay_ms(8);
		}
	}
}