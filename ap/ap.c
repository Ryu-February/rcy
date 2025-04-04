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
}

void apMain(void)
{
    uint32_t prev_time;
    uint8_t rx_buf[128];
    uint32_t rx_len;

    prev_time = millis();

	while(1)
	{
	    if(millis() - prev_time >= 500)
	    {
	        prev_time = millis();
	        ledToggle(_DEF_LED1);
	    }

	    if(uartGetBaud(_DEF_UART1) != uartGetBaud(_DEF_UART2))
	    {
	    	uartOpen(_DEF_UART2, uartGetBaud(_DEF_UART1));
	    }

	    //USB -> UART
	    rx_len = uartAvailable(_DEF_UART1);
	    if(rx_len > 128)
	    {
	    	rx_len = 128;
	    }
	    if(rx_len > 0)
	    {
	    	for(int i = 0; i < rx_len; i++)
	    	{
	    		rx_buf[i] = uartRead(_DEF_UART1);
	    	}
	    	uartWrite(_DEF_UART2, rx_buf, rx_len);
	    }

	    //UART ->USB
	    rx_len = uartAvailable(_DEF_UART2);
		if(rx_len > 128)
		{
			rx_len = 128;
		}
		if(rx_len > 0)
		{
			for(int i = 0; i < rx_len; i++)
			{
				rx_buf[i] = uartRead(_DEF_UART2);
			}
			uartWrite(_DEF_UART1, rx_buf, rx_len);
		}
	}
}
