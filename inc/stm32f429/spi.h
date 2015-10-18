#ifndef STM32F429_SPI__H_
#define STM32F429_SPI__H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
	volatile unsigned long CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	volatile unsigned long CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */
	volatile unsigned long SR;         /*!< SPI status register,                                Address offset: 0x08 */
	volatile unsigned long DR;         /*!< SPI data register,                                  Address offset: 0x0C */
	volatile unsigned long CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	volatile unsigned long RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	volatile unsigned long TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	volatile unsigned long I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
	volatile unsigned long I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_TypeDef;

#define setMcuSpiBaudrate(addr, x)		setRegField(addr->CR1, 0x7, x, 3)
#define setMcuSPiMode(addr, x)			setRegField(addr->CR1, 0x3, x, 0)
#define setMcuSpiDff(addr, x)			setRegBit(addr->CR1, x, 11)
#define setMcuSpiLsbfirst(addr)			setRegBit(addr->CR1, 1, 7)
#define setMcuSpiMsbfirst(addr)			setRegBit(addr->CR1, 0, 7)
#define setMcuSpiEnable(addr, x)		setRegBit(addr->CR1, x, 6)
#define setMcuSpiSsm(addr, x)			setRegBit(addr->CR1, x, 9)
#define setMcuSpiSsi(addr, x)			setRegBit(addr->CR1, x, 8)
#define setMcuSpiMstr(addr, x)			setRegBit(addr->CR1, x, 2)
#define setMcuSpiTxeie(addr, x)			setRegBit(addr->CR2, x, 7)
#define setMcuSpiRxneie(addr, x)		setRegBit(addr->CR2, x, 6)
#define setMcuSpiDmaTxEn(addr, x)		setRegBit(addr->CR2, x, 1)
#define setMcuSpiDr(addr, x)			addr->DR = (unsigned char)x
#define getMcuSpiDr(addr)				(unsigned char)addr->DR

#define getMcuSpiBusy(addr)				getRegBit(addr->SR, 7)
#define getMcuSpiTxe(addr)				getRegBit(addr->SR, 1)
#define getMcuSpiRxne(addr)				getRegBit(addr->SR, 0)
#define isMcuSpiExchOk(addr)			((addr->SR & 0x3) == 0x3)

#define MCU_SPI_BAUDRATE_2		0
#define MCU_SPI_BAUDRATE_4		1
#define MCU_SPI_BAUDRATE_8		2
#define MCU_SPI_BAUDRATE_16		3
#define MCU_SPI_BAUDRATE_32		4
#define MCU_SPI_BAUDRATE_64		5
#define MCU_SPI_BAUDRATE_128	6
#define MCU_SPI_BAUDRATE_256	7

inline unsigned char exchMcuSpi(SPI_TypeDef* addr, unsigned char data)
{
	while(!getMcuSpiTxe(addr));
	setMcuSpiDr(addr, data);
	while(!getMcuSpiRxne(addr));
    return getMcuSpiDr(addr);
}

#endif
