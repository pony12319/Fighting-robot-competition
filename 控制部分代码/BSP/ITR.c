#include "ITR.h"
#include "tim.h"
#include "motor.h"
#include "RX.h"
#include "main.h"

extern unsigned int time;
extern uint8_t OPenMv_RX_Flag,This_Id;


void start(void)				//启动
{
		motor_back(3500);
		while(itr_3 == Y_target && itr_4 == Y_target);
			HAL_Delay(900);
		motor_back(6000);
			HAL_Delay(800);

			motor_left(turn_speed);
		HAL_Delay(130);
	
//		motor_back(6000);
//		HAL_Delay(500);
}
void State_Edge(void)		//擂台边沿检测
{
	if( itr_1 == N_target || itr_2 == N_target || itr_3 == N_target || itr_4 == N_target )
	{
		if(itr_1 == N_target || itr_2 == N_target)
		{
			time=0;
			motor_back(set_speed_b);
			HAL_Delay(200);
			while(itr_1 == N_target && itr_2 == N_target);
			if(itr_3 == Y_target && itr_4 == Y_target)
		{
			motor_left(turn_speed);
			HAL_Delay(100);
		}
			//while(time<=200);	
		}
		else if(itr_3 == N_target || itr_4 == N_target)
		{
			motor_forward(6000);
			while(itr_3 == N_target && itr_3 == N_target);
		}
	}
}
void Open_MV_Move(void)			//视觉处理
{
	if(This_Id == 1)
	{
		if(OPenMv_RX_Flag == 0)
		{
			motor_right(turn_speed);
			//delay_ms(Pid);
		}
		else if(OPenMv_RX_Flag == 1)
		{
			motor_forward(set_speed_b);
			if( itr_5 == Y_target || itr_6 == Y_target)
				motor_forward(set_speed_b);
		}
		else if(OPenMv_RX_Flag == 2)
		{
			motor_left(turn_speed);
			//delay_ms(Pid);
		}
	}
	else if(This_Id == 2)
	{
			if(OPenMv_RX_Flag == 0)
		{
			motor_left(turn_speed);
			HAL_Delay(130);
			//delay_ms(Pid);
		}
		else if(OPenMv_RX_Flag == 1)
		{
			motor_left(turn_speed);
			HAL_Delay(130);
		}
		else if(OPenMv_RX_Flag == 2)
		{
			motor_right(turn_speed);
			HAL_Delay(130);
			//delay_ms(Pid);
		}
	}
	else if( This_Id == 0)
	{
		Scan_target();
	}
}

void Scan_target(void)			//物体检测
{
		if( itr_5 == Y_target || itr_6 == Y_target )
			motor_forward(set_speed_b);
		else if(itr_5 == N_target && itr_6 == N_target && itr_8 == N_target &&itr_9 == N_target)
			motor_forward(set_speed_b);
		else if(itr_9 == Y_target )
		{
			motor_right(turn_speed);//右边检测到物块，向右转
			time = 0;
			while( This_Id != 1 && (itr_5 == N_target || itr_6 == N_target))
			{
				if( This_Id == 1 || This_Id == 3||time>120)
				break;
			}
		}		
		else if(itr_8 == Y_target )
		{
			motor_left(turn_speed);//右边检测到物块，向右转
			time = 0;
			while( This_Id != 1 && (itr_5 == N_target || itr_6 == N_target))
			{
				if( This_Id == 1 || This_Id == 3||time>120)
				break;
			}
		}
}

void state_down(void)			//掉台处理
{
//	motor_back(0);
		if(itr_5 == Y_target && itr_6 == Y_target && itr_10 == N_target)
		{
			motor_forward(2000);
			HAL_Delay(1000);
			start();
		} 
		else 
		{
			motor_left(4000);
				if((itr_5 == Y_target || itr_6 == Y_target) && itr_10 == N_target)
			{
				motor_forward(2000);
				HAL_Delay(1000);
				start();
			}
		}
}