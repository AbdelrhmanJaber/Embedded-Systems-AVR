#include"std_types.h"
#include"BIT_MATH.h"

#include"MDIO_interface.h"
#include"MADC_interface.h"

#include"HLED_interface.h"
#include"HLCD_interface.h"

int main(void){
	MDIO_u8INIT();
	MADC_voidINIT();
	HLCD_voidINIT();
	u16 Local_u16DigitalValue;
	u16 Local_u16AnalogValue;
	HLCD_u8SendChar('A');
	while(1){
		MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&Local_u16DigitalValue);
		Local_u16AnalogValue=(Local_u16DigitalValue*5000UL)/1024;
		if(Local_u16AnalogValue < 3000){
			HLED_u8_ALL_LED_OF(MDIO_u8_PORTB);
			HLCD_u8SendString("Good Morning ",0);
			HLCD_u8SetCursor(1,0);
		}
		else{
			HLED_u8_ALL_LED_ON(MDIO_u8_PORTB);
			HLCD_u8SendString("Good Evening ",0);
			HLCD_u8SetCursor(1,0);
		}
	}
}
