#ifndef MTMR_CONFIG_H_
#define MTMR_CONFIG_H_

/* modes of operation
 * 1-MTMR_u8_Normal_Mode
 * 2-MTMR_u8_CTC_Mode
 * 3-MTMR_u8_Fast_PWM_Mode
 * 4-MTMR_u8_Phase_Correct_PWM_Mode*/

#define MTMR_u8_Timer_Mode            MTMR_u8_Phase_Correct_PWM_Mode

/* CTC modes of OC0
 * 1-CTC_u8_Normal_Mode
   2-CTC_u8_Toggle_Mode
   3-CTC_u8_Non_Inverted_Mode
   4-CTC_u8_Inverted_Mode	*/
#define MTMR_u8_CTC_OC0_MODE           CTC_u8_Inverted_Mode

/* FAST PWM modes of OC0
 * 1-FAST_PWM_u8_Normal_Mode
   2-FAST_PWM_u8_Toggle_Mode
   3-FAST_PWM_u8_Non_Inverted_Mode
   4-FAST_PWM_u8_Inverted_Mode	*/

#define MTMR_u8_Fast_PWM_OC0_MODE      FAST_PWM_u8_Non_Inverted_Mode

/* FAST PWM modes of OC0
 * 1-PHASE_CORRECT_PWM_u8_Normal_Mode
   2-PHASE_CORRECT_PWM_u8_Toggle_Mode
   3-PHASE_CORRECT_PWM_u8_Non_Inverted_Mode
   4-PHASE_CORRECT_PWM_u8_Inverted_Mode	*/

#define MTMR_u8_Phase_Correct_PWM_OC0_MODE   PHASE_CORRECT_PWM_u8_Non_Inverted_Mode

/*choose the preScaler
 * 1-NO_CLOCK_SOURCE
   2-NO_PRESCALING
   3-PRESCALER_8
   4-PRESCALER_64
   5-PRESCALER_256
   6-PRESCALER_1024
   7-EXTRNAL_CLK_FALLING_EDGE
   8-EXTRNAL_CLK_RISING_EDGE */

#define MTMR_PRESCALER_VALUE            PRESCALER_8


/*   TIMER 1  */
#define MTMR1_u8Mode        PWM_PHASE_AND_FREQ_CORRECT_ICR1_TOP

#define PWM_PHASE_AND_FREQ_CORRECT_ICR1_TOP     0
#define PWM_PHASE_AND_FREQ_CORRECT_OCR1A_TOP    1
#define PWM_FAST_MODE_ICR1_TOP                  2
#define PWM_FAST_MODE_OCR1A_TOP                 3

#endif /* MTMR_CONFIG_H_ */
