#include "struct.h"
#include "ITR.h"
#include "action.h"
#include "motor.h"

uint8_t LOOP_openmv()
{
	Open_MV_Move();			//�Ӿ�����
	return 1;
}
uint8_t LOOP_edge()
{
	State_Edge();		//��̨���ؼ��
	return 1;
}
uint8_t LOOP_goup()
{
	state_down();		//��̨���ؼ��
	return 1;
}


