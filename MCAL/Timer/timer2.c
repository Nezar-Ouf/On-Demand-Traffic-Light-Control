/*
 * timer2.c
 *
 * Created: 1/20/2023 5:54:10 PM
 *  Author: Nezar
 */ 

/* Includes */
#include "timer2.h"

/* Function Definitions */

// 1. This Function takes as arguments:
//		- The timer prescaler
//		- The required delay in seconds.
// 2. This function creates a delay in seconds.
/* Giving an example of calculations for 5 seconds delay and 1 second delay. */

// 3. Setting Timer Configurations:
//	   Ttick = Prescalre/Fcpu = 1024/1,000,000 = 0.001024
//	   Tmax delay = Ttick * 2^n = 256 * 0.001024 = 0.262144 seconds
//	   N(overflows for 5 seconds) = Tdelay/Tmaxdelay = (ceil) 5/0.262144 = 20 = (delayInSeconds x 4)
//	   N(overflows for 1 second) = Tdelay/Tmaxdelay = (ceil) 1/0.262144 = 4 = (delayInSeconds x 4)
//	   T(initial) = 2^n - (Tdelay/Ttick/Noverflows) = 256 - (5/0.001024/20) = 11.859375 (Approximately 12)
//	   T(initial) = 2^n - (Tdelay/Ttick/Noverflows) = 256 - (delayInSeconds/0.001024/N) = 11.859375 (Approximately 12)
// 4. Setting the prescaler value to 1024 in TCCR0.
// 5. Waiting for overflows, then resetting overflow counter and stopping the timer.
// 6. The function will return an error state to indicate whether a correct prescaler is used.
 EN_timer2Error_t TIMER2_delay(uint16_t timer2Prescaler, uint16_t delayInSeconds)
 {
	 uint8_t overflowCounter = 0;
	 
	 /* Normal mode */
	 TCCR2 = 0x00;
	 /* Start Counting from 12 */
	 TCNT2 = 12;
	 
	 /* Note: Here, I am only writing suitable code for Prescaler 1024. Any other value will return Error */
	 switch(timer2Prescaler)
	 {
		 case TIMER2_PRESCALER_1024:
		 /* Start Timer2 with Prescaler = 1024 */
		 TCCR2 |= (1<<BIT0) | (1<<BIT1) | (1<<BIT2);
		 /* According to the calculations, the number of overflows required to reach the delay is: delayInSeconds x 4 */
		 while(overflowCounter < (delayInSeconds * 4))
		 {
			 while((TIFR & (1<<BIT6)) == 0);
			 
			 // Clear overflow flag
			 TIFR|= (1<<BIT6);
			 
			 overflowCounter++;
		 }
		 overflowCounter = 0;
		 /* Timer2 stop */
		 TCCR2 = 0x00;
		 return TIMER2_OK;
		 break;
		 
		 default:
		 return WRONG_TIMER2_DELAY;
	 }
 }
