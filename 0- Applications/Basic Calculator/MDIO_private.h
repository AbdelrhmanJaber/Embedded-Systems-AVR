#ifndef MDIO_PRIVATE_H
#define MDIO_PRIVATE_H

#define MDIO_u8_PORTA_REG  *((volatile u8*)0x3B)
#define MDIO_u8_DDRA_REG   *((volatile u8*)0x3A)
#define MDIO_u8_PINA_REG   *((const volatile u8*)0x39)

#define MDIO_u8_PORTB_REG  *((volatile u8*)0x38)
#define MDIO_u8_DDRB_REG   *((volatile u8*)0x37)
#define MDIO_u8_PINB_REG   *((const volatile u8*)0x36)

#define MDIO_u8_PORTC_REG  *((volatile u8*)0x35)
#define MDIO_u8_DDRC_REG   *((volatile u8*)0x34)
#define MDIO_u8_PINC_REG   *((const volatile u8*)0x33)

#define MDIO_u8_PORTD_REG  *((volatile u8*)0x32)
#define MDIO_u8_DDRD_REG   *((volatile u8*)0x31)
#define MDIO_u8_PIND_REG   *((const volatile u8*)0x30)

/*MACROS Definition for init Direction and Values*/

#define MDIO_u8_INIT_INPUT         0
#define MDIO_u8_INIT_OUTPUT        1

#define MDIO_u8_INIT_LOW           0
#define MDIO_u8_INIT_HIGH          1
#define MDIO_u8_INIT_FLOATING      0
#define MDIO_u8_INIT_PULLED_UP     1

/*CONC FUNCTIONS*/
#define PRIVATE_u8_CONC(b7,b6,b5,b4,b3,b2,b1,b0)   PRIVATE_u8_CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define PRIVATE_u8_CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif
