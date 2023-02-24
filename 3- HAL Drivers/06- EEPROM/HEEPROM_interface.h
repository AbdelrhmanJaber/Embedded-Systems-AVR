#ifndef HEEPROM_INTERFACE_H_
#define HEEPROM_INTERFACE_H_

void HEEPROM_voidInit(u8 Copy_u8frequency);

u8 HEEPROM_u8WriteByte(u8 Copy_u8Data , u16 Copy_u16Address);

u8 HEEPROM_u8ReadByte(u8* Copy_pu8RecievedData , u16 Copy_u16Address);

#define FREQ_100K     1

#define FREQ_200K     2

#define FREQ_300K     3

#define FREQ_400K     4

#endif /* HEEPROM_INTERFACE_H_ */
