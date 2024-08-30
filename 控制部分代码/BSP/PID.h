#ifndef __PID_H
#define __PID_H


#include "main.h"              


typedef struct PID {
		float  Kp;         //  Proportional Const  Pϵ��
		float  Ki;           //  Integral Const      Iϵ��
		float  Kd;         //  Derivative Const    Dϵ��
		
		float  PrevError ;          //  Error[-2]  
		float  LastError;          //  Error[-1]  
		float  Error;              //  Error[0 ]  
		float  DError;            //pid->Error - pid->LastError	
		float  SumError;           //  Sums of Errors  
		
		float  output;
		
		float  Integralmax;      //����������ֵ
		float  outputmax;        //���������ֵ
} PID;


void PID_Init(PID *pid, float Kp , float Ki , float Kd , float Limit_value); 
float PID_Incremental_Calc(PID *pid, float Target_val, float Actual_val);  

#endif
