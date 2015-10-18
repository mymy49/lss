#ifndef REG__H_
#define REG__H_

#define setRegBit(addr, bit, sh) ((bit)==1 ? (addr) |= (0x1 << (sh)) : (addr) &= ~(0x1 << (sh)))
#define getRegBit(addr, sh) ((addr) & (1 << (sh)))

#define setRegField(addr, mask, data, sh)	{unsigned long buf;buf = addr;buf &= ~(mask << sh);buf |= (data << sh);addr=buf;}
#define setRegField3(addr, mask1, data1, sh1, mask2, data2, sh2, mask3, data3, sh3)	{unsigned long buf;buf = addr;buf &= ~((mask1 << sh1) | (mask2 << sh2) | (mask3 << sh3));buf |= (data1 << sh1) | (data2 << sh2) | (data3 << sh3);addr=buf;}

#define getRegField(addr, mask, sh)	(addr >> sh) & mask

#endif