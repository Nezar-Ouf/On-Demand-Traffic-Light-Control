/*
 * int0.c
 *
 * Created: 1/22/2023 4:30:12 PM
 *  Author: Nezar
 */ 

/* Includes */
#include "interrupts.h"
/* Global Variables */
uint8_t volatile interruptFlag_g = FALSE;

/* Definitions */
/* Internal Function Declarations */
void static (*INT0Callback)(void);

/* Function Definitions */
// 1. This function takes the INT number as an input.
// 2. Enable global interrupts.
// 3. Trigger INT0 on rising edge.
// 4. Enable INT0.
// 5. Return error state.
EN_intError_t INT_init(uint8_t interruptNumber)
{
	/* Here I am only writing code suitable for INT0. Any other value will return an error. */
	switch (interruptNumber)
	{
		case 0:
		/* Enable global interrupts */
		sei();
		/* Interrupt triggers on rising edge */
		MCUCR |= (1<<BIT0) | (1<<BIT1);
		/* Enable INT0 */
		GICR |= (1<<BIT6);
		return INT_OK;
		break;

		default:
		return WRONG_INT_INIT;
		break;
	}
}
/* This function takes a function as an input and stores its address in INT0Callback pointer to function */
void setINT0Callback (void (*Callback)(void))
{
	INT0Callback = Callback;
}

/* Interrupt Service Routine for INT0 */
ISR(EXT_INT_0)
{
	/* Checking if INT0 got triggered once. */
	if(interruptFlag_g == FALSE)
	{
		interruptFlag_g = TRUE; // After Triggering INT0, raising a flag so that it will not trigger again.
		INT0Callback();
		//interruptFlag_g = FALSE;
	}
}