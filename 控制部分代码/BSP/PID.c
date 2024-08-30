#include "PID.h" 
#include "tim.h"


float PID_Incremental_Calc(PID *pid, float Target_val, float Actual_val)  
{  
	pid->Error = Target_val- Actual_val;                        

	pid->output  +=  pid->Kp* ( pid->Error - pid->LastError )+   
									 pid->Ki* pid->Error +   
									 pid->Kd* ( pid->Error +  pid->PrevError - 2*pid->LastError);  
								 
	pid->PrevError = pid->LastError;  
	pid->LastError = pid->Error;

	if(pid->output > pid->outputmax )    pid->output = pid->outputmax;
	if(pid->output < - pid->outputmax )  pid->output = -pid->outputmax;
	
	return pid->output ;   //Êä³öÎªpwmÖµ
}
void PID_Init(PID *pid, float Kp , float Ki , float Kd , float Limit_value)  
{  
	pid->Kp= Kp;
	pid->Ki= Ki;
	pid->Kd= Kd;
	
	pid->PrevError =pid->LastError = pid->Error =pid->SumError= pid->output =  0; 
	pid->Integralmax = pid->outputmax  = Limit_value;
}  
