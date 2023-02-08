/*
 * timer2.h
 *
 * Created: 1/20/2023 4:39:59 PM
 *  Author: Nezar
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

/* Includes */
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/std_types.h"

/* Defines */
#define DELAY_5_SECONDS		5
#define DELAY_1_SECOND		1

/* Internal Driver Typedefs */
typedef enum EN_timer2Error_t
{
	TIMER2_OK, WRONG_TIMER2_INIT, WRONG_TIMER2_START, WRONG_TIMER2_DELAY, WRONG_TIMER2_STOP
}EN_timer2Error_t;

typedef enum EN_timer2Mode_t
{
	TIMER2_NORMAL_MODE, TIMER2_CTC_MODE, TIMER2_PWM_MODE, TIMER2_FAST_PWM_MODE
}EN_timer2Mode_t;

typedef enum EN_timer2Prescaler_t
{
	TIMER2_PRESCALER_OFF = 0, TIMER2_NO_PRESCALER = 1, TIMER2_PRESCALER_8 = 8, TIMER2_PRESCALER_32 = 32,
	TIMER2_PRESCALER_64 = 64, TIMER2_PRESCALER_256 = 256, TIMER2_PRESCALER_1024 = 1024
}EN_timer2Prescaler_t;

/* Function Prototypes */
EN_timer2Error_t TIMER2_delay(uint16_t timer2Prescaler, uint16_t delayInSeconds);

#endif /* TIMER2_H_ */