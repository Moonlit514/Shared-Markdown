


#ifndef HITFEEDBACK_H
#define HITFEEDBACK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "stm32f10x.h"                  // Device header  
void EXTI_All_Init(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

uint8_t Get_Circle(void);
void Set_Circle(uint8_t circle);
uint8_t CheckButtonChange();

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
