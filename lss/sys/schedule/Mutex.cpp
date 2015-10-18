#include <Mutex.h>

Mutex::Mutex(void (*func)(void))
{
	usingFlag = false;
    switchContext = func;
}

void Mutex::lock(void)
{
	while(usingFlag)
	{
		switchContext();
	}

    usingFlag = true;
}

void Mutex::unlock(void)
{
	usingFlag = false;
}
