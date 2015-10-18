#include <svc.h>
#include <stm32f429.h>

extern "C"
{
	void SysTick_Handler(void);
}

void switchContext(void)
{
	SysTick->VAL = SysTick->LOAD;
	callSvc((void (*)(void*))SysTick_Handler, (void*)0);
}

