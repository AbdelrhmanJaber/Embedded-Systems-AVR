#ifndef MTMR_PRIVATE_H_
#define MTMR_PRIVATE_H_

#define MTMR_u8_TCCR0_REG            *((volatile u8*)0x53)

#define MTMR_u8_TCNT0_REG            *((volatile u8*)0x52)

#define MTMR_u8_OCR0_REG            *((volatile u8*)0x5c)

#define MTMR_u8_TIMSK_REG            *((volatile u8*)0x59)

#define MTMR_u8_TIFR_REG            *((volatile u8*)0x58)


/* Timer0 Mode*/
#define MTMR_u8_Normal_Mode                  0b00000000
#define MTMR_u8_CTC_Mode					 0b00001000
#define MTMR_u8_Fast_PWM_Mode				 0b01001000
#define MTMR_u8_Phase_Correct_PWM_Mode		 0b01000000

/* CTC OC0 Mode*/
#define CTC_u8_Normal_Mode                   0b00000000
#define CTC_u8_Toggle_Mode					 0b00010000
#define CTC_u8_Non_Inverted_Mode			 0b00100000
#define CTC_u8_Inverted_Mode				 0b00110000

/* FAST PWM OC0 Mode*/
#define FAST_PWM_u8_Normal_Mode                   0b00000000
#define FAST_PWM_u8_Toggle_Mode					  0b00010000
#define FAST_PWM_u8_Non_Inverted_Mode			  0b00100000
#define FAST_PWM_u8_Inverted_Mode				  0b00110000

/* PHASE CORRECT PWM OC0 Mode*/
#define PHASE_CORRECT_PWM_u8_Normal_Mode                      0b00000000
#define PHASE_CORRECT_PWM_u8_Toggle_Mode					  0b00010000
#define PHASE_CORRECT_PWM_u8_Non_Inverted_Mode			      0b00100000
#define PHASE_CORRECT_PWM_u8_Inverted_Mode				      0b00110000


/*     TIMER 1      */


#define MTMR_u8_TCCR1A_REG          *((volatile u8*)0x4F)

#define MTMR_u8_TCCR1B_REG          *((volatile u8*)0x4E)

#define MTMR_u16_TCNT1_REG          *((volatile u16*)0x4C)

#define MTMR_u16_OCR1A_REG          *((volatile u16*)0x4A)

#define MTMR_u16_OCR1B_REG          *((volatile u16*)0x48)

#define MTMR_u16_ICR1_REG          *((volatile u16*)0x46)






#endif /* MTMR_PRIVATE_H_ */

