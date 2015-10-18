#ifndef DEV_LCD__H_
#define DEV_LCD__H_

#include <stm32f429.h>

#define setDevLcdCs(en)		setMcuGpioOdr(GPIOC, 2, !en);
#define setDevLcdDcxCmd()	setMcuGpioOdr(GPIOD, 13, false);
#define setDevLcdDcxData()	setMcuGpioOdr(GPIOD, 13, true);

#endif
