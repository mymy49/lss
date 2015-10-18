#ifndef STM32F429_USART__H_
#define STM32F429_USART__H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
	volatile unsigned long SR;		// < USART Status register,                   Address offset: 0x00 
	volatile unsigned long DR;		// < USART Data register,                     Address offset: 0x04 
	volatile unsigned long BRR;		// < USART Baud rate register,                Address offset: 0x08 
	volatile unsigned long CR1;		// < USART Control register 1,                Address offset: 0x0C 
	volatile unsigned long CR2;		// < USART Control register 2,                Address offset: 0x10 
	volatile unsigned long CR3;		// < USART Control register 3,                Address offset: 0x14 
	volatile unsigned long GTPR;	// < USART Guard time and prescaler register, Address offset: 0x18 
} USART_TypeDef;

#define setMcuUsart1Brr(addr, man, fra)	setRegField(addr->BRR, 0xfff, man, 4); \
										setRegField(addr->BRR, 0xf, fra, 0)
#define setMcuUsartOver8(addr, x)		setRegBit(addr->CR1, 15, x)
#define setMcuUsartEn(addr, x)			setRegBit(addr->CR1, 13, x)
#define setMcuUsartTxEn(addr, x)		setRegBit(addr->CR1, 3, x)
#define setMcuUsartRxEn(addr, x)		setRegBit(addr->CR1, 2, x)
#define setMcuUsartDmaTxEn(addr, x)		setRegBit(addr->CR3, 7, x)
#define setMcuUsartDmaRxEn(addr, x)		setRegBit(addr->CR3, 6, x)
#define getMcuUsartTxEmpty(addr)		getRegBit(addr->SR, 7)

#endif
