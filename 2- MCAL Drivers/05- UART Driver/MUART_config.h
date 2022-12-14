#ifndef MUART_CONFIG_H_
#define MUART_CONFIG_H_

/*SPEED MOOD
 *1- NORMAL_SPEED
 *2- DOUBLE_SPEED  */
#define SPEED_MODE         NORMAL_SPEED

/*BIT MOOD
 * 1- ASYNCHRONOUS
   2- SYNCHRONOUS */
#define BIT_MODE  ASYNCHRONOUS

/*PARITY MOOD
 * 1- DISABLE_PARITY
 * 2- EVEN_PARITY
 * 3- ODD_PARITY*/
#define PARITY_MODE  DISABLE_PARITY

/*STOP BITS
 * 1- ONE
 * 2- TWO*/
#define STOP_BITS     TWO

/*DATA BITS
 * 1- FIVE_BITS
 * 2- SIX_BITS
 * 3- SEVEN_BITS
 * 4- EIGHT_BITS
 * 5- NINE_BITS*/
#define NINTH_BIT_EXISTS            1
#define NINTH_BIT_DOESNOT_EXIST     0

#define HAS_NINTH_BIT      NINTH_BIT_DOESNOT_EXIST
#define DATA_BITS_NUMBER    EIGHT_BITS

#define TOTAL_SPEED_MODE    2
#define TOTAL_BAUD_RATE     7


#endif /* MUART_CONFIG_H_ */
