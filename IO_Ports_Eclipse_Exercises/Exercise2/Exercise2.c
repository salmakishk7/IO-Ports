/*
 * Exercise2.c
 *
 * Created: 11/22/2013 2:17:05 PM
 * Author: Mohamed Tarek
 */


#include <avr/io.h>
#include <util/delay.h> // for delay function

int main(void)
{
	DDRD = DDRD | (1<<PD6); // Configure pin 6 in PORTD as output pin

	PORTD |= (1<<PD6); // Set pin 6 in PORTD with value 1 at the beginning(LED OFF)

    while(1)
    {
		PORTD = PORTD & (~(1<<PD6)); // Set pin 6 in PORTD with value 0 (LED ON)
		_delay_ms(1000);
		PORTD = PORTD | (1<<PD6);    // Set pin 6 in PORTD with value 1 (LED OFF)
		_delay_ms(1000);
		/************ Another Method *************
		PORTD = PORTD ^ (1<<PD6); // Toggle value of pin 6 in PORTD (LED Toggle)
		_delay_ms(1000);
		******************************************/
    }
}
