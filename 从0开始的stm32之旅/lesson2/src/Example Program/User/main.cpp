#include "stm32f10x.h" // Device header
#include "led.hpp"
#include "infrared.h"
#include "Delay.h"
#include "rand.h"
#include "HitFeedback.h"
#include "Time.hpp"
#include "CanManager.hpp"
#include "CanMsgDispatcher.hpp"
#include "ChassisCtrlMsg.hpp"
#include "Stream.hpp"
#include "bsp_communication.h"



extern "C" void SysTick_Handler(void);
const uint32_t MS_PRE_TICK = 1;
void SysTick_Handler(void)
{
	__set_PRIMASK(1);
	Time::Tick();
	CanMsgDispatcher::Instance()->Update();
	LED_Update();
	CanManager::Instance()->Update();
	__set_PRIMASK(0);
}

ChassisCtrlMsg* pChassisCtrlMsg = ChassisCtrlMsg::Instance();
int main(void)
{
	Time::Init(MS_PRE_TICK);
	CanManager::Instance()->Init();
	ChassisCtrlMsg::Instance()->Init(CAN1, 0x9C);	
	rand_init();
	EXTI_All_Init();
	LED_Init(RedState);
	while (1)
	{
	}
}

