#include"std_types.h"
#include"MDIO_interface.h"
#include"HLCD_interface.h"
#include"HLCD_private.h"
#include"HLCD_config.h"
#define F_CPU 8000000UL
#include<avr/delay.h>

void HLCD_voidINIT(void)
{
	_delay_us(31);
	/*Function set command*/
	HLCD_u8SendCmnd(FunctionSet);
	_delay_us(40);
	/*Display on/off Control*/
	HLCD_u8SendCmnd(DisplayControl);
	_delay_us(40);
	/*Display Clear*/
	HLCD_u8SendCmnd(DisplayClear);
	_delay_ms(2);
	/*Entry Mode Set*/
	HLCD_u8SendCmnd(EntryMode);
}

u8 HLCD_u8SendCmnd(u8 Copy_u8Cmnd)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/*1- set Rs pin=> Low (command)*/
	MDIO_u8SetPinValue(HLCD_u8_RS_PORT,HLCD_u8_RS_PIN,MDIO_u8_LOW);
	/*2- set Rw pin=>low (write)*/
	MDIO_u8SetPinValue(HLCD_u8_RW_PORT,HLCD_u8_RW_PIN,MDIO_u8_LOW);
	/*3- send command to LCD on data Pins*/
	MDIO_u8SetPortValue(HCLD_u8_DATA_PORT,Copy_u8Cmnd);
	/*4- set Enable pulse*/
	MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_HIGH);
	_delay_us(1);
	MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_LOW);
	return Local_u8ErrorState;
}

u8 HLCD_u8SendChar (u8 Copy_u8Char)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/*1- set Rs pin=> Low (command)*/
	MDIO_u8SetPinValue(HLCD_u8_RS_PORT,HLCD_u8_RS_PIN,MDIO_u8_HIGH);
	/*2- set Rw pin=>low (write)*/
	MDIO_u8SetPinValue(HLCD_u8_RW_PORT,HLCD_u8_RW_PIN,MDIO_u8_LOW);
	/*3- send command to LCD on data Pins*/
	MDIO_u8SetPortValue(HCLD_u8_DATA_PORT,Copy_u8Char);
	/*4- set Enable pulse*/
	MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_HIGH);
	_delay_us(1);
	MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_LOW);
	return Local_u8ErrorState;
}


u8 HLCD_u8SetCursor(u8 Copy_u8LineNum,u8 Copy_u8CharNum)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	switch(Copy_u8LineNum)
	{
		case HLCD_u8_LINE_1:HLCD_u8SendCmnd(0x80+Copy_u8CharNum); break;
		case HLCD_u8_LINE_2:HLCD_u8SendCmnd(0xC0+Copy_u8CharNum); break;
		default:Local_u8ErrorState=STD_TYPES_NOK;break;
	}
	return Local_u8ErrorState;
}

u8 HLCD_u8SendString(u8 Copy_u8String[],u8 Copy_u8Cursor)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	for(u8 i=0;Copy_u8String[i] !='\0'; i++)
	{
		if(i==16-Copy_u8Cursor)
			HLCD_u8SetCursor(2,0);
		HLCD_u8SendChar(Copy_u8String[i]);
	}

	return Local_u8ErrorState;
}

u8 HLCD_u8SendNumber(s32 Copy_u8Number,u8 Copy_floatNumber,u8 Copy_negativeNumber)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	u8 temp1;
	s32 temp2=Copy_u8Number;
	u16 temp3=1;
	u8 counter=0;
	if(Copy_u8Number==0)
	{
		HLCD_u8SendChar('0');
		if(Copy_floatNumber!=0)
		{
			HLCD_u8SendChar('.');
			HLCD_u8SendNumber(Copy_floatNumber,0,0);
		}
	}
	else{
		if(Copy_negativeNumber)
			HLCD_u8SendChar('-');
	while(temp2!=0)
	{
		temp2=temp2/10;
		counter++;
	}
	for(u8 i=0;i<(counter-1);i++)
			temp3=temp3*10;
	for(u8 i=0;i<counter; i++)
	{
		temp1=(Copy_u8Number)/temp3;
		Copy_u8Number=(Copy_u8Number)%temp3;
		temp3=temp3/10;
		HLCD_u8SendChar(48+temp1);
	}
	if(Copy_floatNumber!=0)
	{
		HLCD_u8SendChar('.');
		HLCD_u8SendNumber(Copy_floatNumber,0,0);
	}
	}
	return Local_u8ErrorState;
}

u8 HLCD_u8GenerateSpecialCharacter(u8* Copy_Pu8_pattern,u8 Copy_u8_CGRAM_Index)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	HLCD_u8SendCmnd((0x40+Copy_u8_CGRAM_Index));
	for(u8 i=0;i<8;i++)
		HLCD_u8SendChar(Copy_Pu8_pattern[i]);

	return Local_u8ErrorState;
}

u8 HLCD_u8DisplaySpecialCharacter(u8 Copy_u8_PatternId,u8 Copy_u8LineNum,u8 Copy_u8CharNum)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	HLCD_u8SetCursor(Copy_u8LineNum,Copy_u8CharNum);
	HLCD_u8SendChar(Copy_u8_PatternId);
	return Local_u8ErrorState;
}

u8 HLCD_u8ClearDisplay(void)
{
	HLCD_u8SendCmnd(0x01);
	return 1;
}
