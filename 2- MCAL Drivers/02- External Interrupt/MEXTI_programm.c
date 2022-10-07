#include"std_types.h"
#include"BIT_MATH.h"

#include"MDIO_interface.h"
#include"MEXTI_interface.h"
#include"MEXTI_private.h"
#include"MEXTI_config.h"

/*Global Pointers To Functions*/
static void(*MEXTI_APF[3])(void)={STD_TYPES_NULL,STD_TYPES_NULL,STD_TYPES_NULL};

u8 MEXTI_u8EXTIEnable(u8 Copy_u8EXTINum,u8 Copy_u8EXTISource)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_u8EXTINum<=EXTI_NUM_2)&&(Copy_u8EXTISource<=MAX_Copy_u8EXTISource)){
		Local_u8ErrorState=STD_TYPES_OK;
		switch(Copy_u8EXTINum){
			case EXTI_NUM_0:
				switch(Copy_u8EXTISource){
					case EXTI_FALLING_EDGE:
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						break;

					case EXTI_RAISING_EDGE:
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						break;

					case EXTI_LEVEL_EDGE:
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						break;

					case EXTI_ANY_CHANGE:
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						break;
				}
				SET_BIT(MEXTI_u8_GICR_REG,MDIO_u8_PIN_6);
			break;

			case EXTI_NUM_1 :
				switch(Copy_u8EXTISource){
					case EXTI_FALLING_EDGE:
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						break;

					case EXTI_RAISING_EDGE:
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						break;

					case EXTI_LEVEL_EDGE:
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						break;

					case EXTI_ANY_CHANGE:
						SET_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_0);
						CLR_BIT(MEXTI_u8_MCUCR_REG,MDIO_u8_PIN_1);
						break;
				}
				SET_BIT(MEXTI_u8_GICR_REG,MDIO_u8_PIN_7);
				break;

		 case EXTI_NUM_2 :
			 switch(Copy_u8EXTISource){
			 	 case EXTI_FALLING_EDGE:
			 		CLR_BIT(MEXTI_u8_MCUCSR_REG,MDIO_u8_PIN_6);
			 		 break;

			 	 case EXTI_RAISING_EDGE:
			 		SET_BIT(MEXTI_u8_MCUCSR_REG,MDIO_u8_PIN_6);
			 		 break;

			 	 default:
			 		Local_u8ErrorState= STD_TYPES_NOK;
			 		break;
			 }
			 SET_BIT(MEXTI_u8_GICR_REG,MDIO_u8_PIN_5);
			 break;
		}
	}
	return Local_u8ErrorState;
}

u8 MEXTI_u8EXTIDisable(u8 Copy_u8EXTINum)
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if(Copy_u8EXTINum<=EXTI_NUM_2){
		Local_u8ErrorState=STD_TYPES_OK;
		switch(Copy_u8EXTINum){
			case EXTI_NUM_0:
				CLR_BIT(MEXTI_u8_GICR_REG,MDIO_u8_PIN_6);
				break;

			case EXTI_NUM_1:
				CLR_BIT(MEXTI_u8_GICR_REG,MDIO_u8_PIN_7);
				break;

			case EXTI_NUM_2:
				CLR_BIT(MEXTI_u8_GICR_REG,MDIO_u8_PIN_5);
				break;
		}
	}

	return Local_u8ErrorState;
}


u8 MEXTI_u8EXTISetCallBack(u8 Copy_u8EXTINum,void(*Copy_Pf)(void))
{
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if((Copy_Pf!=STD_TYPES_NULL)&&(Copy_u8EXTINum<=EXTI_NUM_2)){
		Local_u8ErrorState=STD_TYPES_OK;
	/*Init Global Pointer to Function*/
	MEXTI_APF[Copy_u8EXTINum]=Copy_Pf;
	}
	return Local_u8ErrorState;
}


/*prototype for ISR EXTI0*/
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if(MEXTI_APF[EXTI_NUM_0]!=STD_TYPES_NULL)
		MEXTI_APF[EXTI_NUM_0]();
}

/*prototype for ISR EXTI1*/
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(MEXTI_APF[EXTI_NUM_1]!=STD_TYPES_NULL)
		MEXTI_APF[EXTI_NUM_1]();
}

/*prototype for ISR EXTI2*/
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if(MEXTI_APF[EXTI_NUM_2]!=STD_TYPES_NULL)
		MEXTI_APF[EXTI_NUM_2]();
}
