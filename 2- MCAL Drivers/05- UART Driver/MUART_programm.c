#include"std_types.h"
#include"Bit_Math.h"

#include"MUART_private.h"
#include"MUART_config.h"
#include"MUART_interface.h"


const u16 BaudRateArray[TOTAL_SPEED_MODE][TOTAL_BAUD_RATE]={{207, 103, 51, 34, 25, 16, 12},
		{416, 207, 103, 68, 51, 34 , 25}};

static void (*MUART_DesiredFunctionTX)(void) = STD_TYPES_NULL;
static void (*MUART_DesiredFunctionRX)(void) = STD_TYPES_NULL;
static u8* globalStringTX = STD_TYPES_NULL;
static u8* globalStringRX = STD_TYPES_NULL;
static u8 globalByteTX;
static u8* globalByteRX = STD_TYPES_NULL;

#define NEXT_LINE         0x0d

void MUART_voidInit(void){
 /**************Frame ****************/
	u8 Local_u8UCSRC = 0x80;
	u16 Local_u16BaudRate;
	/* speed of data Normal speed or double speed*/
	MUART_u8_UCSRA_REG &= SPEED_MODE;
	/*Enable Transmitter , Receiver*/
	SET_BIT(MUART_u8_UCSRB_REG,4); //RX
	SET_BIT(MUART_u8_UCSRB_REG,3); //TX
	/* PARITY MOOD */
	Local_u8UCSRC |= PARITY_MODE;
	/*Stop Bit Selection 1bit or 2bits */
	Local_u8UCSRC |= STOP_BITS;
	/*******DATA BITS******/
    #if(HAS_NINTH_BIT == NINTH_BIT_EXISTS)
	SET_BIT(MUART_u8_UCSRB_REG , 2);
	Local_u8UCSRC = DATA_BITS_NUMBER;
    #elif(HAS_NINTH_BIT == NINTH_BIT_DOESNOT_EXIST)
	CLR_BIT(MUART_u8_UCSRB_REG , 2);
	Local_u8UCSRC = DATA_BITS_NUMBER;
    #endif
	MUART_u8_UCSRC_REG = Local_u8UCSRC;
	/**BaudRate**/
	Local_u16BaudRate = BaudRateArray[SPEED_IS_NORMAL][BAUDRATE_9600];
	MUART_u8_UBRRL_REG = (u8)(Local_u16BaudRate);
	MUART_u8_UBRRH_REG = (u8)(Local_u16BaudRate>>8);
}

void MUART_voidSendByte(u8 data){
	/*Check if the buffer is empty to send data*/
	while(!(GET_BIT(MUART_u8_UCSRA_REG , 5)));
	MUART_u8_UDR_REG = data;
}

void MUART_voidSendByteAsynch(u8 data){
	globalByteTX = data;
	MUART_SetCallBackTransmitter(TX_Byte);
	/*Enable TX Interrupt*/
	SET_BIT(MUART_u8_UCSRB_REG , 5);
}

void TX_Byte(void){
	MUART_u8_UDR_REG = globalByteTX;
}
u8 MUART_u8RecieveByte(){
	while(!(GET_BIT(MUART_u8_UCSRA_REG,7)));
	return MUART_u8_UDR_REG;
}

void MUART_voidRecieveByteAsynch(u8* data){
	globalByteRX = data;
	MUART_SetCallBackReciever(RX_Byte);
	/*Enable RX Interrupt*/
	SET_BIT(MUART_u8_UCSRB_REG , 7);
}

void RX_Byte(void){
	if(globalByteRX != STD_TYPES_NULL)
	  *(globalByteRX) = MUART_u8_UDR_REG;
}

void MUART_voidSendStringSynch(u8* word){
	u8 index = 0;
	while(word[index] != '\0'){
		MUART_voidSendByte(word[index]);
		index++;
	}
}

void MUART_Pu8RecieveStringSynch(u8* word){
	u8 index=0;
	word[index] = MUART_u8RecieveByte();
	while(word[index] != NEXT_LINE){
		word[++index] = MUART_u8RecieveByte();
	}
	word[index] = '\0';
}


void MUART_SendStringAsynch(u8* Copy_String){
	if(Copy_String != STD_TYPES_NULL){
	globalStringTX  = Copy_String;
      MUART_SetCallBackTransmitter(TX_String);
	  /*Enable Interrupt*/
	   SET_BIT(MUART_u8_UCSRB_REG , 5);
	}
}

void TX_String(void){
	static u8 index = 0;
	if(globalStringTX != STD_TYPES_NULL){
		if(globalStringTX[index] != '\0'){
		   HLCD_u8SendChar(globalStringTX[index]);
	       MUART_u8_UDR_REG = globalStringTX[index];
	       index++;
		}
		else{
		 index = 0;
		 CLR_BIT(MUART_u8_UCSRB_REG , 5);
	   }
	}
}

void MUART_SetCallBackTransmitter(void(*Copy_Pf)(void)){
	if(Copy_Pf != STD_TYPES_NULL)
		MUART_DesiredFunctionTX = Copy_Pf;
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void){
	if(MUART_DesiredFunctionTX != STD_TYPES_NULL){
	  MUART_DesiredFunctionTX();
	}
}

void MUART_RecieveStringAsynch(u8* word){
	globalStringRX = word;
	MUART_SetCallBackReciever(RX_String);
	/* Enable Interrupt */
	SET_BIT(MUART_u8_UCSRB_REG , 7);
}

void MUART_SetCallBackReciever(void(*Copy_Pf)(void)){
	if(Copy_Pf != STD_TYPES_NULL)
     	MUART_DesiredFunctionRX = Copy_Pf;
}

void RX_String(void){
	static u8 index = 0;
	u8 temp = MUART_u8_UDR_REG;
	if(temp != NEXT_LINE){
		globalStringRX[index] = temp;
		index++;
	}
	else{
		index = 0;
		CLR_BIT(MUART_u8_UCSRB_REG , 7);
		globalStringRX[index] = '\0';
	}
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void){
	if(MUART_DesiredFunctionRX != STD_TYPES_NULL)
       	MUART_DesiredFunctionRX();
}

