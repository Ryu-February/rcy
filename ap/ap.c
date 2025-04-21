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

    prev_time = millis();

	while(1)
	{
	    if(millis() - prev_time >= 500)
	    {
	        prev_time = millis();
	        ledToggle(_DEF_LED1);
	    }

	    if(uartAvailable(_DEF_UART1) > 0)
		{
			uint8_t rx_data;

			rx_data = uartRead(_DEF_UART1);

			if(rx_data == '1')
			{
				uint8_t buf[32];

				logPrintf("Read...\r\n");

				flashRead(0x8000000 + (60 * 1024), buf, 32);

				for(int i = 0; i < 32; i++)
				{
					logPrintf("0x%X : 0x%X\r\n", 0x8000000 + (60 * 1024) + i, buf[i]);
				}
			}

			if(rx_data == '2')
			{
				logPrintf("Erase...\r\n");

				if(flashErase(0x8000000 + (60 * 1024), 32) == true)
				{
					logPrintf("Erase OK\r\n");
				}
				else
				{
					logPrintf("Erase Fail\r\n");
				}
			}

			if(rx_data == '3')
			{
				uint8_t buf[32];

				for(int i = 0; i < 32; i++)
				{
					buf[i] = i;
				}

				logPrintf("Write...\r\n");

				if(flashWrite(0x8000000 + (60 * 1024), buf, 32) == true)
				{
					logPrintf("Write OK\r\n");
				}
				else
				{
					logPrintf("Write Fail\r\n");
				}
			}
		}
	}


}
