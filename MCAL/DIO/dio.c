/*
 * dio.c
 *
 * Created: 1/16/2023 12:39:29 PM
 *  Author: Nezar
 */ 

/* Includes */
#include "dio.h"

/* Global Variables*/
/* Function Definitions */

// 1. This function takes 3 arguments as an input:
// 2. Port Number, Pin Number, and Pin Direction.
// 3. Depending on the arguments, the function will initialize that specific pin and define its direction.
// 4. The function will return an error state to indicate whether everything is OK.
EN_dioError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	if((pinNumber < 0) || (pinNumber > 7))
	{
		return WRONG_DIO_INIT;
	}
	else
	{
		switch(portNumber)
		{
			case PORT_A:
				if(direction == IN)
				{
					CLR_BIT(DDRA,pinNumber);
					return DIO_OK;
				}
				else if(direction == OUT)
				{
					SET_BIT(DDRA,pinNumber);
					return DIO_OK;
				}
				else
				{
					return WRONG_DIO_INIT;
				}
			break;
			
			case PORT_B:
				if(direction == IN)
				{
					CLR_BIT(DDRB,pinNumber);
					return DIO_OK;
				}
				else if(direction == OUT)
				{
					SET_BIT(DDRB,pinNumber);
					return DIO_OK;
				}
				else
				{
					return WRONG_DIO_INIT;
				}
				break;
				
			case PORT_C:
				if(direction == IN)
				{
					CLR_BIT(DDRC,pinNumber);
					return DIO_OK;
				}
				else if(direction == OUT)
				{
					SET_BIT(DDRC,pinNumber);
					return DIO_OK;
				}
				else
				{
					return WRONG_DIO_INIT;
				}
				break;
				
			case PORT_D:
				if(direction == IN)
				{
					CLR_BIT(DDRD,pinNumber);
					return DIO_OK;
				}
				else if(direction == OUT)
				{
					SET_BIT(DDRD,pinNumber);
					return DIO_OK;
				}
				else
				{
					return WRONG_DIO_INIT;
				}
				break;
				
			default:
				return WRONG_DIO_INIT;
				break;
		}
	}
}

// 1. This function takes 3 arguments as an input:
// 2. Port Number, Pin Number, and Pin Value.
// 3. Depending on the arguments, the function will write the pin value on the desired pin.
// 4. The function will return an error state to indicate whether everything is OK.
EN_dioError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	if((pinNumber < 0) || (pinNumber > 7))
	{
		return WRONG_DIO_WRITE;
	}
	else
	{
		switch(portNumber)
		{
			case PORT_A:
			if(value == LOW)
			{
				CLR_BIT(PORTA,pinNumber);	// write 0
				return DIO_OK;
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTA,pinNumber);	// write 1
				return DIO_OK;
			}
			else
			{
				return WRONG_DIO_WRITE;
			}
			break;
			
			case PORT_B:
			if(value == LOW)
			{
				CLR_BIT(PORTB,pinNumber);	// write 0
				return DIO_OK;
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTB,pinNumber);	// write 1
				return DIO_OK;
			}
			else
			{
				return WRONG_DIO_WRITE;
			}
			break;
			
			case PORT_C:
			if(value == LOW)
			{
				CLR_BIT(PORTC,pinNumber);	// write 0
				return DIO_OK;
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTC,pinNumber);	// write 1
				return DIO_OK;
			}
			else
			{
				return WRONG_DIO_WRITE;
			}
			break;
			
			case PORT_D:
			if(value == LOW)
			{
				CLR_BIT(PORTD,pinNumber);	// write 0
				return DIO_OK;
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTD,pinNumber);	// write 1
				return DIO_OK;
			}
			else
			{
				return WRONG_DIO_WRITE;
			}
			break;
			
			default:
			return WRONG_DIO_WRITE;
			break;
		}
	}
	
}

// 1. This function takes 2 arguments as an input:
// 2. Port Number and Pin Number.
// 3. Depending on the arguments, the function will toggle the desired pin.
// 4. The function will return an error state to indicate whether everything is OK.
EN_dioError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	if((pinNumber < 0) || (pinNumber > 7))
	{
		return WRONG_DIO_TOGGLE;
	}
	else
	{
		switch(portNumber)
		{
			case PORT_A:
			TOG_BIT(PORTA,pinNumber);
			return DIO_OK;
			break;
			
			case PORT_B:
			TOG_BIT(PORTB,pinNumber);
			return DIO_OK;
			break;
			
			case PORT_C:
			TOG_BIT(PORTC,pinNumber);
			return DIO_OK;
			break;
			
			case PORT_D:
			TOG_BIT(PORTD,pinNumber);
			return DIO_OK;
			break;
			
			default:
			return WRONG_DIO_TOGGLE;
			break;
		}
	}
}
