#ifndef __KEY_H
#define __KEY_H

#include "main.h"

struct keys
{
	char key_sta;
	char judge;
	char flage;
	uint16_t time_cont;
};

float Get_Speed(TIM_HandleTypeDef *htim);
void key_proc(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif
