#ifndef HLCD_CONFIG_H
#define HLCD_CONFIG_H

//CONFIG for Control Pins
#define HLCD_u8_RS_PIN       MDIO_u8_PIN_0
#define HLCD_u8_RS_PORT		 MDIO_u8_PORTC

#define HLCD_u8_RW_PIN       MDIO_u8_PIN_1
#define HLCD_u8_RW_PORT		 MDIO_u8_PORTC

#define HLCD_u8_EN_PIN       MDIO_u8_PIN_2
#define HLCD_u8_EN_PORT		 MDIO_u8_PORTC

#define FunctionSet          0X38
#define DisplayControl       0x0f
#define DisplayClear         0x01
#define EntryMode            0x06
#define ReturnCGROM          0x02

/*Data Pins*/
#define HCLD_u8_DATA_PORT    MDIO_u8_PORTD
#endif
