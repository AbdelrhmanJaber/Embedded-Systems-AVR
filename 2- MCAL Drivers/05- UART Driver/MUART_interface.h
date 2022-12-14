#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

void MUART_voidInit(void);

void MUART_voidSendByte(u8 data);

void MUART_voidSendByteAsynch(u8 data);

u8 MUART_u8RecieveByte();

void MUART_voidRecieveByteAsynch(u8* data);

void MUART_voidSendStringSynch(u8* word);

void MUART_Pu8RecieveStringSynch(u8* word);

void MUART_SendStringAsynch(u8* Copy_String);

void MUART_SetCallBackTransmitter(void(*Copy_Pf)(void));

void MUART_RecieveStringAsynch(u8* word);

void MUART_SetCallBackReciever(void(*Copy_Pf)(void));



#define SPEED_IS_NORMAL       0
#define SPEED_IS_DOUBLE       1

#define BAUDRATE_2400           0
#define BAUDRATE_4800           1
#define BAUDRATE_9600           2
#define BAUDRATE_14400          3
#define BAUDRATE_19200          4
#define BAUDRATE_28800          5
#define BAUDRATE_38400          6


#endif /* MUART_INTERFACE_H_ */
