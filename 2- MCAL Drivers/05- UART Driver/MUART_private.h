#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

#define MUART_u8_UDR_REG		*((volatile u8*)0x2C)

#define MUART_u8_UCSRA_REG		*((volatile u8*)0x2B)

#define MUART_u8_UCSRB_REG		*((volatile u8*)0x2A)

#define MUART_u8_UBRRL_REG		*((volatile u8*)0x29)

#define MUART_u8_UBRRH_REG		*((volatile u8*)0x40)

#define MUART_u8_UCSRC_REG		*((volatile u8*)0x40)

#define NORMAL_SPEED     0b11111101
#define DOUBLE_SPEED     0b11111111

#define ASYNCHRONOUS     0b00000000
#define SYNCHRONOUS      0b01000000

#define DISABLE_PARITY   0b00000000
#define EVEN_PARITY      0b00100000
#define ODD_PARITY       0b00110000

#define ONE              0b00000000
#define TWO              0b00001000

#define FIVE_BITS        0b00000000
#define SIX_BITS         0b00000010
#define SEVEN_BITS       0b00000100
#define EIGHT_BITS       0b00000110
#define NINE_BITS        0b00000110

void TX_Byte(void);

void RX_String(void);

void TX_String(void);

void RX_Byte(void);
#endif /* MUART_PRIVATE_H_ */
