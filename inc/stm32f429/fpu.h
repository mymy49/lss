#ifndef __H_
#define __H_

typedef struct
{
	unsigned long RESERVED0[1];
	volatile unsigned long FPCCR;	// < Offset: 0x004 (R/W)  Floating-Point Context Control Register
	volatile unsigned long FPCAR;	// < Offset: 0x008 (R/W)  Floating-Point Context Address Register
	volatile unsigned long FPDSCR;	// < Offset: 0x00C (R/W)  Floating-Point Default Status Control Register
	volatile unsigned long MVFR0;	// < Offset: 0x010 (R/ )  Media and FP Feature Register 0
	volatile unsigned long MVFR1;	// < Offset: 0x014 (R/ )  Media and FP Feature Register 1
} FPU_Type;

#define SCS_BASE	(0xE000E000UL)			// < System Control Space Base Address >
#define FPU_BASE	(SCS_BASE + 0x0F30UL)	// < Floating Point Unit >
#define FPU			((FPU_Type*)FPU_BASE)   // < Floating Point Unit >

inline setMcuFpu

#endif
