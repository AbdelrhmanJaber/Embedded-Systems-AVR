#ifndef MTMR_INTERFACE_H_
#define MTMR_INTERFACE_H_


/* TIMER 0*/

u8 MTMR_u8Timer0Init(void);

u8 MTMR_u8Timer0NormalModeTimeMapping(u8 hours,u16 minutes,u16 seconds,u16 milliSecond,u16 microSecond);

u8 MTMR_u8Timer0CTCModeTimeMapping(u8 hours,u16 minutes,u16 seconds,u16 milliSecond,u16 microSecond);

u8 MTMR_u8Timer0SetCallBack(u8 Copy_u8MTMRIndex , void(*Copy_PF)(void));

void MTMR_u8Timer0GeneratePWM(u16 Copy_u16CompareMatchValue);

void MTMR_u8Timer0SetCompareMatchValue(u16 Copy_u16CompareMatchValue);

void SetPreScaler();

void MTMR_u8StopTimer();

/* User Guide
 * A- to operate Normal Mode :
 * 1- Timer0 Init
 * 2- Timer0 Normal mode SetCallBack
 * 3- Timer0 Normal Mode Time Mapping
 *
 * B- to operate CTC Mode
 * 1- Timer0 Init
 * 2- Timer0 CTC SetCallBack
 * 3- Timer0 CTC Time mapping
 * 4- Timer0 CTC SetCompare Match Value
 *
 * C && D OPERATE PWM
 * 1- Timer0 INIT
 * 2- Generate PWM
 * */

/* preScaler value*/
#define NO_CLOCK_SOURCE               0
#define NO_PRESCALING                 1
#define PRESCALER_8                   2
#define PRESCALER_64                  3
#define PRESCALER_256                 4
#define PRESCALER_1024                5
#define EXTRNAL_CLK_FALLING_EDGE      6
#define EXTRNAL_CLK_RISING_EDGE       7


/*Timer 1*/
u8 MTMR_u8Timer1Init(void);
void MTMR_voidTMR1SetCompareMatchValueChannelA(u16 Copy_u8CompareMatchValue);


#define MTMR1_u16TopValue         2400
#define MTMR1_u16StartValue       250
#endif /* MTMR_INTERFACE_H_ */
