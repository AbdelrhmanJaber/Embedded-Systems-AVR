#ifndef MDIO_CONFIG_H
#define MDIO_CONFIG_H
/*configuration for pins Direction*/
/*Options: 1- MDIO_u8_INIT_INPUT
           2- MDIO_u8_INIT_OUTPUT*/
/*PORTA*/
#define MDIO_u8_PA0_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PA1_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PA2_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PA3_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PA4_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PA5_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PA6_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PA7_DIRECTION      MDIO_u8_INIT_INPUT

/*PORTB*/
#define MDIO_u8_PB0_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PB1_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PB2_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PB3_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PB4_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PB5_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PB6_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PB7_DIRECTION      MDIO_u8_INIT_INPUT

/*PORTC*/
#define MDIO_u8_PC0_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PC1_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PC2_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PC3_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PC4_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PC5_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PC6_DIRECTION      MDIO_u8_INIT_INPUT
#define MDIO_u8_PC7_DIRECTION      MDIO_u8_INIT_OUTPUT

/*PORTD*/
#define MDIO_u8_PD0_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PD1_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PD2_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PD3_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PD4_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PD5_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PD6_DIRECTION      MDIO_u8_INIT_OUTPUT
#define MDIO_u8_PD7_DIRECTION      MDIO_u8_INIT_OUTPUT

/*configuration for pins Value*/
/*Options: 1- MDIO_u8_INIT_LOW
           2- MDIO_u8_INIT_HIGH
           3- MDIO_u8_INIT_FLOATING
           4- MDIO_u8_INIT_PULLED_UP*/
/*PORTA*/
#define MDIO_u8_PA0_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PA1_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PA2_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PA3_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PA4_value      MDIO_u8_INIT_PULLED_UP
#define MDIO_u8_PA5_value      MDIO_u8_INIT_PULLED_UP
#define MDIO_u8_PA6_value      MDIO_u8_INIT_PULLED_UP
#define MDIO_u8_PA7_value      MDIO_u8_INIT_PULLED_UP

/*PORTB*/
#define MDIO_u8_PB0_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PB1_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PB2_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PB3_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PB4_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PB5_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PB6_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PB7_value      MDIO_u8_INIT_FLOATING

/*PORTC*/
#define MDIO_u8_PC0_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PC1_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PC2_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PC3_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PC4_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PC5_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PC6_value      MDIO_u8_INIT_FLOATING
#define MDIO_u8_PC7_value      MDIO_u8_INIT_HIGH

/*PORTD*/
#define MDIO_u8_PD0_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PD1_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PD2_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PD3_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PD4_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PD5_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PD6_value      MDIO_u8_INIT_HIGH
#define MDIO_u8_PD7_value      MDIO_u8_INIT_HIGH
#endif
