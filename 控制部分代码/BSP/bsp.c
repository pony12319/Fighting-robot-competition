#include "BSP.h"
#include "tim.h"
#include "usart.h"
#include "ITR.h"
#include "oled.h"
#include "PID.h"
#include "ITR.h"

extern PID speedpid;
u8 flagss=0;
void bsp(void)
{
//���PWMʹ��
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
//������ʹ��	
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL); //����������ģʽ
  HAL_TIM_Base_Start_IT(&htim3);                  //�������������ж�
	
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL); //����������ģʽ
  HAL_TIM_Base_Start_IT(&htim4);                  //�������������ж�
	
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL); //����������ģʽ
  HAL_TIM_Base_Start_IT(&htim1);                  //�������������ж�
	
	HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL); //����������ģʽ
  HAL_TIM_Base_Start_IT(&htim8);                  //�������������ж�

//������������ʱ�����ж�
	HAL_TIM_Base_Start_IT(&htim6);
	HAL_TIM_Base_Start_IT(&htim7);
 	PID_Init(&speedpid, 1.0, 0, 1.0, 7000);
	
//	if(itr_8 == Y_target && itr_9 == Y_target)
//	{
//		start();
//		flagss=1;
//	}
	
}

