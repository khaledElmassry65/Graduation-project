/*
* MOTOR.c
*
* Created: 2/12/2021 9:06:24 PM
*  Author: karim
*/

#include "MOTOR.h"


void Motor1_Init(void)
{
	DIO_SetPin_Direction(MOTOR_CNTRL_PORT, MOTOR_EN1, MOTOR_OUTPUT);
	DIO_SetPin_Direction(MOTOR_DTA_PORT, MOTOR1_A1, MOTOR_OUTPUT);
	DIO_SetPin_Direction(MOTOR_DTA_PORT, MOTOR1_A2, MOTOR_OUTPUT);
}
void Motor1_Enable(void)
{
	DIO_SetPin_Value(MOTOR_CNTRL_PORT, MOTOR_EN1, MOTOR_HIGH);
}
void Motor1_Disable(void)
{
	DIO_SetPin_Value(MOTOR_CNTRL_PORT, MOTOR_EN1, MOTOR_LOW);
}
void Motor1_CW(void)
{
	DIO_SetPin_Value(MOTOR_DTA_PORT, MOTOR1_A1, MOTOR_HIGH);
	DIO_SetPin_Value(MOTOR_DTA_PORT, MOTOR1_A2, MOTOR_LOW);
}
void Motor1_CCW(void)
{
	DIO_SetPin_Value(MOTOR_DTA_PORT, MOTOR1_A1, MOTOR_LOW);
	DIO_SetPin_Value(MOTOR_DTA_PORT, MOTOR1_A2, MOTOR_HIGH);
}
