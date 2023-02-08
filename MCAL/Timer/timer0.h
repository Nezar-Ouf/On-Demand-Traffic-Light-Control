/*
 * timer0.h
 *
 * Created: 1/20/2023 4:39:59 PM
 *  Author: Nezar
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/* Includes */
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/std_types.h"

/* Defines */
#define DELAY_5_SECONDS		5
#define DELAY_1_SECOND		1

/* Internal Driver Typedefs */
typedef enum EN_timer0Error_t
{
	TIMER0_OK, WRONG_TIMER0_INIT, WRONG_TIMER0_START, WRONG_TIMER0_DELAY, WRONG_TIMER0_STOP
}EN_timer0Error_t;

typedef enum EN_timer0Mode_t
{
	TIMER0_NORMAL_MODE, TIMER0_CTC_MODE, TIMER0_PWM_MODE, TIMER0_FAST_PWM_MODE
}EN_timer0Mode_t;

typedef enum EN_timer0Prescaler_t
{
	TIMER0_PRESCALER_OFF = 0, TIMER0_NO_PRESCALER = 1, TIMER0_PRESCALER_8 = 8,
	TIMER0_PRESCALER_64 = 64, TIMER0_PRESCALER_256 = 256, TIMER0_PRESCALER_1024 = 1024
}EN_timer0Prescaler_t;

/* Function Prototypes */
EN_timer0Error_t TIMER0_delay(uint16_t timer0Prescaler, uint16_t delayInSeconds);

#endif /* TIMER0_H_ */