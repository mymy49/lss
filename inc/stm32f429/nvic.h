#ifndef STM32L_NVIC_H_
#define STM32L_NVIC_H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
	volatile unsigned long ISER[8];		// < Offset: 0x000 (R/W)  Interrupt Set Enable Register >
	unsigned long RESERVED0[24];
	volatile unsigned long ICER[8];		// < Offset: 0x080 (R/W)  Interrupt Clear Enable Register >
	unsigned long RSERVED1[24];
	volatile unsigned long ISPR[8];		// < Offset: 0x100 (R/W)  Interrupt Set Pending Register >
	unsigned long RESERVED2[24];
	volatile unsigned long ICPR[8];		// < Offset: 0x180 (R/W)  Interrupt Clear Pending Register >
	unsigned long RESERVED3[24];
	volatile unsigned long IABR[8];		// < Offset: 0x200 (R/W)  Interrupt Active bit Register >
	unsigned long RESERVED4[56];
	volatile unsigned char IP[240];			// < Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) >
	unsigned long RESERVED5[644];
	volatile  unsigned long STIR;		// < Offset: 0xE00 ( /W)  Software Trigger Interrupt Register >
}  NVIC_Type;


inline void setMcuNvicIntEn(unsigned char num)
{
	if(num < 32)
	{
		NVIC->ISER[0] = 1 << num;
	}
	else if(num < 64)
	{
		num -= 32;
		NVIC->ISER[1] = 1 << num;
	}
	else if(num < 96)
	{
		num -= 64;
		NVIC->ISER[2] = 1 << num;
	}
}

inline void clrMcuNvicIntEn(unsigned char num)
{
	if(num < 32)
	{
		NVIC->ICER[0] = 1 << num;
	}
	else if(num < 64)
	{
		num -= 32;
		NVIC->ICER[1] = 1 << num;
	}
	else if(num < 96)
	{
		num -= 64;
		NVIC->ICER[2] = 1 << num;
	}
}

#endif
	