#ifndef __BSP_H
#define __BSP_H

#include "main.h"

void bsp(void);
void pwm_set(TIM_HandleTypeDef *htim);
void update_com_reg(float ta);


#endif

