#ifndef STM32F429_LTDC__H_
#define STM32F429_LTDC__H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
	volatile unsigned long RESERVED0[2];  /*!< Reserved, 0x00-0x04 */
	volatile unsigned long SSCR;          /*!< LTDC Synchronization Size Configuration Register,    Address offset: 0x08 */
	volatile unsigned long BPCR;          /*!< LTDC Back Porch Configuration Register,              Address offset: 0x0C */
	volatile unsigned long AWCR;          /*!< LTDC Active Width Configuration Register,            Address offset: 0x10 */
	volatile unsigned long TWCR;          /*!< LTDC Total Width Configuration Register,             Address offset: 0x14 */
	volatile unsigned long GCR;           /*!< LTDC Global Control Register,                        Address offset: 0x18 */
	volatile unsigned long RESERVED1[2];  /*!< Reserved, 0x1C-0x20 */
	volatile unsigned long SRCR;          /*!< LTDC Shadow Reload Configuration Register,           Address offset: 0x24 */
	volatile unsigned long RESERVED2[1];  /*!< Reserved, 0x28 */
	volatile unsigned long BCCR;          /*!< LTDC Background Color Configuration Register,        Address offset: 0x2C */
	volatile unsigned long RESERVED3[1];  /*!< Reserved, 0x30 */
	volatile unsigned long IER;           /*!< LTDC Interrupt Enable Register,                      Address offset: 0x34 */
	volatile unsigned long ISR;           /*!< LTDC Interrupt Status Register,                      Address offset: 0x38 */
	volatile unsigned long ICR;           /*!< LTDC Interrupt Clear Register,                       Address offset: 0x3C */
	volatile unsigned long LIPCR;         /*!< LTDC Line Interrupt Position Configuration Register, Address offset: 0x40 */
	volatile unsigned long CPSR;          /*!< LTDC Current Position Status Register,               Address offset: 0x44 */
	volatile unsigned long CDSR;          /*!< LTDC Current Display Status Register,                       Address offset: 0x48 */
} LTDC_TypeDef;  

typedef struct
{  
	volatile unsigned long CR;				// LTDC Layerx Control Register                                  Address offset: 0x84
	volatile unsigned long WHPCR;			// LTDC Layerx Window Horizontal Position Configuration Register Address offset: 0x88
	volatile unsigned long WVPCR;			// LTDC Layerx Window Vertical Position Configuration Register   Address offset: 0x8C
	volatile unsigned long CKCR;			// LTDC Layerx Color Keying Configuration Register               Address offset: 0x90
	volatile unsigned long PFCR;			// LTDC Layerx Pixel Format Configuration Register               Address offset: 0x94
	volatile unsigned long CACR;			// LTDC Layerx Constant Alpha Configuration Register             Address offset: 0x98
	volatile unsigned long DCCR;			// LTDC Layerx Default Color Configuration Register              Address offset: 0x9C
	volatile unsigned long BFCR;			// LTDC Layerx Blending Factors Configuration Register           Address offset: 0xA0
	volatile unsigned long RESERVED0[2];	// Reserved */
	volatile unsigned long CFBAR;			// LTDC Layerx Color Frame Buffer Address Register               Address offset: 0xAC
	volatile unsigned long CFBLR;			// LTDC Layerx Color Frame Buffer Length Register                Address offset: 0xB0 
	volatile unsigned long CFBLNR;			// LTDC Layerx ColorFrame Buffer Line Number Register            Address offset: 0xB4 
	volatile unsigned long RESERVED1[3];	// Reserved
	volatile unsigned long CLUTWR;			// LTDC Layerx CLUT Write Register                               Address offset: 0x144
} LTDC_Layer_TypeDef;

#define setMcuLtdcHsw(x)			setRegField(LTDC->SSCR, 0xFFFUL, x, 16)
#define setMcuLtdcVsh(x)			setRegField(LTDC->SSCR, 0x7FFUL, x, 0)
#define setMcuLtdcAhbp(x)			setRegField(LTDC->BPCR, 0xFFFUL, x, 16)
#define setMcuLtdcAvbp(x)			setRegField(LTDC->BPCR, 0x7FFUL, x, 0)
#define setMcuLtdcAaw(x)			setRegField(LTDC->AWCR, 0xFFFUL, x, 16)
#define setMcuLtdcAah(x)			setRegField(LTDC->AWCR, 0x7FFUL, x, 0)
#define setMcuLtdcTotalw(x)			setRegField(LTDC->TWCR, 0xFFFUL, x, 16)
#define setMcuLtdcTotalh(x)			setRegField(LTDC->TWCR, 0x7FFUL, x, 0)
#define setMcuLtdcImediateReload()	setRegBit(LTDC->SRCR, 1, 0)
#define setMcuLtdcDitherEn(x)		setRegBit(LTDC->GCR, x, 16)
#define setMcuLtdcEn(x)				setRegBit(LTDC->GCR, x, 0)

#define setMcuLtdcHspol(x)		setRegBit(LTDC->GCR, x, 31)
#define setMcuLtdcVspol(x)		setRegBit(LTDC->GCR, x, 30)
#define setMcuLtdcDepol(x)		setRegBit(LTDC->GCR, x, 29)
#define setMcuLtdcPcpol(x)		setRegBit(LTDC->GCR, x, 28)
#define setMcuLtdcDen(x)		setRegBit(LTDC->GCR, x, 16)
#define setMcuLtdcEn(x)			setRegBit(LTDC->GCR, x, 0)

#define setMcuLtdcBcRed(x)		setRegField(LTDC->BCCR, 0xFFUL, x, 16)
#define setMcuLtdcBcGreen(x)	setRegField(LTDC->BCCR, 0xFFUL, x, 8)
#define setMcuLtdcBcBlue(x)		setRegField(LTDC->BCCR, 0xFFUL, x, 0)

#define getMcuLtdcLif()			getRegBit(LTDC->ISR, 0)
#define getMcuLtdcFuif()		getRegBit(LTDC->ISR, 1)
#define getMcuLtdcTerrif()		getRegBit(LTDC->ISR, 2)
#define getMcuLtdcRrif()		getRegBit(LTDC->ISR, 3)

#define setMcuLtdcLie(x)		setRegBit(LTDC->IER, x, 0)
#define setMcuLtdcClif()		setRegBit(LTDC->ICR, 1, 0)

#define setMcuLtdcLipos(x)		setRegField(LTDC->LIPCR, 0x7FFUL, x, 0)

#define LTDC_PIXEL_FORMAT_ARGB8888		0
#define LTDC_PIXEL_FORMAT_RGB888		1
#define LTDC_PIXEL_FORMAT_RGB565		2
#define LTDC_PIXEL_FORMAT_ARGB1555		3
#define LTDC_PIXEL_FORMAT_ARGB4444		4
#define LTDC_PIXEL_FORMAT_L8			5
#define LTDC_PIXEL_FORMAT_AL44			6
#define LTDC_PIXEL_FORMAT_AL88			7

#define setMcuLtdcLayerPixelFormat(addr, x)				setRegField(addr->PFCR, 0x7UL, x, 0)
#define setMcuLtdcLayerConstAlpha(addr, x)				setRegField(addr->CACR, 0xFFUL, x, 0)
#define setMcuLtdcLayerFrameBuffer(addr, x)				addr->CFBAR = x;
#define setMcuLtdcLayerFrameBufferLineNumber(addr, x)	addr->CFBLNR = (x & 0x7FFUL);
#define setMcuLtdcLayerEn(addr, x)						setRegBit(addr->CR, x, 0)

inline void setMcuLtdcLayerWhpcr(LTDC_Layer_TypeDef *addr, unsigned short start, unsigned short stop)
{
	unsigned long buf = (unsigned long)((stop & 0xfff) << 16) | (start & 0xfff);
	addr->WHPCR = buf;
}

inline void setMcuLtdcLayerWvpcr(LTDC_Layer_TypeDef *addr, unsigned short start, unsigned short stop)
{
	unsigned long buf = (unsigned long)((stop & 0x7ff) << 16) | (start & 0x7ff);
	addr->WVPCR = buf;
}

inline void setMcuLtdcLayerDccr(LTDC_Layer_TypeDef *addr, unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned long buf = (unsigned long)((alpha & 0xff) << 24) | ((red & 0xff) << 16) | ((green & 0xff) << 8) | (blue & 0xff);
	addr->DCCR = buf;
}

inline void setMcuLtdcLayerBfcr(LTDC_Layer_TypeDef *addr, unsigned char bf1, unsigned char bf2)
{
	unsigned long buf = (unsigned long)((bf1 & 0x7) << 8) | (bf2 & 0x7);
	addr->BFCR = buf;
}

inline void setMcuLtdcLayerCfblr(LTDC_Layer_TypeDef *addr, unsigned short cfbp, unsigned short cfbll)
{
	unsigned long buf = (unsigned long)((cfbp & 0x1fff) << 16) | (cfbll & 0x1fff);
	addr->CFBLR = buf;
}

#endif