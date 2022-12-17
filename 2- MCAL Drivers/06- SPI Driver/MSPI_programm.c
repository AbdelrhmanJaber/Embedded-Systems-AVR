#include"std_types.h"
#include"Bit_Math.h"

#include"MSPI_private.h"
#include"MSPI_config.h"
#include"MSPI_interface.h"

void MSPI_voidMasterInit(void){
	/***ENABLE SPI***/
	SET_BIT(MSPI_u8_SPCR_REG , 6);
	/***Data order***/
	MSPI_u8_SPCR_REG |= DataOrder;
	/***Select Master Mode***/
	SET_BIT(MSPI_u8_SPCR_REG , 4);
	/***Clock Polarity***/
	MSPI_u8_SPCR_REG |= ClockPolarity;
	/***Clock Phase***/
	MSPI_u8_SPCR_REG |= ClockPhase;
	/***Speed Mode***/
	MSPI_u8_SPSR_REG |= SpeedMode;
	#if(SpeedMode == NormalSpeed)
	MSPI_u8_SPCR_REG |= NormalClockRate;
	#elif(speedMode == DoubleSpeed)
	MSPI_u8_SPCR_REG |= DoubleClockRate;
	#endif
}

void MSPI_voidSlaveInit(void){
	/***ENABLE SPI***/
	SET_BIT(MSPI_u8_SPCR_REG , 6);
	/***Data order***/
	MSPI_u8_SPCR_REG |= DataOrder;
	/***Select Master Mode***/
	CLR_BIT(MSPI_u8_SPCR_REG , 4);
	/***Clock Polarity***/
	MSPI_u8_SPCR_REG |= ClockPolarity;
	/***Clock Phase***/
	MSPI_u8_SPCR_REG |= ClockPhase;
	/***Speed Mode***/
	MSPI_u8_SPSR_REG |= SpeedMode;
}

u8 MSPI_u8Transeive(u8 data){
	MSPI_u8_SPDR_REG = data;
	while(!(GET_BIT(MSPI_u8_SPSR_REG , 7)));
	return MSPI_u8_SPDR_REG;
}
