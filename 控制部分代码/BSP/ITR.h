#ifndef __ITR_H
#define __ITR_H

#include "main.h"
//////////////////////��Ե///////////////////////////
#define itr_1 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)   
#define itr_2 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)   
#define itr_3 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)   
#define itr_4 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)   
//////////////////////����///////////////////////////
#define itr_5 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_12)   
#define itr_6 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11) 

#define itr_7 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)  

#define itr_8 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)  
#define itr_9 		HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)  
///////////////////////�м�/////////////////////////
#define itr_10 		HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)  
#define itr_11 		HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4)  
//////////////////////״̬///////////////////////////
#define N_target 1
#define Y_target 0

void State_Edge(void);		//��̨���ؼ��
void Scan_target(void);			//������
void Open_MV_Move(void);			//�Ӿ�����
void start(void);				//����
void state_down(void);			//��̨����

#endif


