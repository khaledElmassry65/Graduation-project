/*
* TIMER0.h
*
* Created: 3/12/2021 10:31:18 AM
*  Author: karim
*/


#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_CONFIG.h"
/*Polling Mode*/
void TIMER0_WITHOUT_INTERRUPT_Initialization(void);
void TIMER0_WITHOUT_INTERRUPT_Set_Delay(Uint32t Delay, Uint8t ocr);
/*Interrupt Mode*/
void TIMER0_WITH_INTERRUPT_Initialization(void);
void TIMER0_WITH_INTERRUPT_Set_Delay(Uint32t Delay, Uint8t ocr);

void TIMER0_FastPWM_Initialization(void);
void TIMER0_FastPWM_Set_Duty(Uint8t Duty);

#endif /* TIMER0_H_ */