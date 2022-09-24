#include"std_types.h"
#include"BIT_MATH.h"
#include"MDIO_private.h"
#include"MDIO_interface.h"
#include"MDIO_config.h"
u8 MDIO_u8INIT(void)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/*PORTA*/
	MDIO_u8_DDRA_REG = PRIVATE_u8_CONC(MDIO_u8_PA7_DIRECTION,
			MDIO_u8_PA6_DIRECTION,
			MDIO_u8_PA5_DIRECTION,
			MDIO_u8_PA4_DIRECTION,
			MDIO_u8_PA3_DIRECTION,
			MDIO_u8_PA2_DIRECTION,
			MDIO_u8_PA1_DIRECTION,
			MDIO_u8_PA0_DIRECTION);

	MDIO_u8_DDRB_REG = PRIVATE_u8_CONC(MDIO_u8_PB7_DIRECTION,
			MDIO_u8_PB6_DIRECTION,
			MDIO_u8_PB5_DIRECTION,
			MDIO_u8_PB4_DIRECTION,
			MDIO_u8_PB3_DIRECTION,
			MDIO_u8_PB2_DIRECTION,
			MDIO_u8_PB1_DIRECTION,
			MDIO_u8_PB0_DIRECTION);

	MDIO_u8_DDRC_REG = PRIVATE_u8_CONC(MDIO_u8_PC7_DIRECTION,
			MDIO_u8_PC6_DIRECTION,
			MDIO_u8_PC5_DIRECTION,
			MDIO_u8_PC4_DIRECTION,
			MDIO_u8_PC3_DIRECTION,
			MDIO_u8_PC2_DIRECTION,
			MDIO_u8_PC1_DIRECTION,
			MDIO_u8_PC0_DIRECTION);

	MDIO_u8_DDRD_REG = PRIVATE_u8_CONC(MDIO_u8_PD7_DIRECTION,
			MDIO_u8_PD6_DIRECTION,
			MDIO_u8_PD5_DIRECTION,
			MDIO_u8_PD4_DIRECTION,
			MDIO_u8_PD3_DIRECTION,
			MDIO_u8_PD2_DIRECTION,
			MDIO_u8_PD1_DIRECTION,
			MDIO_u8_PD0_DIRECTION);

	MDIO_u8_PORTA_REG= PRIVATE_u8_CONC(MDIO_u8_PA7_value,
           MDIO_u8_PA6_value,
           MDIO_u8_PA5_value,
           MDIO_u8_PA4_value,
           MDIO_u8_PA3_value,
           MDIO_u8_PA2_value,
           MDIO_u8_PA1_value,
           MDIO_u8_PA0_value);

	MDIO_u8_PORTB_REG= PRIVATE_u8_CONC(MDIO_u8_PB7_value,
	       MDIO_u8_PB6_value,
	       MDIO_u8_PB5_value,
	       MDIO_u8_PB4_value,
	       MDIO_u8_PB3_value,
	       MDIO_u8_PB2_value,
	       MDIO_u8_PB1_value,
	       MDIO_u8_PB0_value);

	MDIO_u8_PORTC_REG= PRIVATE_u8_CONC(MDIO_u8_PC7_value,
	       MDIO_u8_PC6_value,
	       MDIO_u8_PC5_value,
	       MDIO_u8_PC4_value,
	       MDIO_u8_PC3_value,
	       MDIO_u8_PC2_value,
	       MDIO_u8_PC1_value,
	       MDIO_u8_PC0_value);

	MDIO_u8_PORTD_REG= PRIVATE_u8_CONC(MDIO_u8_PD7_value,
	       MDIO_u8_PD6_value,
	       MDIO_u8_PD5_value,
	       MDIO_u8_PD4_value,
	       MDIO_u8_PD3_value,
	       MDIO_u8_PD2_value,
	       MDIO_u8_PD1_value,
	       MDIO_u8_PD0_value);

	return Local_u8ErrorState;
}

u8 MDIO_u8SetPinDirection(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u8 Copy_u8_Pin_Direction)
{
	u8 Local_u8ErrorState= STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD)&&(Copy_u8_Pin_Id<=MDIO_u8_PIN_7))
	{
		Local_u8ErrorState= STD_TYPES_OK;
		switch(Copy_u8_Pin_Direction)
		{
			case MDIO_u8_OUTPUT:
				switch(Copy_u8_Port_Id)
				{
					case MDIO_u8_PORTA:
						SET_BIT(MDIO_u8_DDRA_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTB:
						SET_BIT(MDIO_u8_DDRB_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTC:
						SET_BIT(MDIO_u8_DDRC_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTD:
						SET_BIT(MDIO_u8_DDRD_REG,Copy_u8_Pin_Id);
						break;
				}
				break;

		  case MDIO_u8_INPUT_PULLED_UP:
		  	switch(Copy_u8_Port_Id)
		  	{
		  		case MDIO_u8_PORTA:
		  			SET_BIT(MDIO_u8_PORTA_REG,Copy_u8_Pin_Id);
		  			break;

		  		case MDIO_u8_PORTB:
		  			SET_BIT(MDIO_u8_PORTB_REG,Copy_u8_Pin_Id);
		  			break;

		  		case MDIO_u8_PORTC:
		  			SET_BIT(MDIO_u8_PORTC_REG,Copy_u8_Pin_Id);
		  			break;

		  		case MDIO_u8_PORTD:
		  			SET_BIT(MDIO_u8_PORTD_REG,Copy_u8_Pin_Id);
		  			break;
		  	}
		  	/* no break */

		 case MDIO_u8_INPUT_FLOATING:
		 	switch(Copy_u8_Port_Id)
		 	{
		 		case MDIO_u8_PORTA:
		 			CLR_BIT(MDIO_u8_DDRA_REG,Copy_u8_Pin_Id);
		 			break;

		 		case MDIO_u8_PORTB:
		 			CLR_BIT(MDIO_u8_DDRB_REG,Copy_u8_Pin_Id);
		 			break;

		 		case MDIO_u8_PORTC:
		 			CLR_BIT(MDIO_u8_DDRC_REG,Copy_u8_Pin_Id);
		 			break;

		 		case MDIO_u8_PORTD:
		 			CLR_BIT(MDIO_u8_DDRD_REG,Copy_u8_Pin_Id);
		 			break;
		 	}
		 break;

		 	default:
		 	Local_u8ErrorState=STD_TYPES_NOK;
		 	break;
		}
	}

	return Local_u8ErrorState;
}

u8 MDIO_u8SetPinValue(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u8 Copy_u8_Pin_Value)
{
	u8 Local_u8ErrorState= STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD)&&(Copy_u8_Pin_Id<=MDIO_u8_PIN_7))
	{
		Local_u8ErrorState= STD_TYPES_OK;
		switch(Copy_u8_Pin_Value)
		{
			case MDIO_u8_HIGH:
				switch(Copy_u8_Port_Id)
				{
					case MDIO_u8_PORTA:
						SET_BIT(MDIO_u8_PORTA_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTB:
						SET_BIT(MDIO_u8_PORTB_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTC:
						SET_BIT(MDIO_u8_PORTC_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTD:
						SET_BIT(MDIO_u8_PORTD_REG,Copy_u8_Pin_Id);
						break;
				}
			break;

			case MDIO_u8_LOW:
				switch(Copy_u8_Port_Id)
				{
					case MDIO_u8_PORTA:
						CLR_BIT(MDIO_u8_PORTA_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTB:
						CLR_BIT(MDIO_u8_PORTB_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTC:
						CLR_BIT(MDIO_u8_PORTC_REG,Copy_u8_Pin_Id);
						break;

					case MDIO_u8_PORTD:
						CLR_BIT(MDIO_u8_PORTD_REG,Copy_u8_Pin_Id);
						break;
				}
			break;

			default:
			Local_u8ErrorState=STD_TYPES_NOK;
			break;
		}
	}
	return Local_u8ErrorState ;
}

u8 MDIO_u8GetPinValue(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u8* Copy_Pu8_Pin_Value)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD)&&(Copy_u8_Pin_Id<=MDIO_u8_PIN_7)
			&&(Copy_Pu8_Pin_Value!=STD_TYPES_NULL))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		switch(Copy_u8_Port_Id)
		{
		    case MDIO_u8_PORTA:
			*Copy_Pu8_Pin_Value=GET_BIT(MDIO_u8_PINA_REG,Copy_u8_Pin_Id);
			break;

		    case MDIO_u8_PORTB:
		    *Copy_Pu8_Pin_Value=GET_BIT(MDIO_u8_PINB_REG,Copy_u8_Pin_Id);
			break;

		    case MDIO_u8_PORTC:
		    *Copy_Pu8_Pin_Value=GET_BIT(MDIO_u8_PINC_REG,Copy_u8_Pin_Id);
			break;

		    case MDIO_u8_PORTD:
		    *Copy_Pu8_Pin_Value=GET_BIT(MDIO_u8_PIND_REG,Copy_u8_Pin_Id);
			break;

		    default:
		    Local_u8ErrorState=STD_TYPES_NOK;
		    break;
		}
	}

	return Local_u8ErrorState;
}


u8 MDIO_u8SetPortDirection(u8 Copy_u8_Port_Id,u8 Copy_u8_Port_Direction)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if(Copy_u8_Port_Id<=MDIO_u8_PORTD)
	{
		Local_u8ErrorState=STD_TYPES_OK;
		switch(Copy_u8_Port_Direction)
		{
			case MDIO_u8_OUTPUT:
				switch(Copy_u8_Port_Id)
				{
					case MDIO_u8_PORTA:
						MDIO_u8_DDRA_REG=0xff;
						break;

					case MDIO_u8_PORTB:
						MDIO_u8_DDRB_REG=0xff;
						break;

					case MDIO_u8_PORTC:
						MDIO_u8_DDRC_REG=0xff;
						break;

					case MDIO_u8_PORTD:
						MDIO_u8_DDRD_REG=0xff;
						break;
				}
				break;

		   case MDIO_u8_INPUT_PULLED_UP:
			   switch(Copy_u8_Port_Id)
			   {
			   	case MDIO_u8_PORTA:
			   		MDIO_u8_PORTA_REG=0xff;
			   		break;

			   	case MDIO_u8_PORTB:
			   		MDIO_u8_PORTB_REG=0xff;
			   		break;

			   	case MDIO_u8_PORTC:
			   		MDIO_u8_PORTC_REG=0xff;
			   		break;

			   	case MDIO_u8_PORTD:
			   		MDIO_u8_PORTD_REG=0xff;
			   		break;
			   }
			   /* no break */

		 case MDIO_u8_INPUT_FLOATING:
			 switch(Copy_u8_Port_Id)
			 {
			 	case MDIO_u8_PORTA:
			 		MDIO_u8_DDRA_REG=0x00;
			 		break;

			 	case MDIO_u8_PORTB:
			 		MDIO_u8_DDRB_REG=0x00;
			 		break;

			 	case MDIO_u8_PORTC:
			 		MDIO_u8_DDRC_REG=0x00;
			 		break;

			 	case MDIO_u8_PORTD:
			 		MDIO_u8_DDRD_REG=0x00;
			 		break;
			 }
			 break;

		default:
			 Local_u8ErrorState=STD_TYPES_NOK;
			 break;
		}
	}
	return Local_u8ErrorState;
}

u8 MDIO_u8SetPortValue(u8 Copy_u8_Port_Id,u8 Copy_u8_Port_Value)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if(Copy_u8_Port_Id<=MDIO_u8_PORTD)
	{
		Local_u8ErrorState=STD_TYPES_OK;
		switch(Copy_u8_Port_Id)
		{
		case MDIO_u8_PORTA:
			MDIO_u8_PORTA_REG=Copy_u8_Port_Value;
			break;

		case MDIO_u8_PORTB:
			MDIO_u8_PORTB_REG=Copy_u8_Port_Value;
			break;

		case MDIO_u8_PORTC:
			MDIO_u8_PORTC_REG=Copy_u8_Port_Value;
			break;

		case MDIO_u8_PORTD:
			MDIO_u8_PORTD_REG=Copy_u8_Port_Value;
			break;
		}
	}


	return Local_u8ErrorState;
}

u8 MDIO_u8GetPortValue(u8 Copy_u8_Port_Id,u8* Copy_Pu8_Port_Value)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8_Port_Id<=MDIO_u8_PORTD)&&(Copy_Pu8_Port_Value!=STD_TYPES_NULL))
	{
		Local_u8ErrorState=STD_TYPES_OK;
		switch(Copy_u8_Port_Id)
		{
			case MDIO_u8_PORTA:
				*Copy_Pu8_Port_Value=MDIO_u8_PINA_REG;
				break;

			case MDIO_u8_PORTB:
				*Copy_Pu8_Port_Value=MDIO_u8_PINB_REG;
				break;

			case MDIO_u8_PORTC:
				*Copy_Pu8_Port_Value=MDIO_u8_PINC_REG;
				break;

			case MDIO_u8_PORTD:
				*Copy_Pu8_Port_Value=MDIO_u8_PIND_REG;
				break;
		}
	}

	return Local_u8ErrorState;
}
