/*
 * Challenge1.c
 *
 * Created: 11/22/2013 2:43:10 PM
 *  Author: Mohamed Tarek
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char num = 0;
	DDRA  = DDRA & (~(1<<PA0)); // Configure pin 0 in PORTA as input pin
	DDRA  = DDRA & (~(1<<PA1)); // Configure pin 1 in PORTA as input pin
	DDRD |= 0x0F; // Configure the first four pins of PORTD as output pins
	
	// initialize the 7-segment with value 0 by clear the first four bits in PORTD
	PORTD &= 0xF0;
	
    while(1)
    {
		if(PINA & (1<<PA0)) // check if the first push button at PA0 is pressed or not
		{
			_delay_ms(30);
			//second check due to switch bouncing
			if(PINA & (1<<PA0))
			{
					if((PORTD & 0x0F) != 9)
					{
						// increment the 7-segment
						num++;
						PORTD = (PORTD & 0xF0) | (num & 0x0F);
					}
			}
			while(PINA & (1<<PA0)){} // wait until the first button is released
		}
		
		else if(PINA & (1<<PA1))// check if the second push button at PA1 is pressed or not
		{
			_delay_ms(30);
			//second check due to switch bouncing
			if(PINA & (1<<PA1))
			{
					if((PORTD & 0x0F) != 0)
					{
						// decrement the 7-segment
						num--;
						PORTD = (PORTD & 0xF0) | (num & 0x0F);
					}
			}
			while(PINA & (1<<PA1)){} // wait until the second button is released
		}				       
    }
}
