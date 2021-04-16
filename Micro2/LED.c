/*
* LED.c
*
* Created: 2/26/2021 11:30:48 AM
*  Author: karim
*/

/*
What should i write in source file?
1- Macros
2- Implementation of functions
*/

#include "LED.h"

void LED0_Initialize(void)
{
	//SET_BIT(DDRC, PC2);//Define direction
	//DIO_SetDirection(18, DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(LED0_PORT, LED0_PIN, LED_OUTPUT);//Define direction
}
void LED0_ON(void)
{
	//SET_BIT(LED0_PORT, LED0_PIN);
	//DIO_SetValue(18, LED_HIGH);
	DIO_SetPin_Value(LED0_PORT, LED0_PIN, LED_HIGH);
}
void LED0_OFF(void)
{
	//CLR_BIT(LED0_PORT, LED0_PIN);
	//DIO_SetValue(18, LED_LOW);
	DIO_SetPin_Value(LED0_PORT, LED0_PIN, LED_LOW);
}
void LED0_TGL(void)
{
	//TGL_BIT(LED0_PORT, LED0_PIN);
	DIO_TogglePin(LED0_PORT, LED0_PIN);
}


void LED1_Initialize(void){

	DIO_SetPin_Direction(LED1_PORT,LED1_PIN,LED_OUTPUT)	;

}

void LED1_ON(void){

	DIO_SetPin_Value(LED1_PORT,LED1_PIN,LED_HIGH);

}
void LED1_OFF(void){

	DIO_SetPin_Value(LED1_PORT,LED1_PIN,LED_LOW);

}
void LED1_TGL(void){

	DIO_TogglePin(LED1_PORT,LED1_PIN);

}



void LED2_Initialize(void){

	DIO_SetPin_Direction(LED2_PORT, LED2_PIN , LED_OUTPUT);
}
void LED2_ON(void){

	DIO_SetPin_Value(LED2_PORT,LED2_PIN,LED_HIGH);

}
void LED2_OFF(void){
	DIO_SetPin_Value(LED2_PORT,LED2_PIN,LED_LOW);

}
void LED2_TGL(void){
	DIO_TogglePin(LED2_PORT,LED2_PIN);

}


