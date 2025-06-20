#ifndef __TIMER_H__
#define __TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
void Timer_Init(void);
void Timer_reset(void);
void TIM4_StartCounter(void);
uint16_t TIM4_GetCounter(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
