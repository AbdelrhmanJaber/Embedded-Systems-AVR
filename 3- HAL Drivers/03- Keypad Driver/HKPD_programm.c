#include"std_types.h"

#include"MDIO_interface.h"

#include"HKPD_interface.h"
#include"HKPD_config.h"
#include"HKPD_private.h"

#define F_CPU  8000000UL
#include<avr/delay.h>

u8 HKPD_Au8RowPins[4]={HKPD_u8_R0_PIN,HKPD_u8_R1_PIN,HKPD_u8_R2_PIN,HKPD_u8_R3_PIN};
u8 HKPD_Au8RowPort[4]={HKPD_u8_R0_PORT,HKPD_u8_R1_PORT,HKPD_u8_R2_PORT,HKPD_u8_R3_PORT};

u8 HKPD_Au8ColPins[4]={HKPD_u8_C0_PIN,HKPD_u8_C1_PIN,HKPD_u8_C2_PIN,HKPD_u8_C3_PIN};
u8 HKPD_Au8ColPort[4]={HKPD_u8_C0_PORT,HKPD_u8_C1_PORT,HKPD_u8_C2_PORT,HKPD_u8_C3_PORT};

u8 HKPD_Au8Keys[4][4]=HKPD_KEYS;

u8 HKPD_u8GetKey(u8* Copy_Pu8_RetKey)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	u8 Local_u8RowCounter;
	u8 Local_u8ColCounter;
	u8 Local_u8RetPinValue,Local_u8Flag=0;
	if(Copy_Pu8_RetKey!=STD_TYPES_NULL)
	{
		*Copy_Pu8_RetKey=HKPD_u8_NO_KEY_PRESSED;
		/*Activate Each Row*/
		for(Local_u8RowCounter=0;Local_u8RowCounter<4;Local_u8RowCounter++)
		{
			/*Activate Row*/
			MDIO_u8SetPinValue(HKPD_Au8RowPort[Local_u8RowCounter],HKPD_Au8RowPins[Local_u8RowCounter],
					MDIO_u8_LOW);
			/*Check columns*/
			for(Local_u8ColCounter=0;Local_u8ColCounter<4;Local_u8ColCounter++)
			{
				MDIO_u8GetPinValue(HKPD_Au8ColPort[Local_u8ColCounter],HKPD_Au8ColPins[Local_u8ColCounter],
								&Local_u8RetPinValue);
				if(Local_u8RetPinValue==MDIO_u8_LOW){
					/*wait for debouncing*/
					_delay_ms(20);
					while(Local_u8RetPinValue==MDIO_u8_LOW)
					{
					  MDIO_u8GetPinValue(HKPD_Au8ColPort[Local_u8ColCounter],HKPD_Au8ColPins[Local_u8ColCounter],
										&Local_u8RetPinValue);
					}
					_delay_ms(20);
					/*return value*/
					*Copy_Pu8_RetKey=HKPD_Au8Keys[Local_u8RowCounter][Local_u8ColCounter];
					Local_u8Flag=1;
					break;
				}
			}
			/*Dectivate row*/
			MDIO_u8SetPinValue(HKPD_Au8RowPort[Local_u8RowCounter],HKPD_Au8RowPins[Local_u8RowCounter],
					MDIO_u8_HIGH);
			if(Local_u8Flag)
				break;
		}
	}
	else
		Local_u8ErrorState=STD_TYPES_NOK;

	return Local_u8ErrorState;
}
