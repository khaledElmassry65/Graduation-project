/*
 * KEYPAD_CONFIG.h
 *
 * Created: 11/20/2020 8:03:38 PM
 *  Author: karim
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "CPU_CONFIGURATION.h"

#define KEYPAD_OUT_PORT DIO_PORTC
#define KEYPAD_INP_PORT DIO_PORTC


#define KEYPAD_OUT_PIN0 DIO_PIN4
#define KEYPAD_OUT_PIN1 DIO_PIN5
#define KEYPAD_OUT_PIN2 DIO_PIN6
#define KEYPAD_OUT_PIN3 DIO_PIN7

#define KEYPAD_INP_PIN0 DIO_PIN0
#define KEYPAD_INP_PIN1 DIO_PIN1
#define KEYPAD_INP_PIN2 DIO_PIN2
#define KEYPAD_INP_PIN3 DIO_PIN3

#define COL_INIT  4
#define COL_FINAL 7

#define ROW_INIT  0
#define ROW_FINAL 3


#endif /* KEYPAD_CONFIG_H_ */