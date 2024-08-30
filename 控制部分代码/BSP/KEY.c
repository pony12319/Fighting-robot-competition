#include "KEY.h"
#include "tim.h"
#include "oled.h"
#include "PID.h"
#include "motor.h"
#include "oled.h"

PID speedpid;
unsigned int time = 0;
uint16_t time_cnt=0;
uint8_t Count_2ms,Count_5ms,Count_8ms,Count_10ms,Count_20ms,Count_200ms;

struct keys key[4]={0,0,0,0};
int16_t set_speed[4] = {0};

float mb_speed=3400;		//目标速度

float k1=0,k2=0,k3=0,k4=0;

float Get_Speed(TIM_HandleTypeDef *htim)
{
    int16_t zj;
		float The_Speed = 0;
    zj = __HAL_TIM_GetCounter(htim);//获取计数值
    __HAL_TIM_SetCounter(htim, 0);//清空计数值
    The_Speed= (float)zj / (4 * 96) * 100 * 60;//计算转速

    return  The_Speed;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{	
//		if(htim->Instance==TIM14)
//	{
//		time_cnt++;
//		key[0].key_sta=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3);
//		key[1].key_sta=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4);
//		key[2].key_sta=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_5);
//		key[3].key_sta=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_6);

//		for(int i=0;i<4;i++)
//		{
//			switch(key[i].judge)
//			{
//				case 0:
//				{
//					if(key[i].key_sta==0)
//					{
//						key[i].judge=1;
//						key[i].time_cont=0;
//					}
//				}break;
//				case 1:
//				{
//					if(key[i].key_sta==0)
//					{
//						key[i].time_cont++;
//						key[i].judge=2;
//					}
//				}break;
//				case 2:
//				{
//					if(key[i].key_sta==1)
//					{
//							key[i].judge=0;
//						if(key[i].time_cont<100)
//							key[i].flage=1;
//					}
//					else
//					{
//						key[i].time_cont++;
//						if(key[i].time_cont>100)
//						{
//							key[i].flage=2;
//							key[i].time_cont=0;
//						}
//					}
//				}break;
//			}
//		}
//	}
//	//编码器
//		int16_t zj;
		if(htim->Instance == TIM7)
		{
			time++;
			Count_2ms++;
			Count_5ms++;
			Count_8ms++;
			Count_10ms++;
			Count_20ms++;
			Count_200ms++;
		}
//    else if (htim->Instance == TIM6)
//    {//10ms中断
//			k1 = Get_Speed(&htim1);
//      k2 = Get_Speed(&htim3);
//			k3 = Get_Speed(&htim4);
//			k4 = Get_Speed(&htim8);

//      set_speed[0] = PID_Incremental_Calc(&speedpid, mb_speed,k1);//PID
//			set_speed[1] = PID_Incremental_Calc(&speedpid, mb_speed,k2);//PID
//      set_speed[2] = PID_Incremental_Calc(&speedpid, mb_speed,k3);//PID
//      set_speed[3] = PID_Incremental_Calc(&speedpid, mb_speed,k4);//PID

////			for(int i=0;i<4;i++)
////			{
////        if (set_speed[i] > 5000)
////            set_speed[i] = 5000;
////        else if (set_speed[i] < -5000)
////            set_speed[i] = -5000;//限幅
////				
//// //       if (set_speed[i] > 500 || set_speed[i] < -500)//死区控制,改善电机异响
////            motor(set_speed[i],i);
////			}
//       //printf("%f,%d,%d\r\n", k4,set_speed[3],mb_speed);//打印当前和目标转速
//    }
}




