#include "motor.h"
#include "tim.h"
#include "stdio.h"
extern uint32_t mb_speed;		//目标速度

//左前 右前 左后 右后
void motor_back(uint16_t sp)
{	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);

		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,sp);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,sp);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_SET);
	
}

void motor_forward(uint16_t sp)
{
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);

		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,sp);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,sp);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_RESET);
	
}

void motor_right(uint16_t sp)
{
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);

		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,sp);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,sp);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_SET);
	
}

void motor_left(uint16_t sp)
{
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);

		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,sp);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,sp);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,sp);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_RESET);
	
}

void motor(int16_t Spe,int i)
{
	switch(i)
	{
		case 0:__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,Spe);break;
		case 1:__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,Spe);break;
		case 2:__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,Spe);break;
		case 3:__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,Spe);break;
		default:
			break;
	}

}
