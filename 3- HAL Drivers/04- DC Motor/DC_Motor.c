#include"std_types.h"

#include"MTMR_interface.h"

#include"DC_Motor.h"

void HDC_StartMotor(u8 Local_u8Dute_Cycle){
	if(Local_u8Dute_Cycle == 0){
		MTMR_u8Timer0Init();
		MTMR_u8Timer0GeneratePWM(0);
		return;
	}
	u16 Local_u16_OCR_Value = 0;
	u8 temp;
	temp = (100/Local_u8Dute_Cycle);
	Local_u16_OCR_Value = 255/temp;
	MTMR_u8Timer0Init();
	MTMR_u8Timer0GeneratePWM(Local_u16_OCR_Value);
}

void HDC_StopMotor(void){
	MTMR_u8Timer0GeneratePWM(0);
}





