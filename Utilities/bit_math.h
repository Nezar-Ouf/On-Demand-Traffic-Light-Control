/*
 * bit_math.h
 *
 * Created: 1/16/2023 4:03:55 PM
 *  Author: Nezar
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT)			( VAR |=  (1 << (BIT)))
#define CLR_BIT(VAR,BIT)			( VAR &= ~(1 << (BIT)))
#define TOG_BIT(VAR,BIT)			( VAR ^=  (1 << (BIT)))
#define GET_BIT(VAR,BIT)			((VAR >> BIT) &   1   )

#define BIT_IS_SET(VAR,BIT)			( VAR & (1   <<  BIT ))
#define BIT_IS_CLR(VAR,BIT)		  (!( VAR & (1   <<  BIT )))


#endif /* BIT_MATH_H_ */