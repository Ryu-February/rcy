/*
 * ap.c
 *
 *  Created on: Mar 25, 2025
 *      Author: fbcks
 */


#include "ap.h"


extern uint32_t cdcAvailable(void);
extern uint8_t cdcDequeue(void);
extern void cdcEnqueue(uint8_t rx_data);
extern uint32_t cdcWrite(uint8_t *p_data, uint32_t length);

void apInit(void)
{

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

	    if(cdcAvailable() > 0)
	    {
	        uint8_t rx_data;

	        rx_data = cdcDequeue();
	        cdcWrite((uint8_t *)"RX_data : ", 11);
	        cdcWrite(&rx_data, 1);
	        cdcWrite((uint8_t *)"\n", 2);
	    }
	}
}
