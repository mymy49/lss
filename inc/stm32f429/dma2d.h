#ifndef STM32F429_DMA2D__H_
#define STM32F429_DMA2D__H_

#include "peripheral.h"
#include "reg.h"


/** 
  * @brief DMA2D Controller
  */

typedef struct
{
	volatile unsigned long CR;            /*!< DMA2D Control Register,                         Address offset: 0x00 */
	volatile unsigned long ISR;           /*!< DMA2D Interrupt Status Register,                Address offset: 0x04 */
	volatile unsigned long IFCR;          /*!< DMA2D Interrupt Flag Clear Register,            Address offset: 0x08 */
	volatile unsigned long FGMAR;         /*!< DMA2D Foreground Memory Address Register,       Address offset: 0x0C */
	volatile unsigned long FGOR;          /*!< DMA2D Foreground Offset Register,               Address offset: 0x10 */
	volatile unsigned long BGMAR;         /*!< DMA2D Background Memory Address Register,       Address offset: 0x14 */
	volatile unsigned long BGOR;          /*!< DMA2D Background Offset Register,               Address offset: 0x18 */
	volatile unsigned long FGPFCCR;       /*!< DMA2D Foreground PFC Control Register,          Address offset: 0x1C */
	volatile unsigned long FGCOLR;        /*!< DMA2D Foreground Color Register,                Address offset: 0x20 */
	volatile unsigned long BGPFCCR;       /*!< DMA2D Background PFC Control Register,          Address offset: 0x24 */
	volatile unsigned long BGCOLR;        /*!< DMA2D Background Color Register,                Address offset: 0x28 */
	volatile unsigned long FGCMAR;        /*!< DMA2D Foreground CLUT Memory Address Register,  Address offset: 0x2C */
	volatile unsigned long BGCMAR;        /*!< DMA2D Background CLUT Memory Address Register,  Address offset: 0x30 */
	volatile unsigned long OPFCCR;        /*!< DMA2D Output PFC Control Register,              Address offset: 0x34 */
	volatile unsigned long OCOLR;         /*!< DMA2D Output Color Register,                    Address offset: 0x38 */
	volatile unsigned long OMAR;          /*!< DMA2D Output Memory Address Register,           Address offset: 0x3C */
	volatile unsigned long OOR;           /*!< DMA2D Output Offset Register,                   Address offset: 0x40 */
	volatile unsigned long NLR;           /*!< DMA2D Number of Line Register,                  Address offset: 0x44 */
	volatile unsigned long LWR;           /*!< DMA2D Line Watermark Register,                  Address offset: 0x48 */
	volatile unsigned long AMTCR;         /*!< DMA2D AHB Master Timer Configuration Register,  Address offset: 0x4C */
	volatile unsigned long RESERVED[236]; /*!< Reserved, 0x50-0x3FF */
	volatile unsigned long FGCLUT[256];   /*!< DMA2D Foreground CLUT,                          Address offset:400-7FF */
	volatile unsigned long BGCLUT[256];   /*!< DMA2D Background CLUT,                          Address offset:800-BFF */
} DMA2D_TypeDef;

#define DMA2D_COLOR_MODE_ARGB8888	0
#define DMA2D_COLOR_MODE_RBG888		1
#define DMA2D_COLOR_MODE_RGB565		2
#define DMA2D_COLOR_MODE_ARGB1555	3
#define DMA2D_COLOR_MODE_ARGB4444	4
#define DMA2D_COLOR_MODE_L8			5
#define DMA2D_COLOR_MODE_AL44		6
#define DMA2D_COLOR_MODE_AL88		7
#define DMA2D_COLOR_MODE_L4			8
#define DMA2D_COLOR_MODE_A8			9
#define DMA2D_COLOR_MODE_A4			10


#define setMcuDma2dFgmar(x)						DMA2D->FGMAR = (unsigned long)x;
#define setMcuDma2dFgAlpha(x)					setRegField(DMA2D->FGPFCCR, 0xFFUL, x, 24)
#define setMcuDma2dFgAlphaMode(x)				setRegField(DMA2D->FGPFCCR, 0x3UL, x, 16)
#define setMcuDma2dFgColorMode(x)				setRegField(DMA2D->FGPFCCR, 0x7UL, x, 0)
#define setMcuDma2dFgLineOffset(x)				setRegField(DMA2D->FGOR, 0x3FFFUL, x, 0)

#define setMcuDma2dBgmar(x)						DMA2D->BGMAR = (unsigned long)x;
#define setMcuDma2dBgColorMode(x)				setRegField(DMA2D->BGPFCCR, 0x7UL, x, 0)
#define setMcuDma2dBgLineOffset(x)				setRegField(DMA2D->BGOR, 0x3FFFUL, x, 0)

#define setMcuDma2dOmar(x)						DMA2D->OMAR = (unsigned long)x;
#define setMcuDma2dOutputColorMode(x)			setRegField(DMA2D->OPFCCR, 0x7UL, x, 0)
#define setMcuDma2dOutputColor(x)				DMA2D->OCOLR = (unsigned long)x
#define setMcuDma2dOutputColorRgb565(r, g, b)	setRegField3(DMA2D->OCOLR, 0x1f, r, 11, 0x3f, g, 5, 0x1f, b, 0)

#define setMcuDma2dNumOfLine(x)					setRegField(DMA2D->NLR, 0xFFFFUL, x, 0)
#define setMcuDma2dNumOfPixel(x)				setRegField(DMA2D->NLR, 0x3FFFUL, x, 16)
#define setMcuDma2dOutputLineOffset(x)			setRegField(DMA2D->OOR, 0x3FFFUL, x, 0)

#define setMcuDma2dStart()						setRegBit(DMA2D->CR, 1, 0)

#define DMA2D_MODE_MEM_TO_MEM					0
#define DMA2D_MODE_MEM_TO_MEM_PFC				1
#define DMA2D_MODE_MEM_TO_MEM_BLENDING			2
#define DMA2D_MODE_REG_TO_MEM					3
#define setMcuDma2dMode(x)						setRegField(DMA2D->CR, 0x3UL, x, 16)

#define setMcuDma2dTcie(x)						setRegBit(DMA2D->CR, x, 9)
#define getMcuDma2dTcif()						getRegBit(DMA2D->ISR, 1)
#define clrMcuDma2dTcif()						setRegBit(DMA2D->IFCR, 1, 1)

void initMcuDma2d(void);
void setMcuDma2dFill(unsigned short** addr, unsigned short width, unsigned short height, unsigned short color);
void setMcuDma2dCopy(unsigned short** srcBf, unsigned short srcWidth, unsigned short srcHeight, unsigned short** desBf, unsigned short desWidth, unsigned short desHeight, unsigned short desX, unsigned short desY);
void setMcuDma2dCopy(unsigned short** srcBf, unsigned short srcWidth, unsigned short srcHeight, unsigned short** desBf, unsigned short desWidth, unsigned short desHeight, unsigned short desX, unsigned short desY, unsigned char alpha);
void setMcuDma2dWaitFunc(void (*func)(void));

//setRegField(RCC->PLLCFGR, 0x3FUL, x, 0)


#endif
