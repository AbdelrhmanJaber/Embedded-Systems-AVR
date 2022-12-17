#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

#define MSPI_u8_SPCR_REG	*(volatile u8*)(0x2D)

#define MSPI_u8_SPSR_REG	*(volatile u8*)(0x2E)

#define MSPI_u8_SPDR_REG	*(volatile u8*)(0x2F)

#define FirstLSB            0b00100000
#define FirstMSB            0b00000000

#define LeadingEdgeIsFallingEdge  0b00001000
#define LeadingEdgeIsRaisingEdge  0b00000000

#define LeadingEdgeIsSample       0b00000000
#define LeadingEdgeIsSetup        0b00000100

#define NormalSpeed               0b00000000
#define DoubleSpeed               0b00000001

#define NormalFoscDevidedBy4            0b00000000
#define NormalFoscDevidedBy16           0b00000001
#define NormalFoscDevidedBy64           0b00000010
#define NormalFoscDevidedBy128          0b00000011

#define DoubleFoscDevidedBy2            0b00000000
#define DoubleFoscDevidedBy8 			0b00000001
#define DoubleFoscDevidedBy32           0b00000010
#define DoubleFoscDevidedBy64           0b00000011

#endif /* MSPI_PRIVATE_H_ */
