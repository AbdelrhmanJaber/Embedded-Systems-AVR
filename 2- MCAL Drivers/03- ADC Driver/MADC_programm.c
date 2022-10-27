#include "std_types.h"
#include"BIT_MATH.h"

#include"MADC_interface.h"
#include"MADC_private.h"
#include"MADC_config.h"


static u8 MADC_u8BussyFlag = MADC_u8_NOT_BUSY;
static void(*MADC_PfNotificationFunc)(u16)=STD_TYPES_NULL;

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

u8 MADC_u8GetDigitalValueSynch(u8 Copy_u8ChannelNum,u16 * Copy_Pu16DigitalValue){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	u32 Local_u32TimeOutCounter=0;
	if( (Copy_u8ChannelNum < 32)&& (Copy_Pu16DigitalValue != STD_TYPES_NULL)&&(MADC_u8BussyFlag==MADC_u8_NOT_BUSY) ){
		/* Clear Channel Number Bits */
		MADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel Number */
		MADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		/* Start Conversion */
		SET_BIT(MADC_u8_ADCSRA_REG,6);
		/* Wait for the flag */
		while((!(GET_BIT(MADC_u8_ADCSRA_REG,4)))&&(Local_u32TimeOutCounter< MADC_u32_MAX_TIMEOUT)){
			Local_u32TimeOutCounter++;
		}
		/*Check flag*/
		if(GET_BIT(MADC_u8_ADCSRA_REG,4)){
		/* Clear the flag */
		SET_BIT(MADC_u8_ADCSRA_REG,4);
		/* Read Digital Value and return it in pointer*/
		*Copy_Pu16DigitalValue=MADC_u8ADC_REG;
		}
		else{
			Local_u8ErrorState=STD_TYPES_NOK;
		}
	}
	else{
		Local_u8ErrorState=STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

u8 MADC_u8GetDigitalValueAsynch(u8 Copy_u8ChannelNum,void(*Copy_PfNotification)(u16)){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if((Copy_u8ChannelNum < 32)&& (Copy_PfNotification != STD_TYPES_NULL)&&(MADC_u8BussyFlag==MADC_u8_NOT_BUSY)){
		/*Update flag to busy state*/
		MADC_u8BussyFlag=MADC_u8_BUSY;
		/*Update Global pointer to function*/
		MADC_PfNotificationFunc=Copy_PfNotification;
		/* Clear Channel Number Bits */
		MADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel Number */
		MADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		/*Enable Interrupt*/
		SET_BIT(MADC_u8_ADCSRA_REG,3);
		/*Start Conversion*/
		SET_BIT(MADC_u8_ADCSRA_REG,6);
    }
	else
		Local_u8ErrorState=STD_TYPES_NOK;

	return Local_u8ErrorState;

}

void __vector_16(void) __attribute__((signal));
void __vector_16(void){
	/* Set Busy Flag to Not Busy State */
	MADC_u8BussyFlag = MADC_u8_NOT_BUSY;
	/* Check global pointer to function */
	if(MADC_PfNotificationFunc!= STD_TYPES_NULL){
		MADC_PfNotificationFunc(MADC_u8ADC_REG);
	}
	/*Disable Interrupt*/
	CLR_BIT(MADC_u8_ADCSRA_REG,3);
}
