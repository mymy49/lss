#ifndef STM32F429_I2C__H_
#define STM32F429_I2C__H_

#include "peripheral.h"
#include "reg.h"

/** 
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
	volatile unsigned long CR1;        /*!< I2C Control register 1,     Address offset: 0x00 */
	volatile unsigned long CR2;        /*!< I2C Control register 2,     Address offset: 0x04 */
	volatile unsigned long OAR1;       /*!< I2C Own address register 1, Address offset: 0x08 */
	volatile unsigned long OAR2;       /*!< I2C Own address register 2, Address offset: 0x0C */
	volatile unsigned long DR;         /*!< I2C Data register,          Address offset: 0x10 */
	volatile unsigned long SR1;        /*!< I2C Status register 1,      Address offset: 0x14 */
	volatile unsigned long SR2;        /*!< I2C Status register 2,      Address offset: 0x18 */
	volatile unsigned long CCR;        /*!< I2C Clock control register, Address offset: 0x1C */
	volatile unsigned long TRISE;      /*!< I2C TRISE register,         Address offset: 0x20 */
	volatile unsigned long FLTR;       /*!< I2C FLTR register,          Address offset: 0x24 */
} I2C_TypeDef;

#define setMcuRccI2cFreq(addr, x)			setRegField(addr->CR2, 0x3FUL, x, 0)
#define setMcuRccI2cFreq(addr, x)			setRegField(addr->CR2, 0x3FUL, x, 0)
//#define 

#endif
