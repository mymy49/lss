#include <stm32f429.h>
#include <time.h>
#include <schedule.h>

static void wait(void)
{
	switchContext();
}

extern "C"
{
	void initLss(void)
	{
		initThread();
		initTime();
        initMcuDma2d();
		setMcuDma2dWaitFunc(wait);
		setMcuSystickLoad(42000);
		startMcuSystick();
	}
}
