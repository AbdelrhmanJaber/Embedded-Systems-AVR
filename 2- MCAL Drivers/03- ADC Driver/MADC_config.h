#ifndef MADC_CONFIG_H
#define MADC_CONFIG_H

/* Config VREF */
/* Options : MADC_u8_AREF
 *           MADC_u8_AVCC
 *           MADC_u8_INTERNAL_VREF
 *           */

#define MADC_u8_ADC_VREF         MADC_u8_AVCC
#define MADC_u8_Adj_Direction    MADC_u8_Right_Adj

#define MADC_u8_Conversion_Mood  MADC_u8_Single_Conversion_Mood

#define MADC_u8_Auto_Triggerd_Source        MADC_u8_Free_Running_Mode

#define  MADC_u32_MAX_TIMEOUT   100000

#endif
