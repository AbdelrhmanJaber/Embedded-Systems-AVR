#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NUM)    (REG=REG|(1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)    (REG=REG&(~(1<<BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM) (REG=REG^(1<<BIT_NUM))
#define TOGGLE_PORT(REG)        (REG=REG^(0xff))
#define GET_BIT(REG,BIT_NUM)    ((REG>>BIT_NUM)&1)    

#endif
