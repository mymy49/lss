#include "Malloc.h"

Malloc::Malloc(unsigned long* memAddr, unsigned char memSize, unsigned long* clusterAddr, unsigned char clusterSize, MallocData *addrTableAddr, unsigned char mallocSize)
{
	mallocCnt = 0;

	baseAddr = memAddr;
	this->memSize = memSize;

    cluster = clusterAddr;
	this->clusterSize = clusterSize;

	addrTable = addrTableAddr;
    this->mallocSize = mallocSize;

	for(unsigned short i=0;i<calculateSize(mallocSize);i++)
		addrTable[i].addr = 0;
}

inline signed long Malloc::findValidTable(void)
{
	signed long i;
	signed long loop = calculateSize(mallocSize);

	for(i=0;i<loop;i++)
	{
		if(!addrTable[i].addr)
		{
			return i;
		}
	}
	return -1;
}

inline void* Malloc::getAddr(unsigned short &index, unsigned char &startBit)
{
	unsigned long cIndex = ((unsigned long)index << 5) + (unsigned long)startBit;
	cIndex <<= memSize - clusterSize - 7;
	return (void*)(&baseAddr[cIndex]);
}

void Malloc::setCluster(signed long &table)
{
	unsigned short i = addrTable[table].index;
	unsigned short len = addrTable[table].block;

    cluster[i++] |= addrTable[table].head;

	if(len == 1)
	{
		return;
	}
	else if(len == 2)
	{
		cluster[i] |= addrTable[table].tail;
		return;
	}

	len += i - 2;

	for(;i<len;i++)
	{
		cluster[i] |= 0xffffffff;
	}

    cluster[i] |= addrTable[table].tail;
}

inline bool Malloc::findStartCluster(unsigned long &size, signed long &table, unsigned char &bit)
{
	unsigned long loop = calculateSize(clusterSize);

	if(!size)
		return false;

	unsigned long index, cmp, defualt, sub;

   	if(size <= 32)
	{
		defualt = 0xffffffff >> (32 - size);
	}
	else
	{
		defualt = 0xffffffff;
	}


	for(index=addrTable[table].index;index<loop;index++)
	{
		if(cluster[index] != 0xffffffff)
		{
			cmp = defualt;

            for(bit=0;bit<32;bit++)
			{
				if(!(cmp & cluster[index]))
				{
					addrTable[table].head = cmp;
					addrTable[table].index = index;
                    addrTable[table].block = 1;
					sub = bit + size;
					if(sub >= 32)
					{
						sub -= 32;
						size -= size - sub;
					}
					else
						size = 0;

					return true;
				}
				cmp <<= 1;
			}
		}
	}

	return false;
}

bool Malloc::isValidCluster(unsigned long &size, signed long &table)
{
	if(!size)
		return true;

	unsigned short index = addrTable[table].index + 1;
	unsigned short block = (size >> 5) + index;
	unsigned long cmp;

	for(;index<block;index++)
	{
		if(cluster[index])
		{
			addrTable[table].index = index;
			return false;
		}
	}

	addrTable[table].block += block - addrTable[table].index - 1;
	size &= 0x1f;

	if(size)
	{
		cmp = 0xffffffff >> (32-size);
		if(cluster[index] & cmp)
		{
			addrTable[table].index = index;
            return false;
		}

        addrTable[table].block++;
        addrTable[table].tail |= cmp;
	}
	
	return true;
}

void* Malloc::malloc(unsigned long size)
{
	void *rAddr = 0;
	unsigned long shift = (this->memSize - this->clusterSize - 5);
    unsigned long clusterSize = size >> shift, tmpSize;
	signed long table = findValidTable();
	unsigned char startBit;

	tmpSize = 0xffffffff >> (32 - shift);
	if(size & tmpSize)
		clusterSize++;

	if(table < 0)
		return rAddr;

	tmpSize = clusterSize;
	addrTable[table].index = 0;

	while(findStartCluster(tmpSize, table, startBit))
	{
		if(isValidCluster(tmpSize, table))
		{
			rAddr = getAddr(addrTable[table].index, startBit);
			addrTable[table].addr = rAddr;
            setCluster(table);
			mallocCnt++;

			return rAddr;
		}

		tmpSize = clusterSize;
	}
	
    return rAddr;
}

void Malloc::clrCluster(signed long &table)
{
	unsigned short i = addrTable[table].index;
	unsigned short len = addrTable[table].block;

    cluster[i++] &= ~addrTable[table].head;

	if(len == 1)
	{
		return;
	}
	else if(len == 2)
	{
		cluster[i] &= ~addrTable[table].tail;
		return;
	}

	len += i - 2;

	for(;i<len;i++)
	{
		cluster[i] = 0;
	}

    cluster[i] &= ~addrTable[table].tail;
}

void Malloc::free(void *addr)
{
	signed long i;
    signed long loop = calculateSize(mallocSize);

	for(i=0;i<loop;i++)
	{
		if(addr == addrTable[i].addr)
		{
			mallocCnt--;
            clrCluster(i);
			addrTable[i].addr = 0;
			return;
		}
	}
}
