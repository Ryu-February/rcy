/*
 * ap.c
 *
 *  Created on: Mar 25, 2025
 *      Author: fbcks
 */


#include "ap.h"


void apInit(void)
{
    uartOpen(_DEF_UART1, 57600);
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
	}
}
