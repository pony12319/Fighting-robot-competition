#ifndef __MOTOR_H
#define __MOTOR_H

#include "main.h"

void motor(int16_t Spe,int i);
void motor_forward(uint16_t sp);
void motor_back(uint16_t sp);
void motor_left(uint16_t sp);
void motor_right(uint16_t sp);

#endif
