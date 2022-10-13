#ifndef MADC_PRIVATE_H
#define MADC_PRIVATE_H

#define MADC_u8_ADMUX_REG     *((volatile u8*)0x27)
#define MADC_u8_ADCSRA_REG	  *((volatile u8*)0x26)

#define MADC_u8_SFIOR_REG     *((volatile u8*)0x50)

#define MADC_u8_ADCL_REG      *((volatile u8*)0x24)
#define MADC_u8_ADCH_REG      *((volatile u8*)0x25)

#define MADC_u8ADC_REG        *((volatile u16*)0x24)

#define MADC_u8_AREF                0b00000000
#define MADC_u8_AVCC                0b01000000
#define MADC_u8_INTERNAL_VREF       0b11000000

#define MADC_u8_Right_Adj           MADC_u8_ADMUX_REG & 0b11011111
#define MADC_u8_Left_Adj            MADC_u8_ADMUX_REG | 0b00100000

#define MADC_u8_Single_Conversion_Mood     0
#define MADC_u8_Auto_Triggerd_Mode         1

#define MADC_u8_Free_Running_Mode                 MADC_u8_SFIOR_REG | 0b00000000
#define MADC_u8_Analog_Comparator                 MADC_u8_SFIOR_REG | 0b00100000
#define MADC_u8_External_Interrupt_Request0       MADC_u8_SFIOR_REG | 0b01000000
#define MADC_u8_TimerOrCounter0_Compare_Match     MADC_u8_SFIOR_REG | 0b01100000
#define MADC_u8_TimerOrCounter0_Overflow          MADC_u8_SFIOR_REG | 0b10000000
#define MADC_u8_TimerOrCounter0_Compare_MatchB    MADC_u8_SFIOR_REG | 0b10100000
#define MADC_u8_TimerOrCounter1_Overflow          MADC_u8_SFIOR_REG | 0b11000000
#define MADC_u8_TimerOrCounter1_Capture_Event     MADC_u8_SFIOR_REG | 0b11100000

#endif
