/*
* KEYPAD.c
*
* Created: 11/20/2020 8:03:56 PM
*  Author: karim
*/

#include "KEYPAD.h"
/*Array of keypad*/
const Uint8t KEYPAD [4][4]=
{
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','*'},
	{'A','0','=','/'}
};
/*Initialization function*/
void KEYPAD_Init(void)
{
	/*Define Direction For output pins for keypad*/
	DIO_SetPin_Direction(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN0, DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN1, DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN2, DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN3, DIO_PIN_OUTPUT);
	DIO_SetPin_Value(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN0, DIO_PIN_HIGH);
	DIO_SetPin_Value(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN1, DIO_PIN_HIGH);
	DIO_SetPin_Value(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN2, DIO_PIN_HIGH);
	DIO_SetPin_Value(KEYPAD_OUT_PORT, KEYPAD_OUT_PIN3, DIO_PIN_HIGH);
	/*Define Direction For input Pins for Keypad*/
	DIO_SetPin_Direction(KEYPAD_INP_PORT, KEYPAD_INP_PIN0, DIO_PIN_INPUT);
	DIO_SetPin_Direction(KEYPAD_INP_PORT, KEYPAD_INP_PIN1, DIO_PIN_INPUT);
	DIO_SetPin_Direction(KEYPAD_INP_PORT, KEYPAD_INP_PIN2, DIO_PIN_INPUT);
	DIO_SetPin_Direction(KEYPAD_INP_PORT, KEYPAD_INP_PIN3, DIO_PIN_INPUT);
	DIO_SetPull_Up(KEYPAD_INP_PORT, KEYPAD_INP_PIN0);
	DIO_SetPull_Up(KEYPAD_INP_PORT, KEYPAD_INP_PIN1);
	DIO_SetPull_Up(KEYPAD_INP_PORT, KEYPAD_INP_PIN2);
	DIO_SetPull_Up(KEYPAD_INP_PORT, KEYPAD_INP_PIN3);
}
/*Read Function*/
Uint8t KEYPAD_READ(void)
{
	Uint8t LOC_ROW = 0;
	Uint8t LOC_COL = 0;
	Uint8t temp = 0, Val = 0;
	for(LOC_COL = COL_INIT; LOC_COL <= COL_FINAL; LOC_COL++)
	{
		DIO_SetPin_Value(KEYPAD_OUT_PORT, LOC_COL, DIO_PIN_LOW);
		for(LOC_ROW = ROW_INIT; LOC_ROW <= ROW_FINAL; LOC_ROW++)
		{
			temp = DIO_ReadPin_Value(KEYPAD_INP_PORT, LOC_ROW);
			if(!temp)
			{
				Val = KEYPAD[LOC_ROW - ROW_INIT][LOC_COL - COL_INIT];
				while (!temp)
				{
					temp = DIO_ReadPin_Value(KEYPAD_INP_PORT, LOC_ROW);
				}
				_delay_ms(10);
			}
		}
		DIO_SetPin_Value(KEYPAD_OUT_PORT, LOC_COL, DIO_PIN_HIGH);
	}
	return Val;
}