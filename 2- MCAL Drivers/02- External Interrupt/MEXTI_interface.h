#ifndef MEXTI_INTERFACE_H
#define MEXTI_INTERFACE_H

u8 MEXTI_u8EXTIEnable(u8 Copy_u8EXTINum,u8 Copy_u8EXTISource);

u8 MEXTI_u8EXTIDisable(u8 Copy_u8EXTINum);

u8 MEXTI_u8EXTISetCallBack(u8 Copy_u8EXTINum,void(*Copy_Pf)(void));

#define EXTI_NUM_0    0
#define EXTI_NUM_1    1
#define EXTI_NUM_2    2

#define EXTI_FALLING_EDGE   0
#define EXTI_RAISING_EDGE   1
#define EXTI_LEVEL_EDGE     2
#define EXTI_ANY_CHANGE     3

#define MAX_Copy_u8EXTISource   3

#endif
