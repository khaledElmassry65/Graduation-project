/*
 * InOut.c
 *
 * Created: 2/26/2021 11:51:04 AM
 *  Author: karim
 */ 

#include "InOut.h"


void BUTTON0_Initialize(void)
{
	DIO_SetPin_Direction(BUTTON0_PORT, BUTTON0, InOut_INPUT);
}
Uint8t BUTTON0_Read(void)
{
	return DIO_ReadPin_Value(BUTTON0_PORT, BUTTON0);
}
void BUTTON1_Initialize(void);
Uint8t BUTTON1_Read(void);
void BUTTON2_Initialize(void);
Uint8t BUTTON2_Read(void);