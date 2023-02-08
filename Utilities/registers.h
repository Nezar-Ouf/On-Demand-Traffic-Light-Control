/*
 * registers.h
 *
 * Created: 1/16/2023 12:15:12 PM
 *  Author: Nezar
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_types.h"
/************* Pin Definitions *************/
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

#define BIT0	0
#define BIT1	1
#define BIT2	2
#define BIT3	3
#define BIT4	4
#define BIT5	5
#define BIT6	6
#define BIT7	7
/************** DIO Registers *************/
#define PORTA	(*((volatile uint8_t*)0x3B))
#define PORTB	(*((volatile uint8_t*)0x38))
#define PORTC	(*((volatile uint8_t*)0x35))
#define PORTD	(*((volatile uint8_t*)0x32))

#define DDRA	(*((volatile uint8_t*)0x3A))
#define DDRB	(*((volatile uint8_t*)0x37))
#define DDRC	(*((volatile uint8_t*)0x34))
#define DDRD	(*((volatile uint8_t*)0x31))

#define PINA	(*((volatile uint8_t*)0x39))
#define PINB	(*((volatile uint8_t*)0x36))
#define PINC	(*((volatile uint8_t*)0x33))
#define PIND	(*((volatile uint8_t*)0x30))
/************ Timer Registers *************/
#define OCR0	(*((volatile uint8_t*)0x5C))
#define TIMSK	(*((volatile uint8_t*)0x59))
#define TIFR	(*((volatile uint8_t*)0x58))
#define TCCR0	(*((volatile uint8_t*)0x53))
#define TCNT0	(*((volatile uint8_t*)0x52))

#define OCR2	(*((volatile uint8_t*)0x43))
#define TCCR2	(*((volatile uint8_t*)0x45))
#define TCNT2	(*((volatile uint8_t*)0x44))
/****** External Interrupts Registers *****/
#define SREG	(*((volatile uint8_t*)0x5F))
#define GICR	(*((volatile uint8_t*)0x5B))
#define GIFR	(*((volatile uint8_t*)0x5A))
#define MCUCR	(*((volatile uint8_t*)0x55))
#define MCUCSR	(*((volatile uint8_t*)0x54))

#endif /* REGISTERS_H_ */