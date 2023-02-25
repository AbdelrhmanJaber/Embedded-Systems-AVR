#include"std_types.h"
#include"BIT_MATH.h"

#include"MTMR_private.h"
#include"MTMR_config.h"
#include"MTMR_interface.h"

static void(*MTMR_APF[2])(void)={STD_TYPES_NULL , STD_TYPES_NULL};
static u32 prescalerValue=0;
static u32 totalOverflowNumbers = 0;
static u32 preloadValue = 0;
static u64 desiredTimeCTC = 0;
static u32 totalCTCNumbers = 0;

/* TIMER 0*/

/* Initialization of Timer0 */
u8 MTMR_u8Timer0Init(void){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/* Choose Timer0 Mode */
	MTMR_u8_TCCR0_REG &= 0xf8; //to clear the first three bits
	MTMR_u8_TCCR0_REG |= MTMR_u8_Timer_Mode;
	/* Switch on timer mode to enable the interrupt or set pin value (OC0) */
	switch(MTMR_u8_Timer_Mode){
		case MTMR_u8_Normal_Mode:{
			/* Enable Interrupt */
			SET_BIT(MTMR_u8_TIMSK_REG,0);
			break;
		}
		case MTMR_u8_CTC_Mode:{
			/* Enable Interrupt */
			SET_BIT(MTMR_u8_TIMSK_REG,1);
			/* set (OC0) and choose the mode*/
			MTMR_u8_TCCR0_REG |= MTMR_u8_CTC_OC0_MODE;
			break;
		}
		case MTMR_u8_Fast_PWM_Mode:{
			/* set (OC0) and choose the mode*/
			MTMR_u8_TCCR0_REG |= MTMR_u8_Fast_PWM_OC0_MODE;
			break;
		}
		case MTMR_u8_Phase_Correct_PWM_Mode:{
			/* set (OC0) and choose the mode*/
			MTMR_u8_TCCR0_REG |= MTMR_u8_Phase_Correct_PWM_OC0_MODE;
			break;
		}
	}
	/* set preScaler Value in a global Variable*/
	SetPreScaler();
	return Local_u8ErrorState;
}

void SetPreScaler(){
	/* set prescaler value in a globla variable*/
	switch(MTMR_PRESCALER_VALUE){
		case NO_PRESCALING: prescalerValue = 1;    break;
		case PRESCALER_8 :  prescalerValue = 8;    break;
		case PRESCALER_64:  prescalerValue = 64;   break;
		case PRESCALER_256: prescalerValue = 256;  break;
		case PRESCALER_1024:prescalerValue = 1024; break;
	}
}

void MTMR_u8StopTimer(){
	MTMR_u8_TCCR0_REG &= 0xf8;
}

void MTMR_u8Timer0SetCompareMatchValue(u16 Copy_u16CompareMatchValue){
	/*update total ctc number to do action in ISR*/
	totalCTCNumbers = (desiredTimeCTC / Copy_u16CompareMatchValue);
	/*update the register of compare match value*/
	MTMR_u8_OCR0_REG = Copy_u16CompareMatchValue;
	MTMR_u8_TCCR0_REG |= MTMR_PRESCALER_VALUE;
}

u8 MTMR_u8Timer0NormalModeTimeMapping(u8 hours,u16 minutes,u16 seconds,u16 milliSecond,u16 microSecond){
	u8 Local_u8ErrorState= STD_TYPES_OK;
	u64 timeOfOneTick,timeOfOverflow,numberOfOverlflow,desiredTime;
	if(hours==0 && minutes==0 && seconds==0 && milliSecond==0 && microSecond==0){
		MTMR_u8StopTimer();
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	else{
	  timeOfOneTick=prescalerValue/8; //in microsecond
	  timeOfOverflow=256*timeOfOneTick; //in microsecond
	  desiredTime=((hours*3600000000UL));
	  desiredTime+=(minutes*60000000UL);
	  desiredTime+=(seconds*1000000UL);
	  desiredTime+=(milliSecond*1000);
	  desiredTime+=(microSecond);
	  numberOfOverlflow=desiredTime/256;
	  preloadValue=256-(desiredTime %(timeOfOverflow));
	  totalOverflowNumbers=numberOfOverlflow+1;
	  MTMR_u8_TCNT0_REG = preloadValue;
	  MTMR_u8_TCCR0_REG |= MTMR_PRESCALER_VALUE;
	}
	return Local_u8ErrorState;
}

u8 MTMR_u8Timer0CTCModeTimeMapping(u8 hours,u16 minutes,u16 seconds,u16 milliSecond,u16 microSecond){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(hours==0 && minutes==0 && seconds==0 && milliSecond==0 && microSecond==0){
		MTMR_u8StopTimer();
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	else{
		desiredTimeCTC=((hours*3600000000UL));
		desiredTimeCTC+=(minutes*60000000UL);
		desiredTimeCTC+=(seconds*1000000UL);
		desiredTimeCTC+=(milliSecond*1000);
		desiredTimeCTC+=(microSecond);
	}
	return Local_u8ErrorState;
}

u8 MTMR_u8Timer0SetCallBack(u8 Copy_u8MTMRIndex , void(*Copy_PF)(void)){
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_PF != STD_TYPES_NULL){
		Local_u8ErrorState = STD_TYPES_OK;
		MTMR_APF[Copy_u8MTMRIndex] = Copy_PF;
	}
	return Local_u8ErrorState;
}

void MTMR_u8Timer0GeneratePWM(u16 Copy_u16CompareMatchValue){
	MTMR_u8_OCR0_REG = Copy_u16CompareMatchValue;
	MTMR_u8_TCCR0_REG |= MTMR_PRESCALER_VALUE;
}

/* ISR For timer0 normal mode*/

void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	static u16 Local_u16Counter = 0;
	Local_u16Counter++;
	if(Local_u16Counter == totalOverflowNumbers && MTMR_APF[0] != STD_TYPES_NULL){
		/* set preload value*/
		MTMR_u8_TCNT0_REG = preloadValue;
		/* call the function*/
		MTMR_APF[0]();
		Local_u16Counter = 0;
	}
}

/* ISR For timer0 CTC mode*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	static u16 Local_u16Counter = 0;
	Local_u16Counter++;
	if(Local_u16Counter == totalCTCNumbers && MTMR_APF[1] != STD_TYPES_NULL){
		/* call the function*/
		MTMR_APF[1]();
		Local_u16Counter = 0;
	}
}


/* TIMER 1 TO Generate an Efficient PWM and Control Special Types of Motors*/

u8 MTMR_u8Timer1Init(void){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/*select mode of the timer*/
	switch(MTMR1_u8Mode){
	case PWM_PHASE_AND_FREQ_CORRECT_ICR1_TOP:{
		CLR_BIT(MTMR_u8_TCCR1B_REG,3);
		SET_BIT(MTMR_u8_TCCR1B_REG,4);
		CLR_BIT(MTMR_u8_TCCR1A_REG,0);
		CLR_BIT(MTMR_u8_TCCR1A_REG,1);
	}
	break;
	case PWM_PHASE_AND_FREQ_CORRECT_OCR1A_TOP:{
		CLR_BIT(MTMR_u8_TCCR1B_REG,3);
		SET_BIT(MTMR_u8_TCCR1B_REG,4);
		SET_BIT(MTMR_u8_TCCR1A_REG,0);
		CLR_BIT(MTMR_u8_TCCR1A_REG,1);
	}
	break;
	case PWM_FAST_MODE_ICR1_TOP :{
	  SET_BIT(MTMR_u8_TCCR1B_REG,3);
	  SET_BIT(MTMR_u8_TCCR1B_REG,4);
	  CLR_BIT(MTMR_u8_TCCR1A_REG,0);
	  SET_BIT(MTMR_u8_TCCR1A_REG,1);
	}
	break;
	case PWM_FAST_MODE_OCR1A_TOP : {
		SET_BIT(MTMR_u8_TCCR1B_REG,3);
		SET_BIT(MTMR_u8_TCCR1B_REG,4);
		SET_BIT(MTMR_u8_TCCR1A_REG,0);
		SET_BIT(MTMR_u8_TCCR1A_REG,1);
	}
	break;
}
	/* Select the mode of OCR Channel A*/
	SET_BIT(MTMR_u8_TCCR1A_REG,7);
	CLR_BIT(MTMR_u8_TCCR1A_REG,6);

	/* Select the mode of OCR Channel A*/
	SET_BIT(MTMR_u8_TCCR1B_REG,7);
	CLR_BIT(MTMR_u8_TCCR1B_REG,6);

	/*Setting Top and bottom values */
	switch(MTMR1_u8Mode){
	case PWM_PHASE_AND_FREQ_CORRECT_ICR1_TOP : {
	/* Set Top Value*/
	MTMR_u16_ICR1_REG = MTMR1_u16TopValue;
	/* Set Initialize Value */
	MTMR_u16_OCR1A_REG = MTMR1_u16StartValue;
	}
	break;

	case PWM_PHASE_AND_FREQ_CORRECT_OCR1A_TOP : {
	/* Set Top Value*/
	MTMR_u16_OCR1A_REG = MTMR1_u16TopValue;
	/* Set Initialize Value */
	MTMR_u16_OCR1B_REG = MTMR1_u16StartValue;
	}
	break;

	case PWM_FAST_MODE_ICR1_TOP : {
	/* Set Top Value*/
	MTMR_u16_ICR1_REG = MTMR1_u16TopValue;
	/* Set Initialize Value */
	MTMR_u16_OCR1A_REG = MTMR1_u16StartValue;
	}
	break;

	case PWM_FAST_MODE_OCR1A_TOP : {
	/* Set Top Value*/
	MTMR_u16_OCR1A_REG = MTMR1_u16TopValue;
	/* Set Initialize Value */
	MTMR_u16_OCR1B_REG = MTMR1_u16StartValue;
	}
	break;
}
	/* Set PreScaler = 8*/
	CLR_BIT(MTMR_u8_TCCR1B_REG,0);
	SET_BIT(MTMR_u8_TCCR1B_REG,1);
	CLR_BIT(MTMR_u8_TCCR1B_REG,2);
	return Local_u8ErrorState;
}

void MTMR_voidTMR1SetCompareMatchValueChannelA(u16 Copy_u8CompareMatchValue){
	MTMR_u16_OCR1A_REG = Copy_u8CompareMatchValue;
}

void MTMR_voidTMR1SetCompareMatchValueChannelB(u16 Copy_u8CompareMatchValue){
	MTMR_u16_OCR1B_REG = Copy_u8CompareMatchValue;
}

