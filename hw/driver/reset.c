/*
 * reset.c
 *
 *  Created on: Apr 1, 2025
 *      Author: fbcks
 */


#include "reset.h"
#include "rtc.h"


static uint32_t reset_count = 0;


bool resetInit(void)
{
    bool ret = true;

    //if reset pin pressed
    if(RCC->CSR & (1 << 26))
    {
        rtcBackupRegWrite(1, rtcBackupRegRead(1) + 1);//increase 1
        delay(500);
        reset_count = rtcBackupRegRead(1);
    }
    rtcBackupRegWrite(1, 0);

    return ret;
}

uint32_t resetGetCount(void)
{


    return 0;
}
