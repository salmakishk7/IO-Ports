


#include <avr/io.h>

int main()
{
	/********** Initialization Code **********/
	DDRA &= ~(1<<3);  // Configure pin 3 in PORTA as input pin

	DDRC |= (1<<5);   // Configure pin 5 in PORTC as output pin
	PORTC &= ~(1<<5); // Set pin 5 in PORTC with value 0 at the beginning(LED OFF)

	while(1)
	{
		/********** Application Code **********/
		if(PINA & (1<<3)) // check if the push button at PA3 is pressed or not
		{
			PORTC |= (1<<5); // Set pin 5 in PORTC with value 1 (LED ON)
		}
		else
		{
			PORTC &= (~(1<<5)); // Set pin 5 in PORTC with value 0 (LED OFF)
		}
	}
}

