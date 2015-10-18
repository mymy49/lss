#include <schedule.h>
#include <stm32f429.h>
#include <schedule.h>

static unsigned long runningDay = 0;

void initTime(void)
{
	unsigned long psc = (getMcuRccApb1Clk() << 1) / 1000;

	setMcuRccTim2En(true);	
	setMcuTimPsc(TIM2, (unsigned short)psc);
	setMcuTimArr(TIM2, 86400000);
	setMcuTimCnt(TIM2, 86400000);

	setMcuTimUie(TIM2, true);
	setMcuTimEn(TIM2, true);
	setMcuNvicIntEn(TIM2_IRQn);
}

extern "C"
{
	void TIM2_IRQHandler(void)
	{
		clrMcuTimUif(TIM2);
        runningDay++;
	}
}

unsigned long getLssClock(void)
{
	return getMcuTimCnt(TIM2);
}

void delay(unsigned long delayTime)
{
	unsigned long start = getLssClock();
	unsigned long end = start + delayTime;

	if(end < 86400000)
	{
		while(getLssClock() <= end)
		{
			switchContext();
		}
	}
	else
	{
		unsigned long today = runningDay;
		end -= 86400000;
		while(today != runningDay && getLssClock() <= end)
		{
			switchContext();
		}
	}
}