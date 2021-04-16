#include "LED.h"
#include "SPI.h"
#include "UART.h"
#include "STD_TYPES.h"
int main(void)
{
	UART_Init();
	Uint8t dataSent =1;
	SPI_Init();
	SPI_SlaveSelect(0);

	while (1)
	{
		dataSent = UART_Receive()-0x30;
		SPI_Transmit(dataSent);

	}
	return 0;
}
