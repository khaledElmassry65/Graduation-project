/*
* TIMER0_CONFIG.h
*
* Created: 3/12/2021 10:31:08 AM
*  Author: karim
*/


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include "CPU_CONFIGURATION.h"

/*Register address form register summary*/
/*
#define TCNT0 (*(volatile Uint8t*)(0x52))
#define TCCR0 (*(volatile Uint8t*)(0x53))
#define TIFR  (*(volatile Uint8t*)(0x58))
#define TIMSK (*(volatile Uint8t*)(0x59))
#define OCR0  (*(volatile Uint8t*)(0x5C))
*/
#define F_OSC     16
#define BITS      256
#define MISECOND  1000
#define PRESCALER 1024

#define NORMAL_MODE              0
#define PHASECORRECT_PWM_MODE    1
#define CTC_MODE                 2
#define FAST_PWM_MODE            3

#define INVERTING     0
#define NON_INVERTING 1

#define PRE_NOCLK    0
#define PRE_CLK8     1
#define PRE_CLK64    2
#define PRE_CLK256   3
#define PRE_CLK1024  4

#define WAVE_GENERATION_MODE     NORMAL_MODE
#define TIMER0_PRESCALER         PRE_CLK1024
#define PWM_MODE                 NON_INVERTING

#endif /* TIMER0_CONFIG_H_ */