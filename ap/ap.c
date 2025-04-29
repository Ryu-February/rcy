/*
 * ap.c
 *
 *  Created on: Mar 25, 2025
 *      Author: fbcks
 */


#include "ap.h"


void apInit(void)
{
    uartOpen(_DEF_UART1, 57600);//USB
    uartOpen(_DEF_UART2, 57600);//UART

    cliOpen(_DEF_UART1, 57600);
    cliOpenLog(_DEF_UART2, 57600);
}

void apMain(void)
{
    uint32_t prev_time;

    prev_time = millis();

	while(1)
	{
	    if(millis() - prev_time >= 500)
	    {
	        prev_time = millis();
	        ledToggle(_DEF_LED1);
	    }

	    if (uartAvailable(_DEF_UART2) > 0)
		{
		  uint8_t rx_data;
		  rx_data = uartRead(_DEF_UART2);

		  uartPrintf(_DEF_UART2, "Rx : 0x%X\r\n", rx_data);
		}

		cliMain();
	}
}
