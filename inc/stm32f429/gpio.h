#ifndef STM32F429_GPIO__H_
#define STM32F429_GPIO__H_

#include "peripheral.h"
#include "reg.h"

typedef struct
{
  volatile unsigned long MODER;    //!< GPIO port mode register,               Address offset: 0x00       
  volatile unsigned long OTYPER;   //!< GPIO port output type register,        Address offset: 0x04       
  volatile unsigned long OSPEEDR;  //!< GPIO port output speed register,       Address offset: 0x08       
  volatile unsigned long PUPDR;    //!< GPIO port pull-up/pull-down register,  Address offset: 0x0C       
  volatile unsigned long IDR;      //!< GPIO port input data register,         Address offset: 0x10       
  volatile unsigned long ODR;      //!< GPIO port output data register,        Address offset: 0x14       
  volatile unsigned short BSRRL;    //!< GPIO port bit set/reset low register,  Address offset: 0x18       
  volatile unsigned short BSRRH;    //!< GPIO port bit set/reset high register, Address offset: 0x1A       
  volatile unsigned long LCKR;     //!< GPIO port configuration lock register, Address offset: 0x1C       
  volatile unsigned long AFR[2];   //!< GPIO alternate function registers,     Address offset: 0x20-0x24  
} GPIO_TypeDef;

#define GPIO_MODER_INPUT		0
#define GPIO_MODER_OUTPUT		1
#define GPIO_MODER_ALT_FUNC		2
#define GPIO_MODER_ANALOG		3

#define GPIO_AFR_SYS_AF0		0
#define GPIO_AFR_TIM1			1
#define GPIO_AFR_TIM2			1
#define GPIO_AFR_TIM3			2
#define GPIO_AFR_TIM4			2
#define GPIO_AFR_TIM5			2
#define GPIO_AFR_TIM8			3
#define GPIO_AFR_TIM9			3
#define GPIO_AFR_TIM10			3
#define GPIO_AFR_TIM11			3
#define GPIO_AFR_I2C1			4
#define GPIO_AFR_I2C2			4
#define GPIO_AFR_I2C3			4
#define GPIO_AFR_SPI_AF5		5
#define GPIO_AFR_SPI_AF6		6
#define GPIO_AFR_SPI_AF7		7
#define GPIO_AFR_USART1			7
#define GPIO_AFR_USART2			7
#define GPIO_AFR_USART3			7
#define GPIO_AFR_USART6			8
#define GPIO_AFR_UART4			8
#define GPIO_AFR_UART5			8
#define GPIO_AFR_UART7			8
#define GPIO_AFR_UART8			8
#define GPIO_AFR_CAN1			9
#define GPIO_AFR_CAN2			9
#define GPIO_AFR_TIM12			9
#define GPIO_AFR_TIM13			9
#define GPIO_AFR_TIM14			9
#define GPIO_AFR_LCD_AF9		9
#define GPIO_AFR_OTG2_HS		10
#define GPIO_AFR_OTG1_FS		10
#define GPIO_AFR_ETH			11
#define GPIO_AFR_FMC			12
#define GPIO_AFR_SDRAM			12
#define GPIO_AFR_SDIO			12
#define GPIO_AFR_OTG2_FS		12
#define GPIO_AFR_DCMI			13
#define GPIO_AFR_LCD_AF14		14
#define GPIO_AFR_SYS_AF15		15

#define GPIO_SPEED_LOW			0x0
#define GPIO_SPEED_MID			0x1
#define GPIO_SPEED_FAST			0x2
#define GPIO_SPEED_HIGH			0x3

inline void setMcuGpioMode(GPIO_TypeDef *port, unsigned char pin, unsigned char mode)
{
	if(pin < 16)
	{
		pin <<= 1;
		setRegField(port->MODER, 0x3UL, mode, pin);
	}
}

inline void setMcuGpioAltfunc(GPIO_TypeDef *port, unsigned char pin, unsigned char func)
{
	if(pin < 8)
	{
		pin <<= 2;
		setRegField(port->AFR[0], 0xFUL, func, pin);
	}
	else if(pin < 16)
	{
		pin -= 8;
		pin <<= 2;
		setRegField(port->AFR[1], 0xFUL, func, pin);
	}
}

inline void setMcuGpioOdr(GPIO_TypeDef *port, unsigned char pin, bool on)
{
	if(pin < 16)
	{
		setRegBit(port->ODR, on, pin);
	}
}

inline void setMcuGpioOspeed(GPIO_TypeDef *port, unsigned char pin, unsigned char val)
{
	if(pin < 16)
	{
		pin <<= 1;
		setRegField(port->OSPEEDR, 0x3UL, val, pin);
	}
}

#endif
