/*
 * app.c
 *
 * Created: 1/16/2023 6:49:40 PM
 *  Author: Nezar
 */ 

/* Includes */
#include "app.h"

/* Global Variables */
uint8_t static appMode_g = CAR_MODE;
uint8_t static currentCarLed = CAR_GREEN_LED;
uint8_t static previousCarLed = CAR_GREEN_LED;
uint8_t static timer0InterruptFlag_g = FALSE;

uint8_t static secondsCounter = 0;
/* Function Definitions */
/* This function initializes the drivers needed for the application. */
void APP_init()
{
	/* Initializing cars LEDS */
	LED_init (PORT_A, CAR_GREEN_LED);
	LED_init (PORT_A, CAR_YELLOW_LED);
	LED_init (PORT_A, CAR_RED_LED);
	
	/* Initializing pedestrians LEDS */
	LED_init (PORT_B, PEDESTRIANS_GREEN_LED);
	LED_init (PORT_B, PEDESTRIANS_YELLOW_LED);
	LED_init (PORT_B, PEDESTRIANS_RED_LED);
	
	/* Initializing INT0 */
	INT_init(INTERRUPT_NUMBER0);
	setINT0Callback(APP_switchMode);
}

/* This function starts the sequence of the application. */
void APP_start()
{
	if(appMode_g == CAR_MODE)
	{
		APP_startCarMode();
	}
}

void APP_startCarMode()
{
	switch(currentCarLed)
	{
		/* Enable car green light.*/
		case CAR_GREEN_LED:
		LED_on (PORT_A, CAR_GREEN_LED);
		TIMER0_delay(TIMER0_PRESCALER_1024, DELAY_5_SECONDS);
		if(timer0InterruptFlag_g == TRUE)
		{
			timer0InterruptFlag_g = FALSE;
			LED_off(PORT_A, CAR_GREEN_LED);// Closing car green led after coming back from pedestrian mode.
			return;
		}
		LED_off(PORT_A, CAR_GREEN_LED);
		previousCarLed = currentCarLed;
		currentCarLed ++;
		break;
		
		
		/* Blink car yellow light.*/
		case CAR_YELLOW_LED:
		switch(previousCarLed)
		{
			/* Previous LED is green. */
			case CAR_GREEN_LED:
			while (secondsCounter < DELAY_5_SECONDS)
			{
				LED_toggle(PORT_A, CAR_YELLOW_LED);
				TIMER0_delay(TIMER0_PRESCALER_1024, DELAY_1_SECOND);
				if(timer0InterruptFlag_g == TRUE)
				{
					timer0InterruptFlag_g = FALSE;
					LED_off(PORT_A, CAR_GREEN_LED);// Closing car green led after coming back from pedestrian mode.
					return;
				}
				secondsCounter++;
			}
			LED_off(PORT_A, CAR_YELLOW_LED);
			secondsCounter = 0;
			previousCarLed = currentCarLed;
			currentCarLed = CAR_RED_LED;
			break;
			
			/* Previous LED is red. */
			case CAR_RED_LED:
			while (secondsCounter < DELAY_5_SECONDS)
			{
				LED_toggle(PORT_A, CAR_YELLOW_LED);
				TIMER0_delay(TIMER0_PRESCALER_1024, DELAY_1_SECOND);
				if(timer0InterruptFlag_g == TRUE)
				{
					timer0InterruptFlag_g = FALSE;
					LED_off(PORT_A, CAR_GREEN_LED);// Closing car green led after coming back from pedestrian mode.
					return;
				}
				secondsCounter++;
			}
			LED_off(PORT_A, CAR_YELLOW_LED);
			secondsCounter = 0;
			previousCarLed = currentCarLed;
			currentCarLed = CAR_GREEN_LED;
			break;
			
			default:
			/* Do nothing */
			break;
		}
		break;
		
		
		/* Enable car red light.*/
		case CAR_RED_LED:
		LED_on (PORT_A, CAR_RED_LED);
		TIMER0_delay(TIMER0_PRESCALER_1024, DELAY_5_SECONDS);
		LED_off(PORT_A, CAR_RED_LED);
		previousCarLed = currentCarLed;
		currentCarLed = CAR_YELLOW_LED;
		break;
		
		default:
		/* Do nothing */
		break;
	}
}
void APP_startPedestrianMode()
{
	/* In the first and second cases below, I do not add break; since each case happens after the previous one. */
	switch(currentCarLed)
	{
		/* Enable car green light and pedestrian red light.*/
		case CAR_GREEN_LED:
		LED_on(PORT_A, CAR_GREEN_LED);
		LED_on(PORT_B, PEDESTRIANS_RED_LED);
		TIMER2_delay(TIMER2_PRESCALER_1024, DELAY_5_SECONDS);
		LED_off(PORT_A, CAR_GREEN_LED);
		LED_off(PORT_B, PEDESTRIANS_RED_LED);
		
		
		/* Blink car and pedestrian yellow light.*/
		case CAR_YELLOW_LED:
		secondsCounter = 0;
		LED_off(PORT_A, CAR_YELLOW_LED);// stop CAR_YELLOW_LED so that both yellow leds start blinking together.
		while (secondsCounter < DELAY_5_SECONDS)
		{
			LED_toggle(PORT_A, CAR_YELLOW_LED);
			LED_toggle(PORT_B, PEDESTRIANS_YELLOW_LED);
			TIMER2_delay(TIMER2_PRESCALER_1024, DELAY_1_SECOND);
			secondsCounter++;
		}
		LED_off(PORT_A, CAR_YELLOW_LED);
		LED_off(PORT_B, PEDESTRIANS_YELLOW_LED);
		secondsCounter = 0;
		break;// Break from switch and continue the sequence of the rest of the function. 
		
		
		/* Enable car red light and pedestrian green light.*/
		case CAR_RED_LED:
		LED_on(PORT_A, CAR_RED_LED);
		LED_on(PORT_B, PEDESTRIANS_GREEN_LED);
		TIMER2_delay(TIMER2_PRESCALER_1024, DELAY_5_SECONDS);
		LED_off(PORT_B, PEDESTRIANS_GREEN_LED);
		appMode_g = CAR_MODE;
		secondsCounter = 0;
		timer0InterruptFlag_g = FALSE;
		/* Clearing the interrupt flag to receive new interrupts before leaving the pedestrian function. */
		interruptFlag_g = FALSE;
		return;// return from the function without continuing the rest of the sequence.
	}
	/* Car red led on, pedestrian green led on.*/
	LED_on(PORT_A, CAR_RED_LED);
	LED_on(PORT_B, PEDESTRIANS_GREEN_LED);
	TIMER2_delay(TIMER2_PRESCALER_1024, DELAY_5_SECONDS);
	LED_off(PORT_A, CAR_RED_LED);
	
	/* Blink car and pedestrian yellow light while pedestrian green led is still on.*/
	while (secondsCounter < DELAY_5_SECONDS)
	{
		LED_toggle(PORT_A, CAR_YELLOW_LED);
		LED_toggle(PORT_B, PEDESTRIANS_YELLOW_LED);
		TIMER2_delay(TIMER2_PRESCALER_1024, DELAY_1_SECOND);
		secondsCounter++;
	}
	LED_off(PORT_A, CAR_YELLOW_LED);
	LED_off(PORT_B, PEDESTRIANS_YELLOW_LED);
	LED_off(PORT_B, PEDESTRIANS_GREEN_LED);
	
	/* car green led on, pedestrian red led on.*/
	LED_on(PORT_A, CAR_GREEN_LED);
	LED_on(PORT_B, PEDESTRIANS_RED_LED);
	TIMER2_delay(TIMER2_PRESCALER_1024, DELAY_5_SECONDS);
	LED_off(PORT_B, PEDESTRIANS_RED_LED);
	
	/* set previousCarLed & currentCarLed values before returning. */
	previousCarLed = CAR_GREEN_LED;
	currentCarLed = CAR_YELLOW_LED;
	
	appMode_g = CAR_MODE;// change app mode to CAR_MODE
	secondsCounter = 0;
	timer0InterruptFlag_g = TRUE;
/* Clearing the interrupt flag to receive new interrupts before leaving the pedestrian function. */
	interruptFlag_g = FALSE;
}
/* This function is the callback function which will be called by INT0 upon triggering the ISR */
void APP_switchMode()
{
	GICR &= ~(1<<BIT6);// disabling INTO to avoid double press and long press.
	
	/* Switch from car mode to pedestrians mode */
	if (appMode_g == CAR_MODE)
	{
		appMode_g = PEDESTRIAN_MODE;
		APP_startPedestrianMode();
	}
	GICR |= (1<<BIT6);// re-enabling INT0
}


/* This function is only used to test desired modules, and is not used in main application. */
void APP_testModule()
{
	/* Testing DIO_init() */
	DIO_init(PORT_A, PIN0, IN); // Expecting DIO_OK return.
	DIO_init(PORT_A, PIN1, OUT); // Expecting DIO_OK return.
	DIO_init(PORT_A, PIN2, IN); // Expecting DIO_OK return.
	
	DIO_init(PORT_B, PIN0, IN); // Expecting DIO_OK return.
	DIO_init(PORT_B, PIN1, OUT); // Expecting DIO_OK return.
	DIO_init(PORT_B, PIN2, IN); // Expecting DIO_OK return.
	
	DIO_init('F', PIN3, IN); // Expecting WRONG_DIO_INIT return.
	DIO_init(PORT_A, 9, IN); // Expecting WRONG_DIO_INIT return.
	DIO_init(PORT_A, PIN4, 4); // Expecting WRONG_DIO_INIT return.
	
	/* Testing DIO_write() */
	DIO_write(PORT_A, PIN5, HIGH); //Expecting DIO_OK return.
	DIO_write(PORT_C, PIN7, LOW); //Expecting DIO_OK return.
	
	DIO_write('K', PIN7, LOW); //Expecting WRONG_DIO_WRITE return.
	DIO_write(PORT_C, 9, HIGH); //Expecting WRONG_DIO_WRITE return.
	DIO_write(PORT_C, PIN6, 3); //Expecting WRONG_DIO_WRITE return.
	
	/* Testing DIO_toggle() */
	DIO_toggle(PORT_C, PIN7); // Expecting DIO_OK return.
	
	DIO_toggle('R', PIN7); // Expecting WRONG_DIO_TOGGLE return.
	DIO_toggle(PORT_C, 9); // Expecting WRONG_DIO_TOGGLE return.
}
/* This function is only used to test timer module, and is not used in main application.*/
void APP_testTimer()
{
	/* Initializing PORT_A LEDs. */
	LED_init (PORT_A, CAR_GREEN_LED);
	LED_init (PORT_A, CAR_YELLOW_LED);
	LED_init (PORT_A, CAR_RED_LED);
	
	while(1)
	{
		/* CAR_GREEN_LED on. */
		LED_on(PORT_A, CAR_GREEN_LED);
		TIMER0_delay(TIMER0_PRESCALER_1024, DELAY_5_SECONDS);
		LED_off(PORT_A, CAR_GREEN_LED);
		
		/* CAR_YELOLOW_LED on. */
		LED_on(PORT_A, CAR_YELLOW_LED);
		TIMER0_delay(TIMER0_PRESCALER_1024, DELAY_5_SECONDS);
		LED_off(PORT_A, CAR_YELLOW_LED);
		
		/* CAR_RED_LED on. */
		LED_on(PORT_A, CAR_RED_LED);
		TIMER0_delay(TIMER0_PRESCALER_1024, DELAY_5_SECONDS);
		LED_off(PORT_A, CAR_RED_LED);
	}
}