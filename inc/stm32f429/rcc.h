#ifndef STM32F429_RCC__H_
#define STM32F429_RCC__H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
	volatile unsigned long CR;            //!< RCC clock control register,                                  Address offset: 0x00  
	volatile unsigned long PLLCFGR;       //!< RCC PLL configuration register,                              Address offset: 0x04  
	volatile unsigned long CFGR;          //!< RCC clock configuration register,                            Address offset: 0x08  
	volatile unsigned long CIR;           //!< RCC clock interrupt register,                                Address offset: 0x0C  
	volatile unsigned long AHB1RSTR;      //!< RCC AHB1 peripheral reset register,                          Address offset: 0x10  
	volatile unsigned long AHB2RSTR;      //!< RCC AHB2 peripheral reset register,                          Address offset: 0x14  
	volatile unsigned long AHB3RSTR;      //!< RCC AHB3 peripheral reset register,                          Address offset: 0x18  
	unsigned long      RESERVED0;     //!< Reserved, 0x1C                                                                     
	volatile unsigned long APB1RSTR;      //!< RCC APB1 peripheral reset register,                          Address offset: 0x20  
	volatile unsigned long APB2RSTR;      //!< RCC APB2 peripheral reset register,                          Address offset: 0x24  
	unsigned long      RESERVED1[2];  //!< Reserved, 0x28-0x2C                                                                
	volatile unsigned long AHB1ENR;       //!< RCC AHB1 peripheral clock register,                          Address offset: 0x30  
	volatile unsigned long AHB2ENR;       //!< RCC AHB2 peripheral clock register,                          Address offset: 0x34  
	volatile unsigned long AHB3ENR;       //!< RCC AHB3 peripheral clock register,                          Address offset: 0x38  
	unsigned long      RESERVED2;     //!< Reserved, 0x3C                                                                     
	volatile unsigned long APB1ENR;       //!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40  
	volatile unsigned long APB2ENR;       //!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44  
	unsigned long      RESERVED3[2];  //!< Reserved, 0x48-0x4C                                                                
	volatile unsigned long AHB1LPENR;     //!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50  
	volatile unsigned long AHB2LPENR;     //!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54  
	volatile unsigned long AHB3LPENR;     //!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58  
	unsigned long      RESERVED4;     //!< Reserved, 0x5C                                                                     
	volatile unsigned long APB1LPENR;     //!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60  
	volatile unsigned long APB2LPENR;     //!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64  
	unsigned long      RESERVED5[2];  //!< Reserved, 0x68-0x6C                                                                
	volatile unsigned long BDCR;          //!< RCC Backup domain control register,                          Address offset: 0x70  
	volatile unsigned long CSR;           //!< RCC clock control & status register,                         Address offset: 0x74  
	unsigned long      RESERVED6[2];  //!< Reserved, 0x78-0x7C                                                                
	volatile unsigned long SSCGR;         //!< RCC spread spectrum clock generation register,               Address offset: 0x80  
	volatile unsigned long PLLI2SCFGR;    //!< RCC PLLI2S configuration register,                           Address offset: 0x84  
	volatile unsigned long PLLSAICFGR;    //!< RCC PLLSAI configuration register,                           Address offset: 0x88  
	volatile unsigned long DCKCFGR;       //!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C  
	volatile unsigned long CKGATENR;      //!< RCC Clocks Gated Enable Register,                            Address offset: 0x90   // Only for STM32F446xx devices  
	volatile unsigned long DCKCFGR2;      //!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94   // Only for STM32F446xx devices  

} RCC_TypeDef;

#define RCC_SW_HSI				0
#define RCC_SW_HSE				1
#define RCC_SW_PLL				2

#define RCC_AHB_NO_DIV			0
#define RCC_AHB_DIV_2			4
#define RCC_AHB_DIV_4			5
#define RCC_AHB_DIV_8			6
#define RCC_AHB_DIV_16			7

#define RCC_APB_NO_DIV			0
#define RCC_APB_DIV_2			4
#define RCC_APB_DIV_4			5
#define RCC_APB_DIV_8			6
#define RCC_APB_DIV_16			7

#define setMcuRccHseEn(x)			setRegBit(RCC->CR, x, 16)
#define waitMcuRccHseRdy()			while(!getRegBit(RCC->CR, 17));
#define setMcuRccMainPllOn(x)		setRegBit(RCC->CR, x, 24)
#define waitMcuRccMainPllRdy()		while(!getRegBit(RCC->CR, 25));
#define setMcuRccSaiPllOn(x)		setRegBit(RCC->CR, x, 28)
#define waitMcuRccSaiPllRdy()		while(!getRegBit(RCC->CR, 29));

#define setMcuRccMainPllm(x)		setRegField(RCC->PLLCFGR, 0x3FUL, x, 0)
#define setMcuRccMainPlln(x)		setRegField(RCC->PLLCFGR, 0x1FFUL, x, 6)
#define setMcuRccMainPllp(x)		setRegField(RCC->PLLCFGR, 0x3UL, x, 16)
#define setMcuRccMainPllSrc(x)		setRegBit(RCC->PLLCFGR, x, 22)
#define setMcuRccMainPllq(x)		setRegField(RCC->PLLCFGR, 0xFUL, x, 24)

#define setMcuRccSysclkSw(x)		setRegField(RCC->CFGR, 0x3UL, x, 0)
#define	getMcuRccSysclkSw()			getRegField(RCC->CFGR, 0x3UL, 2);
#define setMcuRccHpre(x)			setRegField(RCC->CFGR, 0xFUL, x, 4)
#define getMcuRccHpre()				getRegField(RCC->CFGR, 0xFUL, 4)
#define setMcuRccPpre2(x)			setRegField(RCC->CFGR, 0x7UL, x, 13)
#define setMcuRccPpre1(x)			setRegField(RCC->CFGR, 0x7UL, x, 10)
#define getMcuRccPpre2()			getRegField(RCC->CFGR, 0x7UL, 13)
#define getMcuRccPpre1()			getRegField(RCC->CFGR, 0x7UL, 10)

#define setMcuRccGpioAEn(x)			setRegBit(RCC->AHB1ENR, x, 0)
#define setMcuRccGpioBEn(x)			setRegBit(RCC->AHB1ENR, x, 1)
#define setMcuRccGpioCEn(x)			setRegBit(RCC->AHB1ENR, x, 2)
#define setMcuRccGpioDEn(x)			setRegBit(RCC->AHB1ENR, x, 3)
#define setMcuRccGpioEEn(x)			setRegBit(RCC->AHB1ENR, x, 4)
#define setMcuRccGpioFEn(x)			setRegBit(RCC->AHB1ENR, x, 5)
#define setMcuRccGpioGEn(x)			setRegBit(RCC->AHB1ENR, x, 6)
#define setMcuRccGpioHEn(x)			setRegBit(RCC->AHB1ENR, x, 7)
#define setMcuRccGpioIEn(x)			setRegBit(RCC->AHB1ENR, x, 8)
#define setMcuRccGpioJEn(x)			setRegBit(RCC->AHB1ENR, x, 9)
#define setMcuRccGpioKEn(x)			setRegBit(RCC->AHB1ENR, x, 10)
#define setMcuRccDma2dEn(x)			setRegBit(RCC->AHB1ENR, x, 23)

#define setMcuRccFmcEn(x)			setRegBit(RCC->AHB3ENR, x, 0)

#define setMcuRccTim2En(x)			setRegBit(RCC->APB1ENR, x, 0)
#define setMcuRccI2c3En(x)			setRegBit(RCC->APB1ENR, x, 23)

#define setMcuRccSpi5En(x)			setRegBit(RCC->APB2ENR, x, 20)
#define setMcuRccLtdcEn(x)			setRegBit(RCC->APB2ENR, x, 26)

#define setMcuRccSaiPlln(x)			setRegField(RCC->PLLSAICFGR, 0x1FFUL, x, 6)
#define setMcuRccSaiPllq(x)			setRegField(RCC->PLLSAICFGR, 0xFUL, x, 24)
#define setMcuRccSaiPllr(x)			setRegField(RCC->PLLSAICFGR, 0x7UL, x, 28)

#define setMcuRccSaiDivr(x)			setRegField(RCC->DCKCFGR, 0x3UL, x, 16)


inline unsigned long getMcuRccApb1Clk(void)
{
	unsigned char sw = getMcuRccSysclkSw();
	const unsigned char ppre[8] = {0, 0, 0, 0, 1, 2, 3, 4};
	const unsigned char hpre[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8}; 
	unsigned long clk = 0;

	switch(sw)
	{
	case 0 : // HSI
		clk = 16000000;
		break;
	case 1 : // HSE
		clk = 0;
		break;
	case 2 : // PLL
		clk = 168000000;
		break;
	}
	
	clk >>= hpre[getMcuRccHpre()];
	clk >>= ppre[getMcuRccPpre1()];

	return clk;
}

inline unsigned long getMcuRccApb2Clk(void)
{
	unsigned char sw = getMcuRccSysclkSw();
   	const unsigned char ppre[8] = {0, 0, 0, 0, 1, 2, 3, 4};
	const unsigned char hpre[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8}; 
	unsigned long clk;

	switch(sw)
	{
	case 0 : // HSI
		clk = 16000000;
		break;
	case 1 : // HSE
		clk = 0;
		break;
	case 2 : // PLL
		clk = 0;
		break;
	}
	
   	clk >>= hpre[getMcuRccHpre()];
	clk >>= ppre[getMcuRccPpre2()];

	return clk;
}

#endif
