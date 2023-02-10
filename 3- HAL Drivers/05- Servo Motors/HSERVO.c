#include"std_types.h"

#include"MTMR_interface.h"

#include"HSERVO.h"

void HSV_SetAngle(u8 Local_u8Angel){
	MTMR_u8Timer1Init();
	if(Local_u8Angel == 0){
		MTMR_voidTMR1SetCompareMatchValueChannelA(MTMR1_u16StartValue);
	}
	else{
	MTMR_voidTMR1SetCompareMatchValueChannelA((50*Local_u8Angel/9)+MTMR1_u16StartValue);
	}
}
