/*
 * ap.c
 *
 *  Created on: Mar 25, 2025
 *      Author: fbcks
 */


#include "ap.h"

volatile uint32_t rcy_led_count = 0;

void apInit(void)
{
    uartOpen(_DEF_UART1, 57600);

}

void apMain(void)
{
    uint32_t prev_time;
    uint32_t prev_baud;
    uint32_t led_blink_time;

    if(isRcyResetPinRead())//pa8 status : pull-up
    {
        rcy_led_count++;
        delay(500);
    }

    if(resetGetCount() == 0)
    {
        led_blink_time = 100;
    }
    else
    {
        led_blink_time = 500;
    }

    prev_baud = uartGetBaud(_DEF_UART1);
    prev_time = millis();

	while(1)
	{
	    if(millis() - prev_time >= led_blink_time)
	    {
	        prev_time = millis();
	        ledToggle(_DEF_LED1);

	        uartPrintf(_DEF_UART1, "ResetCount : %d\n", resetGetCount());
	    }

	    if(uartAvailable(_DEF_UART1) > 0)
	    {
	        uint8_t rx_data;

	        rx_data = uartRead(_DEF_UART1);
	        uartPrintf(_DEF_UART1, "RxData : %c | 0x%X\n", rx_data, rx_data);
	    }

	    if(uartGetBaud(_DEF_UART1) != prev_baud)
        {
            prev_baud = uartGetBaud(_DEF_UART1);
            uartPrintf(_DEF_UART1, "ChangedBaud : %d\n", uartGetBaud(_DEF_UART1));
        }
	}
}
