/*
 * app.h
 *
 * Created: 1/16/2023 6:49:54 PM
 *  Author: Nezar
 */ 


#ifndef APP_H_
#define APP_H_

/* Includes */
#include "../HAL/LED/led.h"

/* Definitions */
#define CAR_MODE			0
#define PEDESTRIAN_MODE		1

/* Global Variables */
extern uint8_t volatile interruptFlag_g;

/* Function Prototypes */
void APP_init();
void APP_start();
void APP_startCarMode();
void APP_startPedestrianMode();
void APP_switchMode();

void APP_testModule();
void APP_testTimer();
#endif /* APP_H_ */