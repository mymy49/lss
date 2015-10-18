#ifndef STM32F429_FLASH__H_
#define STM32F429_FLASH__H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
	volatile unsigned long ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
	volatile unsigned long KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
	volatile unsigned long OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
	volatile unsigned long SR;       /*!< FLASH status register,           Address offset: 0x0C */
	volatile unsigned long CR;       /*!< FLASH control register,          Address offset: 0x10 */
	volatile unsigned long OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
	volatile unsigned long OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;

#define setMcuFlashLatency(x)		setRegField(FLASH->ACR, 0x7UL, x, 0)
#define setMcuFlashPrefetch(x)		setRegBit(FLASH->ACR, x, 8)
#define setMcuFlashDataCacheEn(x)	setRegBit(FLASH->ACR, x, 10)
#define setMcuFlashInstCacheEn(x)	setRegBit(FLASH->ACR, x, 9)

#endif
