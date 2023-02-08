/*
 * int0.h
 *
 * Created: 1/22/2023 4:32:16 PM
 *  Author: Nezar
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/* Includes */
#include "../DIO/dio.h"

/* Definitions */
/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1

#define INTERRUPT_NUMBER0	0

/* sei() enables global interrupts */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* cli() disables global interrupts */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR Definition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


/* Internal Driver Typedefs */
typedef enum EN_intError_t
{
	INT_OK, WRONG_INT_INIT
}EN_intError_t;


/* Function Prototypes */
EN_intError_t INT_init(uint8_t interruptNumber);
void setINT0Callback (void (*Callback)(void));
#endif /* INTERRUPTS_H_ */