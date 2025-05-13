/*
 * hw.c
 *
 *  Created on: Mar 25, 2025
 *      Author: fbcks
 */


#include "hw.h"



void hwInit(void)
{
	bspInit();
	cliInit();
	rtcInit();

	resetInit();
	ledInit();
	usbInit();
	uartInit();
	flashInit();
}
