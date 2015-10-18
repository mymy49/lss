#ifndef LSS_STDLIB_MALLOC_CLASS__H_
#define LSS_STDLIB_MALLOC_CLASS__H_

#define calculateSize(x)		(1 << x)

#define HEAP_MAX_MALLOC			11
#define HEAP_MAX_CLUSTER		9

struct MallocData
{
	void* addr;
	unsigned short block;
	unsigned short index;
	unsigned long head, tail;
};

class Malloc
{
	unsigned long mallocCnt;
	unsigned long *baseAddr;
	unsigned long *cluster;
	unsigned char memSize, clusterSize, mallocSize;
	MallocData *addrTable;
public:
	Malloc(unsigned long* memAddr, unsigned char memSize, unsigned long* clusterAddr, unsigned char clusterSize, MallocData *addrTableAddr, unsigned char mallocSize);

	void* malloc(unsigned long size);
	void free(void *addr);

	inline signed long findValidTable(void);
	inline void* getAddr(unsigned short &index, unsigned char &startBit);
    inline bool findStartCluster(unsigned long &size, signed long &table, unsigned char &bit);
	bool isValidCluster(unsigned long &size, signed long &table);
	void setCluster(signed long &table);
	void clrCluster(signed long &table);
};

#endif