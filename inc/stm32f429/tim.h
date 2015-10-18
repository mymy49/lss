#ifndef STM32F429_TIM__H_
#define STM32F429_TIM__H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
	volatile unsigned long CR1;         // < TIM control register 1,              Address offset: 0x00
	volatile unsigned long CR2;         // < TIM control register 2,              Address offset: 0x04
	volatile unsigned long SMCR;        // < TIM slave mode control register,     Address offset: 
	volatile unsigned long DIER;        // < TIM DMA/interrupt enable register,   Address offset: 0x0C */
	volatile unsigned long SR;          // < TIM status register,                 Address offset: 0x10 */
	volatile unsigned long EGR;         // < TIM event generation register,       Address offset: 0x14 */
	volatile unsigned long CCMR1;       // < TIM capture/compare mode register 1, Address offset: 0x18 */
	volatile unsigned long CCMR2;       // < TIM capture/compare mode register 2, Address offset: 0x1C */
	volatile unsigned long CCER;        // < TIM capture/compare enable register, Address offset: 0x20 */
	volatile unsigned long CNT;         // < TIM counter register,                Address offset: 0x24 */
	volatile unsigned long PSC;         // < TIM prescaler,                       Address offset: 0x28 */
	volatile unsigned long ARR;         // < TIM auto-reload register,            Address offset: 0x2C */
	volatile unsigned long RCR;         // < TIM repetition counter register,     Address offset: 0x30 */
	volatile unsigned long CCR1;        // < TIM capture/compare register 1,      Address offset: 0x34 */
	volatile unsigned long CCR2;        // < TIM capture/compare register 2,      Address offset: 0x38 */
	volatile unsigned long CCR3;        // < TIM capture/compare register 3,      Address offset: 0x3C */
	volatile unsigned long CCR4;        // < TIM capture/compare register 4,      Address offset: 0x40 */
	volatile unsigned long BDTR;        // < TIM break and dead-time register,    Address offset: 0x44 */
	volatile unsigned long DCR;         // < TIM DMA control register,            Address offset: 0x48 */
	volatile unsigned long DMAR;        // < TIM DMA address for full transfer,   Address offset: 0x4C */
	volatile unsigned long OR;          // < TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;

#define setMcuTimEn(addr, x)	setRegBit(addr->CR1, x, 0)
#define setMcuTimDir(addr, x)	setRegBit(addr->CR1, x, 4)
#define setMcuTimArr(addr, x)	addr->ARR = (unsigned long)x
#define setMcuTimPsc(addr, x)	addr->PSC = (unsigned short)x
#define setMcuTimUie(addr, x)	setRegBit(addr->DIER, x, 0)
#define clrMcuTimUif(addr)		setRegBit(addr->SR, 0, 0)
#define getMcuTimCnt(addr)		(addr->CNT)
#define setMcuTimCnt(addr, x)	addr->CNT = (unsigned long)x

#endif
