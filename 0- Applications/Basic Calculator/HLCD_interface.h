#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

/*prototype of lcd functions*/

/*function to init lcd module*/

void HLCD_voidINIT(void);

/*function to send command to LCD*/
u8 HLCD_u8SendCmnd(u8 Copy_u8Cmnd);
/*FUNCTION TO SEND A CHAR TO LCD*/
u8 HLCD_u8SendChar (u8 Copy_u8Char);

/*Function to set cursor*/
u8 HLCD_u8SetCursor(u8 Copy_u8LineNum,u8 Copy_u8CharNum);

u8 HLCD_u8SendString(u8 Copy_u8String[16],u8 Copy_u8Cursor);

u8 HLCD_u8SendNumber(s32 Copy_u8Number,u8 Copy_floatNumber,u8 Copy_negativeNumber);

u8 HLCD_u8GenerateSpecialCharacter(u8* Copy_Pu8_pattern,u8 Copy_u8_CGRAM_Index);

u8 HLCD_u8DisplaySpecialCharacter(u8 Copy_u8_PatternId,u8 Copy_u8LineNum,u8 Copy_u8CharNum);

u8 HLCD_u8ClearDisplay(void);

#define HLCD_u8_LINE_1      1
#define HLCD_u8_LINE_2      2

#define HLCD_u8_Position_0  0
#define HLCD_u8_Position_1   1
#define HLCD_u8_Position_2   2
#define HLCD_u8_Position_3   3
#define HLCD_u8_Position_4   4
#define HLCD_u8_Position_5   5
#define HLCD_u8_Position_6   6
#define HLCD_u8_Position_7   7
#define HLCD_u8_Position_8   8
#define HLCD_u8_Position_9   9
#define HLCD_u8_Position_10  10
#define HLCD_u8_Position_11  11
#define HLCD_u8_Position_12  12
#define HLCD_u8_Position_13  13
#define HLCD_u8_Position_14  14
#define HLCD_u8_Position_15  15

#endif
