
#include "LED.h"
#include "SPI.h"
#include "UART.h"
#include "STD_TYPES.h"

int main(void)
{
	LED0_Initialize();
	LED1_Initialize();
	LED2_Initialize();
    UART_Init();
	SPI_INIT();
	Uint8t dataReceived = 0;

	while (1)
	{
		SPI_RECEIVE(&dataReceived);
		if(dataReceived == 1)
		{
			LED0_ON();
		}
		else if (dataReceived == 2)
		{
			LED1_ON();
	}
		else if (dataReceived == 3)
		{
			LED2_ON();
		}

		else if(dataReceived == 4)
		{
			LED0_OFF();

		}
		else if(dataReceived == 5)
		{
			LED1_OFF();
		}
		else if(dataReceived == 6)
		{
			LED2_OFF();
		}

	}
	return 0;
}

