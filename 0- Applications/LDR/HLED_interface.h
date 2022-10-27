#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

u8 HLED_u8_Single_LED_ON(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id);
u8 HLED_u8_Single_LED_OF(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id);
u8 HLED_u8_Single_LED_TOGGLE_ms(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u32 Copy_u32_Delay_Time);

u8 HLED_u8_ALL_LED_ON(u8 Copy_u8_Port_Id);
u8 HLED_u8_ALL_LED_OF(u8 Copy_u8_Port_Id);
u8 HLED_u8_ALL_LED_TOGGLE_ms(u8 Copy_u8_Port_Id,u32 Copy_u32_Delay_Time);

#endif
