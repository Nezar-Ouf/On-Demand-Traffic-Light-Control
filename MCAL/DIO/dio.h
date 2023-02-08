/*
 * dio.h
 *
 * Created: 1/16/2023 12:39:43 PM
 *  Author: Nezar
 */ 


#ifndef DIO_H_
#define DIO_H_

/* Includes */
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/std_types.h"

/* Internal Driver Typedefs */
typedef enum EN_dioError_t
{
	DIO_OK, WRONG_DIO_INIT, WRONG_DIO_WRITE, WRONG_DIO_TOGGLE, WRONG_DIO_READ
}EN_dioError_t;

/* Driver Macros */
#define PORT_A		'A'
#define PORT_B		'B'
#define PORT_C		'C'
#define PORT_D		'D'

/* Direction Definitions */
#define IN			0
#define OUT			1

/* Value Definitions */
#define LOW			0
#define HIGH		1

/* Function Prototypes */
EN_dioError_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // initialize DIO pin Direction
EN_dioError_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);	 // write data on DIO pin
EN_dioError_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber);					 // toggle DIO pin

#endif /* DIO_H_ */