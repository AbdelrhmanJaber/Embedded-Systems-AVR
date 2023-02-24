#ifndef MTWI_PRIVATE_H_
#define MTWI_PRIVATE_H_

#define MTWI_u8_TWDR_REG                *((volatile u8*)0x23)
#define MTWI_u8_TWAR_REG                *((volatile u8*)0x22)

#define MTWI_u8_TWSR_REG                *((volatile u8*)0x21)
#define MTWI_u8_TWBR_REG                *((volatile u8*)0x20)

#define MTWI_u8_TWCR_REG                *((volatile u8*)0x56)

static u8 status(void);

#define   START_CONDITION_STATUS            0x08

#define   REPEATED_START_CONDITION_STATUS   0x10

#define   SEND_SLAVE_ADDRESS_WRITE_STATUS   0x18

#define   SEND_SLAVE_ADDRESS_READ_STATUS    0x40

#define   WRITE_BYTE_STATUS                 0x28

#define   RECEIVE_BYTE_STATUS               0x50

#define   GET_STATUS                        0xf8

#endif /* MTWI_PRIVATE_H_ */
