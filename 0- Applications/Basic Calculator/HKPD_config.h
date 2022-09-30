#ifndef HKPD_CONFIG_H
#define HKPD_CONFIG_H
/* Rows */
#define HKPD_u8_R0_PIN       MDIO_u8_PIN_3
#define HKPD_u8_R0_PORT      MDIO_u8_PORTA

#define HKPD_u8_R1_PIN       MDIO_u8_PIN_2
#define HKPD_u8_R1_PORT      MDIO_u8_PORTA

#define HKPD_u8_R2_PIN       MDIO_u8_PIN_1
#define HKPD_u8_R2_PORT      MDIO_u8_PORTA

#define HKPD_u8_R3_PIN       MDIO_u8_PIN_0
#define HKPD_u8_R3_PORT      MDIO_u8_PORTA

/* Columns */
#define HKPD_u8_C0_PIN       MDIO_u8_PIN_4
#define HKPD_u8_C0_PORT      MDIO_u8_PORTA

#define HKPD_u8_C1_PIN       MDIO_u8_PIN_5
#define HKPD_u8_C1_PORT      MDIO_u8_PORTA

#define HKPD_u8_C2_PIN       MDIO_u8_PIN_6
#define HKPD_u8_C2_PORT      MDIO_u8_PORTA

#define HKPD_u8_C3_PIN       MDIO_u8_PIN_7
#define HKPD_u8_C3_PORT      MDIO_u8_PORTA

#define HKPD_KEYS            {{'1','2','3','+'}, \
		                     {'4','5','6','-'},  \
		                     {'7','8','9','*'},  \
		                     {'0','=','%','/'} }

#endif
