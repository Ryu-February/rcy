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
        reset_count = rtcBackupRegRead(0);
    }
    rtcBackupRegWrite(0, 0);

    return ret;
}

bool rcyResetInit(void)
{
    bool ret = true;

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    return ret;
}

bool isRcyResetPinRead(/*unsigned char is_pin_valid*/void)
{
    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == GPIN_PIN_RESET)
    {
        return 1;
    }
    return 0;
}

uint32_t resetGetCount(void)
{


    return 0;
}
