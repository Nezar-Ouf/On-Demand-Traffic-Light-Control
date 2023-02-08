/*
 * led.c
 *
 * Created: 1/16/2023 5:32:10 PM
 *  Author: Nezar
 */ 

/* Includes */
#include "led.h"

/* Function Definitions */
// 1. This function takes as an input:
//	  LED Port and LED Pin.
// 2. The function will set the direction of the pin connected to the LED as output.
// 3. The function will return an error state to indicate whether everything is OK.
EN_ledError_t LED_init (uint8_t ledPort, uint8_t ledPin)
{
	uint8_t errorState = DIO_init(ledPort, ledPin, OUT);
	
	switch (errorState)
	{
		case DIO_OK:
		return LED_OK;
		break;
		
		default:
		return WRONG_LED_INIT;
		break;
	}
}

// 1. This function takes as an input:
//	  LED Port and LED Pin.
// 2. The function will set the value of the pin connected to the LED as HIGH.
// 3. The function will return an error state to indicate whether everything is OK.
EN_ledError_t LED_on (uint8_t ledPort, uint8_t ledPin)
{
	uint8_t errorState = DIO_write(ledPort, ledPin, HIGH);
	
	switch (errorState)
	{
		case DIO_OK:
		return LED_OK;
		break;
		
		default:
		return WRONG_LED_ON;
		break;
	}
}

// 1. This function takes as an input:
//	  LED Port and LED Pin.
// 2. The function will set the value of the pin connected to the LED as LOW.
// 3. The function will return an error state to indicate whether everything is OK.
EN_ledError_t LED_off (uint8_t ledPort, uint8_t ledPin)
{
	uint8_t errorState = DIO_write(ledPort, ledPin, LOW);
	
	switch (errorState)
	{
		case DIO_OK:
		return LED_OK;
		break;
		
		default:
		return WRONG_LED_OFF;
		break;
	}
}

// 1. This function takes as an input:
//	  LED Port and LED Pin.
// 2. The function will toggle the value of the pin connected to the LED.
// 3. The function will return an error state to indicate whether everything is OK.
EN_ledError_t LED_toggle (uint8_t ledPort, uint8_t ledPin)
{
	uint8_t errorState = DIO_toggle(ledPort, ledPin);
	
	switch (errorState)
	{
		case DIO_OK:
		return LED_OK;
		break;
		
		default:
		return WRONG_LED_TOGGLE;
		break;
	}
}