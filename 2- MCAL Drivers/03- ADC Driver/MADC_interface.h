#ifndef MADC_INTERFACE_H
#define MADC_INTERFACE_H

void MADC_voidINIT(void);

u8 MADC_u8GetDigitalValueSynch(u8 Copy_u8ChannelNum,u16 * Copy_Pu16DigitalValue);
u8 MADC_u8GetDigitalValueAsynch(u8 Copy_u8ChannelNum,void(*Copy_PfNotification)(u16));

#define MADC_u8_CHANNEL_0      0
#define MADC_u8_CHANNEL_1      1
#define MADC_u8_CHANNEL_2	   2
#define MADC_u8_CHANNEL_3	   3
#define MADC_u8_CHANNEL_4      4
#define MADC_u8_CHANNEL_5      5
#define MADC_u8_CHANNEL_6      6
#define MADC_u8_CHANNEL_7      7

#define MADC_u8_NOT_BUSY       1
#define MADC_u8_BUSY           0

#endif
