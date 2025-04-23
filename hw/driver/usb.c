/*
 * usb.c
 *
 *  Created on: Apr 1, 2025
 *      Author: fbcks
 */


#include "usb.h"
#include "usb_device.h"


bool usbInit(void)
{
    bool ret = true;

    GPIO_InitTypeDef GPIO_InitStruct = {0};


    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
    delay(200);//100 정도로 너무 짧으면 usb 연결이 처음에 간헐적으로 끊기는 현상이 있음
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);

    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    MX_USB_DEVICE_Init();//usb_cdc

    return ret;
}
