/*
 * led.c
 *
 *  Created on: Mar 26, 2025
 *      Author: fbcks
 */


#include "led.h"

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
    GPIO_PinState on_state;
    GPIO_PinState off_state;
}led_table_t;

led_table_t led_table[LED_MAX_CH] =
        {
                {GPIOB, GPIO_PIN_12, GPIO_PIN_RESET, GPIO_PIN_SET},
        };

bool ledInit(void)
{
    bool ret = true;

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();


    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;


    for(int i = 0; i < LED_MAX_CH; i++)
    {
        GPIO_InitStruct.Pin = led_table[i].pin;
        HAL_GPIO_Init(led_table[i].port, &GPIO_InitStruct);

        ledOff(i);
    }

    return ret;
}

void ledOn(uint8_t ch)
{
    if(ch >= LED_MAX_CH)
        return;

    HAL_GPIO_WritePin(led_table[ch].port, led_table[ch].pin, led_table[ch].on_state);
}

void ledOff(uint8_t ch)
{
    if(ch >= LED_MAX_CH)
            return;

    HAL_GPIO_WritePin(led_table[ch].port, led_table[ch].pin, led_table[ch].off_state);
}

void ledToggle(uint8_t ch)
{
    if(ch >= LED_MAX_CH)
            return;

    HAL_GPIO_TogglePin(led_table[ch].port, led_table[ch].pin);
}

