#include <stdlib.h>
#include <stm32f429.h>
#include <Mutex.h>
#include <schedule.h>
#include "Malloc.h"

#define MEM_SIZE		23
#define CLUSTER_SIZE	10
#define MALLOC_SIZE		12

static unsigned long cluster[calculateSize(CLUSTER_SIZE)];
static MallocData mallocData[calculateSize(MALLOC_SIZE)];
static Malloc alloc((unsigned long*)0xd0000000, MEM_SIZE, (unsigned long*)cluster, CLUSTER_SIZE, (MallocData*)mallocData, MALLOC_SIZE);
static Mutex mutex(switchContext);

void lfree(void* addr)
{
	mutex.lock();
	alloc.free(addr);
    mutex.unlock();
}

void* lmalloc(unsigned long size)
{
	void *rt;

	mutex.lock();
	rt = alloc.malloc(size);
	mutex.unlock();

	return rt;
}

