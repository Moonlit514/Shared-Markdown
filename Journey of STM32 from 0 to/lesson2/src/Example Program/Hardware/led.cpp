#include <stm32f10x.h>
#include "led.hpp"
#include "pattern.h"
#include "timer.h"
#include "rand.h"
#include "HitFeedBack.h"
#include "bsp_communication.h"
#include "Time.hpp"
#include "bsp_can.h"
#include "ChassisCtrlMsg.hpp"
#include "CanMsgDispatcher.hpp"

uint8_t debug = 0;  //debug = 1模式下叶片不会2.5s切换，方便视觉对同一个叶片持续调参
uint8_t timeout = 0;       // 如果时间到了(2.5s)，timeout = 1，由定时器硬件中断修改
uint8_t refresh_rectangle = 0; // 如果刷新灯板（指的是让长方形灯板里面的箭头流动起来）时间到了，refresh_rectangle = 1，由定时器中硬件中断修改
uint8_t leaf_ring_value = 0;   //取值范围0-4，分别对应2环，4环，6环，8环，10环(这些环数比较粗略，而且10环弄错了，我这里没有定义10环的图案，这个后续跟据情况改吧)
//static LED_Leaf_Name_t current_Refresh_Leaf = LEAF_0; // 默认为第一片叶子,表示当前在刷新的扇叶

static RGB_t leds[LED_NUM];    //存放led点亮数据的地方
//static RGB_t R_logo[64];   //存放R标的数据

LED_Leaf_Mode_t leafmode= LEAF_STRIKING; //存放每片叶子当前的状态，默认为关闭
RGB_t current_color = {0, 0, 0}; //变量，表示这片叶子亮哪方的颜色（其实有后面的LED_State就可以判断了，但是为了减轻CPU负担，尽量在颜色判断上只在初始化的时候判断一次）


LED_State_t LED_State = RedState; //能量机关默认为红方模式
uint8_t currentLeafStruck = 0; //当前叶子是否击中了
LED_Leaf_Name_t current_striking_leaf = LEAF_0; //当前击打的扇叶
uint8_t total_struck = 0; //总共击打的次数

uint8_t last_time_circle = 0;
uint16_t led_index = 0;
RGB_t dim_red = {100, 0, 0};  //靶心的颜色
RGB_t red = {170, 0, 0};   //目前发现亮度太高好像会出现电流比较大导致信号线受到干扰的情况，所以把颜色调暗了一些

extern ChassisCtrlMsg* m_ctrlMsg;

void LED_Init(LED_State_t state)
{
    ws2812b_Init();
    LED_State = state;
    current_color = (LED_State == RedState ? red : blue);
}

void LED_PackLightALLData(void)
{
    current_color = dim_red;
    for (uint16_t i = 0; i < LED_NUM; i++)
    {
        leds[i] = current_color;
    }
}

void LED_PackRectangleData(LED_Leaf_Mode_t leafmode, RGB_t *dst)
{
    static uint8_t count = 4;
    switch (leafmode)
    {
    case LEAF_OFF:
        for (uint16_t i = 0; i < 256; i++)
        {
            dst[i] = off;
        }
        break;
    case LEAF_STRIKING:
        // 对于移动箭头，每移动4次就会回到初始位置
        if(Time::GetTick()%100 == 0) //(refresh_rectangle == 1)
        {
            count--;
        }
        if (count > 0)
        {
            refresh_rectangle = 0; // 硬件置0(定时器中断)，软件清0
        }
        else if (count == 0)
        {
            count = 4;
            refresh_rectangle = 0;
        }
        for (uint16_t i = 0; i < 256; i++)
        {

            if ((i + count * 8 < 256) && RECTANGLE_ARROWS[i + count * 8])
            {
                dst[i] = current_color;
            }
            else if ((i + count * 8 >= 256) && RECTANGLE_ARROWS[i + count * 8 - 256])
            {
                dst[i] = current_color;
            }
            else
            {
                dst[i] = off;
            }
        }
        break;
    case LEAF_STRUCK:
        for (uint16_t i = 0; i < 256; i++)
        {
            dst[i] = current_color;
        }
        break;
    default:
        break;
    }
}

void LED_PackStripData(LED_Leaf_Mode_t leafmode, RGB_t *dst)
{
    switch (leafmode)
    {
    case LEAF_OFF:
        for (uint8_t i = 0; i < 50; i++)
        {
            dst[i] = off;
        }
        break;
    case LEAF_STRIKING:
        for (uint8_t i = 0; i < 50; i++)
        {
            dst[i] = off;
        }
        break;
    case LEAF_STRUCK:
        for (uint8_t i = 0; i < 50; i++)
        {
            dst[i] = current_color;
        }
        break;
    default:
        break;
    }
}

void LED_PackFrameData1(LED_Leaf_Mode_t leafmode, RGB_t *dst)
{
    switch (leafmode)
    {
    case LEAF_OFF:
        for (uint8_t i = 0; i < UP_LED_NUM; i++)//num=135
        {
            dst[i] = off;
        }
    case LEAF_STRIKING:
        for (uint8_t i = 0; i < UP_LED_NUM; i++)
        {
            dst[i] = current_color;
        }
        break;
    case LEAF_STRUCK:
        for (uint8_t i = 0; i < UP_LED_NUM; i++)
        {
            dst[i] = current_color;
        }
        break;
    default:
        break;
    }
}

uint16_t debug_index = 0;
void LED_PackFrameData2(LED_Leaf_Mode_t leafmode, RGB_t *dst)
{
    if(LED_State == BlueState)
    {
        current_color = blue;
    }
    else
    {
        current_color =  red;
    }

    for(uint16_t i=0;i < 64;i++)//pack R logo in *dst
    {
        dst[i+DOWN_LED_NUM +UP_LED_NUM] = current_color;
    }

    switch (leafmode)
    {
    case LEAF_OFF:
        for (uint16_t i = 0; i < DOWN_LED_NUM +UP_LED_NUM; i++)
        {
            dst[i] = off;
        }
        break;
    case LEAF_STRIKING:
        for (uint16_t i = 0; i < DOWN_LED_NUM +UP_LED_NUM; i++)
        {
            dst[i] = current_color;
        }
        break;
    case LEAF_STRUCK:
        for (uint16_t i = 0; i < DOWN_LED_NUM + UP_LED_NUM; i++)
        {
            dst[i] = current_color;
        }
        break;
    default:
        break;
    }
}
void LED_PackTargetData(LED_Leaf_Mode_t leafmode, RGB_t *dst)
{
    static RGB_t target_color = {150, 0, 0};   //靶心的颜色,和dim_red一样
    if(LED_State == BlueState)
    {
        target_color = dim_blue;
    }
    else
    {
        target_color = dim_red;
    }

    unsigned char *target_struckRing_ptr;
    switch (leafmode)
    {
    case LEAF_OFF:
        for (uint16_t i = 0; i < 274; i++)
        {
            dst[i] = off;
        }
        break;
    case LEAF_STRIKING:
        for (uint16_t i = 0; i < 274; i++)
        {
            if (TARGET_STRIKING[i])
            {
                dst[i] = target_color;
            }
            else
            {
                dst[i] = off;
            }
        }
    case LEAF_STRUCK:

        switch (Get_Circle())
        {
            
            case 0:
                break;
            case 1:
                target_struckRing_ptr = TARGET_STRUCK_Ring[0];
                break;
            case 2:
                target_struckRing_ptr = TARGET_STRUCK_Ring[1];
                break;
            case 3:
                target_struckRing_ptr = TARGET_STRUCK_Ring[2];
                break;
            case 4:
                target_struckRing_ptr = TARGET_STRUCK_Ring[3];
                break;
            case 5:
                target_struckRing_ptr = TARGET_STRUCK_Ring[4];
                break;
            case 6:
                target_struckRing_ptr = TARGET_STRUCK_Ring[5];
                break;
            case 7:  
                target_struckRing_ptr = TARGET_STRUCK_Ring[6];
                break;
            case 8:
                target_struckRing_ptr = TARGET_STRUCK_Ring[7];
                break;
            case 9: 
                target_struckRing_ptr = TARGET_STRUCK_Ring[8];
                break;
            case 10:
                target_struckRing_ptr = TARGET_STRUCK_Ring[9];
                break;
            
            default:
                break;
        }
    if(Get_Circle()<11 && Get_Circle()>0 )
    {
        for (uint16_t i = 0; i < 274; i++)
        {
            if (target_struckRing_ptr[i])
            {
                dst[i] = target_color;
            }
            else
            {
                dst[i] = off;
            }
        }   
    } 
    default:
        break;
    }
}

void LED_Update(void)
{
		CanMsgDispatcher::Instance()->Update();
    if (leafmode == LEAF_OFF)
     {
        if (ChassisCtrlMsg::Instance()->GetIsOpen())
        {
            Set_Circle(0);
            leafmode = LEAF_STRIKING;
        }
     }
	  if (leafmode == LEAF_STRIKING && ChassisCtrlMsg::Instance()->GetIsOpen())
    {    
        if (CheckButtonChange()==1)
        {
            leafmode = LEAF_STRUCK;
        }

    }
    if (leafmode == LEAF_STRUCK)
    {
        ChassisCtrlMsg::Instance()->Setfdbmsg(0x01);
        ChassisCtrlMsg::Instance()->Update();
    }
    				
    LED_PackRectangleData(leafmode, leds);
    LED_PackTargetData(leafmode, leds + 256);
    LED_PackFrameData2(leafmode, leds + 274 + 256);//include R

    if(Time::GetTick()%50 == 0) 
    {
        if(ws2812b_IsReady())
        ws2812b_H3_SendRGB(leds, 256);
    }
    else if(Time::GetTick()%50 == 10)
    {
        if(ws2812b_IsReady())
        ws2812b_H8_SendRGB(leds + 256, 274);
    }
    else if(Time::GetTick()%50 == 20)
    {
        if(ws2812b_IsReady())
        ws2812b_H6_SendRGB(leds + 256 + 274, DOWN_LED_NUM);
    }
    else if(Time::GetTick()%50 == 30)
    {
        if(ws2812b_IsReady())
        ws2812b_H4_SendRGB(leds + 256 + 274 + DOWN_LED_NUM, UP_LED_NUM);
    }
    else if(Time::GetTick()%50 == 40)
    {
        if(ws2812b_IsReady())
        ws2812b_SW1_SendRGB(leds + 256 + 274 + DOWN_LED_NUM + UP_LED_NUM, 64);// R_logo
    }
}
