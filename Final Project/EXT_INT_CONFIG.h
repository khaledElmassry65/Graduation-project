/*
 * EXT_INT_CONFIG.h
 *
 * Created: 1/23/2021 8:40:51 PM
 *  Author: karim
 */ 


#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_
/*Macros and libraries needed*/
#include "CPU_CONFIGURATION.h"
/************************************** INTERRUPT-Registers *******************************************/
/*
#define SREG    (*(volatile Uint8t*) (0x5F))
#define GICR    (*(volatile Uint8t*) (0x5B))
#define GIFR    (*(volatile Uint8t*) (0x5A))
#define MCUCR   (*(volatile Uint8t*) (0x55))
#define MCUCSR  (*(volatile Uint8t*) (0x54))
*/
/*Global Interrupt enable and disable*/
#define GLOBAL_INTERRUPT_EN      1
#define GLOBAL_INTERRUPT_DS      0
/*Logical to fire interrupt, events*/
#define EXT_INT_TRG_LOW          0
#define EXT_INT_TRG_ANY_LOGICAL  1
#define EXT_INT_TRG_FALLING_EDGE 2
#define EXT_INT_TRG_RISING_EDGE  3
/*Interrupts states*/
#define GLOBAL_INTERRUPT_STATE    GLOBAL_INTERRUPT_EN
#define EXT_INT0_TRIGGER          EXT_INT_TRG_FALLING_EDGE
#define EXT_INT1_TRIGGER          EXT_INT_TRG_RISING_EDGE
#define EXT_INT2_TRIGGER          EXT_INT_TRG_LOW
/*End of configuration file*/
#endif /* EXT_INT_CONFIG_H_ */