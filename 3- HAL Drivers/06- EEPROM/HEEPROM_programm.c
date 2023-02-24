#include"std_types.h"
#include"Bit_Math.h"

#include"MTWI_interface.h"

#include"HEEPROM_private.h"
#include"HEEPROM_config.h"
#include"HEEPROM_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

void HEEPROM_voidInit(u8 Copy_u8frequency){
	MTWI_MasterInit(Copy_u8frequency);
}

u8 HEEPROM_u8WriteByte(u8 Copy_u8Data , u16 Copy_u16Address){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorState Local_EnumCheckError = TWI_OK;
	/*Send Start Condition*/
	Local_EnumCheckError = MTWI_SendStartCondition();
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Send the slave address*/
	Local_EnumCheckError = MTWI_SendSlaveAddressWithWrite((EEPROM_Fixed_Address) | (EEPROM_CHIP_SELECT<<2) |((u8)(Copy_u16Address>>8)));
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Send the internal address as a data*/
	Local_EnumCheckError = MTWI_SendDataByte((u8)Copy_u16Address);
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Send the data*/
	Local_EnumCheckError = MTWI_SendDataByte(Copy_u8Data);
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Stop Condition*/
	MTWI_SendStopCondition();
	/*Some delay time*/
	_delay_ms(10);

	return Local_u8ErrorState;
}

u8 HEEPROM_u8ReadByte(u8* Copy_pu8RecievedData , u16 Copy_u16Address){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorState Local_EnumCheckError = TWI_OK;
	/*Send Start Condition*/
	if(Copy_pu8RecievedData != STD_TYPES_NULL){
	Local_EnumCheckError = MTWI_SendStartCondition();
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Send the slave address with write*/
	Local_EnumCheckError = MTWI_SendSlaveAddressWithWrite((EEPROM_Fixed_Address) | (EEPROM_CHIP_SELECT<<2) |((u8)(Copy_u16Address>>8)));
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Send the internal Address*/
	Local_EnumCheckError = MTWI_SendDataByte((u8)Copy_u16Address);
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Send Repeated Start*/
	Local_EnumCheckError = MTWI_SendRepeatedStartCondition();
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Send Slave Address with read*/
	Local_EnumCheckError = MTWI_SendSlaveAddressWithRead((EEPROM_Fixed_Address) | (EEPROM_CHIP_SELECT<<2) |((u8)(Copy_u16Address>>8)));
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Receive Byte*/
	/*Send the address of the received pointer to receive the data*/
	Local_EnumCheckError = MTWI_RecieveDataByte(Copy_pu8RecievedData);
	if(Local_EnumCheckError != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/*Stop Condition*/
	MTWI_SendStopCondition();
	/*Some Delay time*/
	_delay_ms(10);
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
