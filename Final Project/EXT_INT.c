/*
* EXT_INT.c
*
* Created: 1/23/2021 8:41:11 PM
*  Author: karim
*/

#include "EXT_INT.h"

void GLOBAL_INTERRUPT_Init(void)
{
	#if GLOBAL_INTERRUPT_STATE == GLOBAL_INTERRUPT_EN
	SET_BIT(SREG, 7);
	#elif GLOBAL_INTERRUPT_STATE == GLOBAL_INTERRUPT_DS
	CLR_BIT(SREG, 7);
	#endif
}
void EXT_INTERRUPT0_Init(void)
{
	/*Enable global interrupt*/
	GLOBAL_INTERRUPT_Init();
	/*Enable External Interrupt 0*/
	SET_BIT(GICR, INT0);
	//SET_BIT(GICR, 6);
	/*How to trigger an interrupt*/
	#if EXT_INT0_TRIGGER == EXT_INT_TRG_LOW
	CLR_BIT(MCUCR, ISC01);CLR_BIT(MCUCR, ISC00);	
	#elif EXT_INT0_TRIGGER == EXT_INT_TRG_ANY_LOGICAL
	CLR_BIT(MCUCR, ISC01);SET_BIT(MCUCR, ISC00);	
	#elif EXT_INT0_TRIGGER == EXT_INT_TRG_FALLING_EDGE
	SET_BIT(MCUCR, ISC01);CLR_BIT(MCUCR, ISC00);
	#elif EXT_INT0_TRIGGER == EXT_INT_TRG_RISING_EDGE
	SET_BIT(MCUCR, ISC01);SET_BIT(MCUCR, ISC00);
	#endif
}
void EXT_INTERRUPT1_Init(void)
{
	
}
void EXT_INTERRUPT2_Init(void)
{
	
}