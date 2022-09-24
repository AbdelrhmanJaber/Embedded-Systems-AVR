#include"std_types.h"
#include"BIT_MATH.H"
#include"MDIO_private.h"
#include"MDIO_interface.h"
#include"HLED_interface.h"
#define F_CPU 8000000UL
#include<avr/delay.h>

u8 HLED_u8_Single_LED_ON(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD)&&(Copy_u8_Pin_Id<=MDIO_u8_PIN_7))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		MDIO_u8SetPinDirection(Copy_u8_Port_Id,Copy_u8_Pin_Id,MDIO_u8_OUTPUT);
		MDIO_u8SetPinValue(Copy_u8_Port_Id,Copy_u8_Pin_Id,MDIO_u8_HIGH);
	}
	return Local_u8ErrorState;
}
u8 HLED_u8_Single_LED_OF(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD)&&(Copy_u8_Pin_Id<=MDIO_u8_PIN_7))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		MDIO_u8SetPinDirection(Copy_u8_Port_Id,Copy_u8_Pin_Id,MDIO_u8_OUTPUT);
		MDIO_u8SetPinValue(Copy_u8_Port_Id,Copy_u8_Pin_Id,MDIO_u8_LOW);
	}
	return Local_u8ErrorState;
}

u8 HLED_u8_Single_LED_TOGGLE_ms(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u32 Copy_u32_Delay_Time)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD)&&(Copy_u8_Pin_Id<=MDIO_u8_PIN_7))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		MDIO_u8SetPinDirection(Copy_u8_Port_Id,Copy_u8_Pin_Id,MDIO_u8_OUTPUT);
        switch(Copy_u8_Port_Id)
        {
        	case MDIO_u8_PORTA:
        		TOGGLE_BIT(MDIO_u8_PORTA_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		TOGGLE_BIT(MDIO_u8_PORTA_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		break;

        	case MDIO_u8_PORTB:
        		TOGGLE_BIT(MDIO_u8_PORTB_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		TOGGLE_BIT(MDIO_u8_PORTB_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		break;

        	case MDIO_u8_PORTC:
        		TOGGLE_BIT(MDIO_u8_PORTC_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		TOGGLE_BIT(MDIO_u8_PORTC_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		break;

        	case MDIO_u8_PORTD:
        		TOGGLE_BIT(MDIO_u8_PORTD_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		TOGGLE_BIT(MDIO_u8_PORTD_REG,Copy_u8_Pin_Id);
        		_delay_ms(Copy_u32_Delay_Time);
        		break;
        }
	}
	return Local_u8ErrorState;
}

u8 HLED_u8_ALL_LED_ON(u8 Copy_u8_Port_Id)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		MDIO_u8SetPortDirection(Copy_u8_Port_Id,MDIO_u8_OUTPUT);
		MDIO_u8SetPortValue(Copy_u8_Port_Id,MDIO_u8_HIGH);
	}
	return Local_u8ErrorState;
}

u8 HLED_u8_ALL_LED_OF(u8 Copy_u8_Port_Id)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		MDIO_u8SetPortDirection(Copy_u8_Port_Id,MDIO_u8_OUTPUT);
		MDIO_u8SetPortValue(Copy_u8_Port_Id,MDIO_u8_LOW);
	}
	return Local_u8ErrorState;
}

u8 HLED_u8_ALL_LED_TOGGLE_ms(u8 Copy_u8_Port_Id,u32 Copy_u32_Delay_Time)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		MDIO_u8SetPortDirection(Copy_u8_Port_Id,MDIO_u8_OUTPUT);
		 switch(Copy_u8_Port_Id)
		 {
		 	case MDIO_u8_PORTA:
		 		TOGGLE_PORT(MDIO_u8_PORTA_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		TOGGLE_PORT(MDIO_u8_PORTA_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		break;

		 	case MDIO_u8_PORTB:
		 		TOGGLE_PORT(MDIO_u8_PORTB_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		TOGGLE_PORT(MDIO_u8_PORTB_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		break;

		 	case MDIO_u8_PORTC:
		 		TOGGLE_PORT(MDIO_u8_PORTC_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		TOGGLE_PORT(MDIO_u8_PORTC_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		break;

		 	case MDIO_u8_PORTD:
		 		TOGGLE_PORT(MDIO_u8_PORTD_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		TOGGLE_PORT(MDIO_u8_PORTD_REG);
		 		_delay_ms(Copy_u32_Delay_Time);
		 		break;
		 }
	}
	return Local_u8ErrorState;
}
