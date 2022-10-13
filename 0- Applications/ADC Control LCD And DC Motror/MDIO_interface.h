#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H

#define MDIO_u8_PORTA    0
#define MDIO_u8_PORTB    1
#define MDIO_u8_PORTC    2
#define MDIO_u8_PORTD    3

#define MDIO_u8_PIN_0    0
#define MDIO_u8_PIN_1    1
#define MDIO_u8_PIN_2    2
#define MDIO_u8_PIN_3    3
#define MDIO_u8_PIN_4    4
#define MDIO_u8_PIN_5    5
#define MDIO_u8_PIN_6    6
#define MDIO_u8_PIN_7    7

#define MDIO_u8_OUTPUT            1
#define MDIO_u8_INPUT_PULLED_UP   0
#define MDIO_u8_INPUT_FLOATING    2

#define MDIO_u8_LOW                0
#define MDIO_u8_HIGH               1


#define SWITCH_ON                  0

u8 MDIO_u8SetPinDirection(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u8 Copy_u8_Pin_Direction);
u8 MDIO_u8SetPinValue(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u8 Copy_u8_Pin_Value);
u8 MDIO_u8GetPinValue(u8 Copy_u8_Port_Id,u8 Copy_u8_Pin_Id,u8* Copy_Pu8_Pin_Value);

u8 MDIO_u8SetPortDirection(u8 Copy_u8_Port_Id,u8 Copy_u8_Port_Direction);
u8 MDIO_u8SetPortValue(u8 Copy_u8_Port_Id,u8 Copy_u8_Port_Value);
u8 MDIO_u8GetPortValue(u8 Copy_u8_Port_Id,u8* Copy_Pu8_Port_Value);


/*Prototype of INIT Functions*/
u8 MDIO_u8INIT(void);

#endif
