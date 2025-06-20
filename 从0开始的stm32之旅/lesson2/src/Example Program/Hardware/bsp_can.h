/**
  ****************************************************************
  * @file    bsp_can.h
  * @author  TofuLemon(5thzhengjiarandom@gmail.com)
  * @date    2020-Jan-13
  ****************************************************************
  */

#ifndef BSP_CAN_H_
#define BSP_CAN_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "misc.h"

uint8_t can1_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BSP_CAN_H_ */
