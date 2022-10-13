#include "std_types.h"
#include"BIT_MATH.h"

#include"MADC_interface.h"
#include"MADC_private.h"
#include"MADC_config.h"

void MADC_voidINIT(void){
	/* Select VREF source */
	MADC_u8_ADMUX_REG |= MADC_u8_ADC_VREF;
	/* Select Adj */
	MADC_u8_ADMUX_REG = MADC_u8_Adj_Direction;
	/* Conversion Mood */
	switch(MADC_u8_Conversion_Mood){
		case MADC_u8_Single_Conversion_Mood:
			MADC_u8_ADCSRA_REG &= 0b11011111;
			break;

		case MADC_u8_Auto_Triggerd_Mode:
			MADC_u8_SFIOR_REG = MADC_u8_Auto_Triggerd_Source;
			break;
	}
	/* Pre Scaler Option 64=> 125KH */
	SET_BIT(MADC_u8_ADCSRA_REG,2);
	SET_BIT(MADC_u8_ADCSRA_REG,1);
	CLR_BIT(MADC_u8_ADCSRA_REG,0);
	/* Enable ADC */
	SET_BIT(MADC_u8_ADCSRA_REG,7);
}

u8 MADC_u8GetDigitalValue(u8 Copy_u8ChannelNum,u16 * Copy_Pu16DigitalValue){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if( (Copy_u8ChannelNum < 32)&& (Copy_Pu16DigitalValue != STD_TYPES_NULL) ){
		/* Clear Channel Number Bits */
		MADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel Number */
		MADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		/* Start Conversion */
		SET_BIT(MADC_u8_ADCSRA_REG,6);
		/* Wait for the flag */
		while(!(GET_BIT(MADC_u8_ADCSRA_REG,4)));
		/* Clear the flag */
		SET_BIT(MADC_u8_ADCSRA_REG,4);
		/* Read Digital Value and return it in pointer*/
		*Copy_Pu16DigitalValue=MADC_u8ADC_REG;
	}
	else{
		Local_u8ErrorState=STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
