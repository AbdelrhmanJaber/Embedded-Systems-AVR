#include"std_types.h"
#include"Bit_Math.h"

#include"MTWI_private.h"
#include"MTWI_interface.h"

void MTWI_MasterInit(u8 Copy_u8Frequency){
	/*Clear the prescaler */
	CLR_BIT(MTWI_u8_TWSR_REG , 1);
	CLR_BIT(MTWI_u8_TWSR_REG , 0);
	/*Set the frequency*/
	switch(Copy_u8Frequency){
		case FREQ_100K :{
			MTWI_u8_TWBR_REG = 32;
			break;
		}
		case FREQ_200K :{
			MTWI_u8_TWBR_REG = 12;
			break;
		}
		case FREQ_300K :{
			MTWI_u8_TWBR_REG = 6;
			break;
		}
		case FREQ_400K :{
			MTWI_u8_TWBR_REG = 2;
			break;
		}
	}
	/*Enable the Ack*/
	SET_BIT(MTWI_u8_TWCR_REG , 6);
	/*Enable the TWI*/
	SET_BIT(MTWI_u8_TWCR_REG , 2);
}

void MTWI_SlaveInit(u8 Copy_u8SlaveAddress){
	/*Set the Slave Address (7 bits)*/
	MTWI_u8_TWAR_REG = (Copy_u8SlaveAddress<<1);
	/*Enable the Ack*/
	SET_BIT(MTWI_u8_TWCR_REG , 6);
	/*Enable the TWI*/
	SET_BIT(MTWI_u8_TWCR_REG , 2);
}

TWI_ErrorState MTWI_SendStartCondition(void){
	u8 Local_u8Status;
	TWI_ErrorState Local_ErrorState = TWI_OK;
	/*send start condition*/
	SET_BIT(MTWI_u8_TWCR_REG , 5);
	/*CLR FLAG */
	SET_BIT(MTWI_u8_TWCR_REG , 7);
	Local_u8Status = status();
	if((Local_u8Status & GET_STATUS) != START_CONDITION_STATUS ){
		Local_ErrorState = TWI_StartCondition_ERROR;
	}
	return Local_ErrorState;
}

TWI_ErrorState MTWI_SendRepeatedStartCondition(void){
	u8 Local_u8Status;
	TWI_ErrorState Local_ErrorState = TWI_OK;
	/*send start condition*/
	SET_BIT(MTWI_u8_TWCR_REG , 5);
	/*CLR FLAG */
	SET_BIT(MTWI_u8_TWCR_REG , 7);
	Local_u8Status = status();
	if((Local_u8Status & GET_STATUS) != REPEATED_START_CONDITION_STATUS ){
		Local_ErrorState = TWI_RepeatedStartCondioton_ERROR;
	}
	return Local_ErrorState;
}

TWI_ErrorState MTWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress){
	u8 Local_u8Status;
	TWI_ErrorState Local_ErrorState = TWI_OK;
	/*Send the slave address*/
	MTWI_u8_TWDR_REG = (Copy_u8SlaveAddress << 1);
	/*Write Mode*/
	CLR_BIT(MTWI_u8_TWDR_REG , 0);
	/*CLR the Start Condition*/
	CLR_BIT(MTWI_u8_TWCR_REG , 5);
	/*CLR the flag*/
	SET_BIT(MTWI_u8_TWCR_REG , 7);
	Local_u8Status = status();
	if((Local_u8Status & GET_STATUS) != SEND_SLAVE_ADDRESS_WRITE_STATUS){
		Local_ErrorState = TWI_Send_SLAVE_W_ERROR;
	}
	return Local_ErrorState;
}

TWI_ErrorState MTWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress){
	u8 Local_u8Status;
	TWI_ErrorState Local_ErrorState = TWI_OK;
	/*Send the slave address*/
	MTWI_u8_TWDR_REG = (Copy_u8SlaveAddress << 1);
	/*Read Mode*/
	SET_BIT(MTWI_u8_TWDR_REG , 0);
	/*CLR the Start Condition*/
	CLR_BIT(MTWI_u8_TWCR_REG , 5);
	/*CLR the flag*/
	SET_BIT(MTWI_u8_TWCR_REG , 7);
	Local_u8Status = status();
	if((Local_u8Status & GET_STATUS) != SEND_SLAVE_ADDRESS_READ_STATUS){
		Local_ErrorState = TWI_Send_SLAVE_R_ERROR;
	}
	return Local_ErrorState;
}

TWI_ErrorState MTWI_SendDataByte(u8 Copy_u8Data){
	u8 Local_u8Status;
	TWI_ErrorState Local_ErrorState = TWI_OK;
	MTWI_u8_TWDR_REG = Copy_u8Data;
	/*CLR Flag*/
	SET_BIT(MTWI_u8_TWCR_REG , 7);
	Local_u8Status = status();
	if((Local_u8Status & GET_STATUS) != WRITE_BYTE_STATUS){
		Local_ErrorState = TWI_Send_DATA_ERROR;
	}
	return Local_ErrorState;
}


TWI_ErrorState MTWI_RecieveDataByte(u8* Copy_pu8RecievedData){
	u8 Local_u8Status;
	TWI_ErrorState Local_ErrorState = TWI_OK;
	if(Copy_pu8RecievedData != STD_TYPES_NULL){
		/*CLR the flag*/
		SET_BIT(MTWI_u8_TWCR_REG , 7);
		Local_u8Status = status();
		if((Local_u8Status & GET_STATUS) != RECEIVE_BYTE_STATUS){
			Local_ErrorState = TWI_Recieve_DATA_ERROR;
		}
		else{
			*Copy_pu8RecievedData = MTWI_u8_TWDR_REG;
		}
	}
	else{
		Local_ErrorState = TWI_NULL_POINTER;
	}
	return Local_ErrorState;
}


void MTWI_SendStopCondition(void){
	/*Send Stop Condition*/
	SET_BIT(MTWI_u8_TWCR_REG , 4);
	/*CLR Flag*/
	SET_BIT(MTWI_u8_TWCR_REG , 7);
}

static u8 status(void){
	/*Wait the flag*/
	while(!(GET_BIT(MTWI_u8_TWCR_REG , 7)));
	return MTWI_u8_TWSR_REG;
}
