#include <stdlib.h>
#include <stm32f429.h>
#include <Mutex.h>
#include <schedule.h>
#include "Malloc.h"

#define MEM_SIZE		16
#define CLUSTER_SIZE	6
#define MALLOC_SIZE		9

static unsigned long cluster[calculateSize(CLUSTER_SIZE)];
static MallocData mallocData[calculateSize(MALLOC_SIZE)];
static Malloc alloc((unsigned long*)0x10000000, MEM_SIZE, (unsigned long*)cluster, CLUSTER_SIZE, (MallocData*)mallocData, MALLOC_SIZE);
static Mutex mutex(switchContext);

void hfree(void* addr)
{
	mutex.lock();
	alloc.free(addr);
    mutex.unlock();
}

void* hmalloc(unsigned long size)
{
	void *rt;

	mutex.lock();
	rt = alloc.malloc(size);
	mutex.unlock();

	return rt;
}

void* operator new[] (unsigned int size)
{
	return hmalloc(size);
}

void* operator new (unsigned int size)
{
	return hmalloc(size);
}

void operator delete (void *pt)
{
	hfree(pt);
}
