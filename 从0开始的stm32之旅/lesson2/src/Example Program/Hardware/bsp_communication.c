#include "bsp_communication.h"

void bsp_communication_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void bsp_output_on()
{
    GPIO_SetBits(GPIOB, GPIO_Pin_14);
}

void bsp_output_off()
{
    GPIO_ResetBits(GPIOB, GPIO_Pin_14);
}

uint8_t bsp_input_read()
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
}

