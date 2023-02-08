/*
 * led.h
 *
 * Created: 1/16/2023 5:31:24 PM
 *  Author: Nezar
 */ 


#ifndef LED_H_
#define LED_H_
/* Includes */
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Interrupts/interrupts.h"
#include "../../MCAL/Timer/timer0.h"
#include "../../MCAL/Timer/timer2.h"

/* LED Definitions */
#define CAR_GREEN_LED			0
#define CAR_YELLOW_LED			1
#define CAR_RED_LED				2

#define PEDESTRIANS_GREEN_LED	0
#define PEDESTRIANS_YELLOW_LED	1
#define PEDESTRIANS_RED_LED		2

/* Internal Driver Typedefs */
typedef enum EN_ledError_t
{
	LED_OK, WRONG_LED_INIT, WRONG_LED_ON, WRONG_LED_OFF, WRONG_LED_TOGGLE
}EN_ledError_t;

/* Function Prototypes */
EN_ledError_t LED_init (uint8_t ledPort, uint8_t ledPin);
EN_ledError_t LED_on (uint8_t ledPort, uint8_t ledPin);
EN_ledError_t LED_off (uint8_t ledPort, uint8_t ledPin);
EN_ledError_t LED_toggle (uint8_t ledPort, uint8_t ledPin);

#endif /* LED_H_ */