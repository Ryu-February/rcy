/*
 * led.c
 *
 *  Created on: Mar 26, 2025
 *      Author: fbcks
 */


#include "led.h"
#include "cli.h"

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

#ifdef _USE_HW_CLI
	static void cliLed(cli_args_t *args);
#endif

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
#ifdef _USE_HW_CLI
    cliAdd("led", cliLed);
#endif

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


#ifdef _USE_HW_CLI

void cliLed(cli_args_t *args)
{
	bool ret = false;


	if(args->argc == 3 && args->isStr(0, "toggle") == true)
	{
		uint8_t led_ch;
		uint32_t toggle_time;
		uint32_t prev_time;

		led_ch 		= (uint8_t)args->getData(1);
		toggle_time = (uint32_t)args->getData(2);


		if(led_ch > 0)
		{
			led_ch--;
		}

		prev_time = millis();
		while(cliKeepLoop())
		{
			if(millis() - prev_time >= toggle_time)
			{
				prev_time = millis();
				ledToggle(led_ch);
			}
		}

		ret = true;
	}

	if(ret != true)
	{
		cliPrintf("led toggle ch[1 ~ %d] time_ms\r\n", LED_MAX_CH);
	}
}

#endif
