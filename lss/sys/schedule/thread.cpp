#include <schedule.h>
#include <lssConfig.h>
#include <Mutex.h>
#include <malloc.h>

struct Task
{
	long* stack;
	long* sp;
	unsigned long size;
	bool able, mallocated;
};

void delThread(void);
void doSystemTask(void);

static unsigned short numOfThread = 1;
static unsigned short maxThread = LSS_MAX_THREAD;

static unsigned short threadCnt;
static Task task[LSS_MAX_THREAD];

static Mutex mutex(switchContext);

void initThread(void)
{
	task[0].able = true;
	task[0].mallocated = true;
    addThread(doSystemTask, 1024);
}

void doSystemTask(void)
{
	unsigned long i;

	while(1)
	{
		for(i=0;i<LSS_MAX_THREAD;i++)
		{
			if(task[i].mallocated && !task[i].able)
			{
				hfree(task[i].stack);
				task[i].mallocated = false;
			}
		}

        switchContext();
	}
}

signed long addThread(void (*func)(void), unsigned long size)
{
	mutex.lock();

	unsigned long i;
	
	if(numOfThread >= LSS_MAX_THREAD)
	{
		return -1;
	}

	for(i=1;i<LSS_MAX_THREAD;i++)
	{
		if(!task[i].able)
			break;
	}
	
	task[i].stack = (long*)hmalloc(size);
	if(!task[i].stack)
	{
		return -1;
	}

        size >>= 2;

	task[i].size = size;
	task[i].mallocated = true;
	task[i].able = true;
	task[i].stack[size-1] = 0x61000000;							// xPSR
	task[i].stack[size-2] = (long)func;							// PC
	task[i].stack[size-3] = (long)(void (*)(void))delThread;	// LR
	task[i].stack[size-4] = 12;
	task[i].stack[size-5] = 3;
    task[i].stack[size-6] = 2;
    task[i].stack[size-7] = 1;
    task[i].stack[size-8] = 0;
    task[i].stack[size-9] = 11;
    task[i].stack[size-10] = 10;
    task[i].stack[size-11] = 9;
    task[i].stack[size-12] = 8;
    task[i].stack[size-13] = 7;
    task[i].stack[size-14] = 6;
    task[i].stack[size-15] = 5;
    task[i].stack[size-16] = 4;

	task[i].sp = &(task[i].stack[size-32]);
	numOfThread++;

    mutex.unlock();

    return i;
}

void delThread(signed long num)
{
	mutex.lock();

	if(num != threadCnt && num > 0)
	{
		task[num].able = false;
		task[num].mallocated = false;
        hfree((void*)task[num].stack);
        task[num].stack = 0;
		task[num].sp = 0;
		task[num].size = 0;
		numOfThread--;
	}

     mutex.unlock();
}

void delThread(void)
{
	task[threadCnt].able = false;
	numOfThread--;
	switchContext();
}

extern "C"
{
	long* getNextContext(long* sp)
	{
		task[threadCnt++].sp = sp;
		while(!task[threadCnt].able)
		{
			threadCnt++;
			if(threadCnt >= maxThread)
			{
				threadCnt = 0;
			}
		}
		sp = task[threadCnt].sp;
		return sp;
	}
}
