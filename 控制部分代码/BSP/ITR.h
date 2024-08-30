#ifndef __ITR_H
#define __ITR_H

#include "main.h"
//////////////////////边缘///////////////////////////
#define itr_1 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)   
#define itr_2 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)   
#define itr_3 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)   
#define itr_4 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)   
//////////////////////四周///////////////////////////
#define itr_5 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_12)   
#define itr_6 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11) 

#define itr_7 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)  

#define itr_8 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)  
#define itr_9 		HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)  
///////////////////////中间/////////////////////////
#define itr_10 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)  
#define itr_11 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4)  
//////////////////////状态///////////////////////////
#define N_target 1
#define Y_target 0

void State_Edge(void);		//擂台边沿检测
void Scan_target(void);			//物体检测
void Open_MV_Move(void);			//视觉处理
void start(void);				//启动
void state_down(void);			//掉台处理

#endif


