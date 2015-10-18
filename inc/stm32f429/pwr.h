#ifndef STM32F429_PWR__H_
#define STM32F429_PWR__H_

#include "reg.h"

typedef struct
{
	volatile unsigned long CR;   /*!< PWR power control register,        Address offset: 0x00 */
	volatile unsigned long CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;

#define setMcuPwrVos(x)		setRegField(PWR->CR, 0x3UL, x, 14)

#endif
