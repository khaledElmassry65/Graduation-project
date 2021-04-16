/*
* TIMER0.c
*
* Created: 3/12/2021 10:31:45 AM
*  Author: karim
*/
#include "TIMER0.h"

Uint32t Num_OVF = 0;
Uint32t Num_CTC = 0;
Uint32t Initial_Value = 0;

void TIMER0_WITHOUT_INTERRUPT_Initialization(void)
{
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	#elif WAVE_GENERATION_MODE == CTC_MODE
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	#endif
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
}
void TIMER0_WITHOUT_INTERRUPT_Set_Delay(Uint32t Delay, Uint8t ocr)
{
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	Uint32t counter = 0;
	Uint8t Tick = PRESCALER / F_OSC;
	Uint32t Count = (Delay * MISECOND) / Tick;
	Uint32t OVF = Count / BITS;
	OVF++;
	Uint32t InitialValue = BITS - (Count % BITS);
	TCNT0 = InitialValue;
	/*Polling Mode*/
	while (counter != OVF)
	{
		/*Waiting flag after overflow*/
		while (GET_BIT(TIFR, TOV0) != 1);
		/*Re-initialize flag, down flag*/
		SET_BIT(TIFR, TOV0);
		counter++;
	}
	#elif WAVE_GENERATION_MODE == CTC_MODE
	Uint32t counter = 0;
	Uint8t Tick = PRESCALER / F_OSC;
	Uint32t Count = (Delay * MISECOND) / Tick;
	OCR0 = ocr;
	Uint32t CTC = Count / OCR0;
	CTC++;
	/*Polling Mode*/
	while (counter != CTC)
	{
		while (GET_BIT(TIFR, OCF0) != 1);
		SET_BIT(TIFR, OCF0);
		counter++;
	}
	#endif
	return;
}

void TIMER0_WITH_INTERRUPT_Initialization(void)
{
	
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	/*Enable Interrupt*/
	SET_BIT(TIMSK, TOIE0);
	#elif WAVE_GENERATION_MODE == CTC_MODE
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	/*Enable Interrupt*/
	SET_BIT(TIMSK, OCIE0);
	#endif
	/*Prescaler*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
	/*Enable Global Interrupt*/
	sei();
}
void TIMER0_WITH_INTERRUPT_Set_Delay(Uint32t Delay, Uint8t ocr)
{
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	Uint8t Tick = PRESCALER / F_OSC;
	Uint32t Counts = (Delay * MISECOND) / Tick;
	Num_OVF = Counts / BITS;
	Initial_Value = BITS - (Counts % BITS);
	TCNT0 = Initial_Value;
	Num_OVF++;
	#elif WAVE_GENERATION_MODE == CTC_MODE
	Uint8t Tick = PRESCALER / F_OSC;
	Uint32t Counts = (Delay * MISECOND) / Tick;
	OCR0 = ocr;
	Num_CTC = Counts / OCR0;
	Num_CTC++;
	#endif
}

void TIMER0_FastPWM_Initialization(void)
{
	SET_BIT(DDRB, PB3);
	/*
	#if WAVE_GENERATION_MODE == FAST_PWM_MODE
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	#if PWM_MODE == NON_INVERTING
	SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	#elif PWM_MODE == INVERTING
	SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
	#endif
	#elif WAVE_GENERATION_MODE == PHASECORRECT_PWM_MODE
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	#if PWM_MODE == NON_INVERTING
	SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	#elif PWM_MODE == INVERTING
	SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
	#endif
	#endif
	*/
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);/*Choose Fast PWM*/
	SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);/*Non- Inverting Mode*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void TIMER0_FastPWM_Set_Duty(Uint8t Duty)
{
	#if PWM_MODE == NON_INVERTING
	OCR0 = ((BITS * Duty) / 100) - 1;
	#elif PWM_MODE == INVERTING
	OCR0 = (BITS - 1) - (((BITS * Duty) / 100) - 1);
	#endif
}