#include"std_types.h"
#include"BIT_MATH.h"

#include"MDIO_interface.h"
#include"MADC_interface.h"

#include"HLCD_interface.h"

#define F_CPU     8000000UL
#include<avr/delay.h>


void StopMotor(void){
	MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN_6,MDIO_u8_LOW);
	MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN_6,MDIO_u8_LOW);
}

void ClockWiseMotor(void){
	MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN_6,MDIO_u8_HIGH);
	MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN_6,MDIO_u8_LOW);
}

void AntiClockWiseMotor(void){
	MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN_6,MDIO_u8_LOW);
	MDIO_u8SetPinValue(MDIO_u8_PORTA,MDIO_u8_PIN_6,MDIO_u8_HIGH);
}


int main(){

	MDIO_u8INIT();
	HLCD_voidINIT();
	MADC_voidINIT();
	u32 cursor=0;
	u8 pattern[8]={0x04,0x0A,0x0A,0x04,0x0E,0x04,0x04,0x0A};
	HLCD_u8GenerateSpecialCharacter(pattern,0);
    HLCD_u8DisplaySpecialCharacter(0,1,0);
    StopMotor();
    u16 digitalValue,analogValue=0,previousValue=0;
	while(1){
		MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
		analogValue=(digitalValue*5000UL)/1024;
		if(analogValue==0){
			StopMotor();
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			HLCD_u8DisplaySpecialCharacter(0,1,0);
			HLCD_u8SetCursor(2,0);
			MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			analogValue=(digitalValue*5000UL)/1024;
			_delay_ms(200);
		}

		else if(analogValue<=312){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,1);
			 HLCD_u8SetCursor(2,1);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}


		else if(analogValue<=624){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,2);
			 HLCD_u8SetCursor(2,2);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);

		}

		else if(analogValue<=936){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,3);
			 HLCD_u8SetCursor(2,3);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=1248){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,4);
			 HLCD_u8SetCursor(2,4);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=1560){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,5);
			 HLCD_u8SetCursor(2,5);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=1872){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,6);
			 HLCD_u8SetCursor(2,6);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=2184){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,7);
			 HLCD_u8SetCursor(2,7);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=2496){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,8);
			 HLCD_u8SetCursor(2,8);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=2808){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,9);
			 HLCD_u8SetCursor(2,9);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=3120){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,10);
			 HLCD_u8SetCursor(2,10);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=3432){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,11);
			 HLCD_u8SetCursor(2,11);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=3744){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,12);
			 HLCD_u8SetCursor(2,12);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=4056){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,13);
			 HLCD_u8SetCursor(2,13);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=4368){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,14);
			 HLCD_u8SetCursor(2,14);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}

		else if(analogValue<=5000){
			HLCD_u8ClearDisplay();
			_delay_ms(50);
			 HLCD_u8DisplaySpecialCharacter(0,1,15);
			 HLCD_u8SetCursor(2,15);
			 if(analogValue > previousValue)
				 ClockWiseMotor();
			 else
				 AntiClockWiseMotor();

			 previousValue=analogValue;
			 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
			 analogValue=(digitalValue*5000UL)/1024;
			 _delay_ms(200);
		}
		 /*while(analogValue==0){
		cursor=analogValue/312;
		HLCD_u8ClearDisplay();
		_delay_ms(50);
		HLCD_u8DisplaySpecialCharacter(0,1,cursor);
		StopMotor();
		MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
		analogValue=(digitalValue*5000UL)/1024;
		 _delay_ms(150);
		 }
		 while(analogValue > previousValue){
			 cursor=analogValue/312;
			 HLCD_u8ClearDisplay();
			 _delay_ms(50);
			  HLCD_u8DisplaySpecialCharacter(0,1,cursor);
		  AntiClockWiseMotor();
		  previousValue=analogValue;
		  MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
		  analogValue=(digitalValue*5000UL)/1024;
		  _delay_ms(150);
		 }
		 while(analogValue < previousValue){
			 cursor=analogValue/312;
			 HLCD_u8ClearDisplay();
			 _delay_ms(50);
			  HLCD_u8DisplaySpecialCharacter(0,1,cursor);
			 ClockWiseMotor();
		 previousValue=analogValue;
		 MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0,&digitalValue);
		 analogValue=(digitalValue*5000UL)/1024;
		 _delay_ms(150);
		 }*/
	}
	return 0;
}

