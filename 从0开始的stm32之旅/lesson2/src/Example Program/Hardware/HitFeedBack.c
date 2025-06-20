#include "stm32f10x.h"                  // Device header
#include "HitFeedback.h"
#include "Delay.h"
#include "rand.h"

void EXTI_All_Init(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7 ;					
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_6 | GPIO_Pin_11 | GPIO_Pin_10 ;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;
	// GPIO_Init(GPIOC, &GPIO_InitStructure);

	//开启复用IO口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE)
	
	//初始化io输入函数，这里我们可以用按键作为输入
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource4);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource5);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource2);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource7);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource10);//设置IO口与中断线的映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);//设置IO口与中断线的映射

	//设置IO口与中断线的映射


	//初始化线上中断，设置触发条件
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line11 | EXTI_Line10 | EXTI_Line4 | EXTI_Line5  |  EXTI_Line7 | EXTI_Line3 | EXTI_Line0 | EXTI_Line1 | EXTI_Line2 | EXTI_Line6;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//选择中断还是事件触发模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//选择下降沿
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	//配置中断函分组（NVIC），并使能
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x15;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x15;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x15;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x15;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x15;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x15;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x15;
	NVIC_Init(&NVIC_InitStructure);

}
	
uint8_t Circle = 0;


void EXTI2_IRQHandler(void)
{
	if( EXTI_GetFlagStatus(EXTI_Line2)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)==0)
		{
			Circle=8+16;
		}
	}
	EXTI_ClearFlag(EXTI_Line2);
}

void EXTI0_IRQHandler(void)
{
	if( EXTI_GetFlagStatus(EXTI_Line0)  == SET) 
	{
	    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0)
		{
			Circle=6+16;
		}
	}
	EXTI_ClearFlag(EXTI_Line0);
}

void EXTI1_IRQHandler(void)
{
	if( EXTI_GetFlagStatus(EXTI_Line1)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
		{
			Circle=7+16;
		}
	}
	EXTI_ClearFlag(EXTI_Line1);
}

void EXTI3_IRQHandler(void)
{
	if( EXTI_GetFlagStatus(EXTI_Line3)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==0)
		{
			Circle=1+16;
		}
		EXTI_ClearFlag(EXTI_Line3);
	}
}

void EXTI4_IRQHandler(void)
{
	if( EXTI_GetFlagStatus(EXTI_Line4)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0)
		{
			Circle=2+16;
		}
		EXTI_ClearFlag(EXTI_Line4);
	}
}
void EXTI9_5_IRQHandler(void)
{
	if( EXTI_GetFlagStatus(EXTI_Line7)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0)
		{
			Circle=5+16;
		}
		EXTI_ClearFlag(EXTI_Line5);
	}

	else if( EXTI_GetFlagStatus(EXTI_Line6)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0)
		{
			Circle=4+16;
		}
		EXTI_ClearFlag(EXTI_Line6);
	}

	else if( EXTI_GetFlagStatus(EXTI_Line5)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
		{
			Circle=3+16;
		}
		EXTI_ClearFlag(EXTI_Line5);
	}
}

void EXTI15_10_IRQHandler(void)
{
	if( EXTI_GetFlagStatus(EXTI_Line10)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)==0)
		{
			Circle=9+16;
		}
		EXTI_ClearFlag(EXTI_Line10);
	}
	

	else if( EXTI_GetFlagStatus(EXTI_Line11)  == SET) 
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
		{
			Circle=10+16;
		}
		EXTI_ClearFlag(EXTI_Line11);
	}

}

uint8_t Get_Circle(void)
{
	return Circle;
}

void Set_Circle(uint8_t circle)
{
	Circle = circle;
}

uint8_t CheckButtonChange()
{
    if (Get_Circle() > 16)//有按键按下
    {
        Set_Circle(Get_Circle() - 16);
        return 1;
    }
    return 0;
}
