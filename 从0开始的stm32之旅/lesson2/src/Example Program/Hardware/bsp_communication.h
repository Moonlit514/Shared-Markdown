#ifndef BSP_COMMUNICATION_H_
#define BSP_COMMUNICATION_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stm32f10x.h"

void bsp_communication_init(void);
void bsp_output_on();
void bsp_output_off();
uint8_t bsp_input_read();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BSP_CAN_H_ */
