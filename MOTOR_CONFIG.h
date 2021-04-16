/*
 * MOTOR_CONFIG.h
 *
 * Created: 2/12/2021 9:10:21 PM
 *  Author: karim
 */ 


#ifndef MOTOR_CONFIG_H_
#define MOTOR_CONFIG_H_

#include "CPU_CONFIGURATION.h"

#define MOTOR_CNTRL_PORT DIO_PORTD
#define MOTOR_DTA_PORT   DIO_PORTC

#define MOTOR_EN1        DIO_PIN4
#define MOTOR_EN2        DIO_PIN5
#define MOTOR1_A1        DIO_PIN3
#define MOTOR1_A2        DIO_PIN4		         
#define MOTOR1_A3        DIO_PIN5
#define MOTOR1_A4        DIO_PIN6

#define MOTOR_LOW        DIO_PIN_LOW
#define MOTOR_HIGH       DIO_PIN_HIGH
#define MOTOR_OUTPUT     DIO_PIN_OUTPUT

#endif /* MOTOR_CONFIG_H_ */