#ifndef LSS_STDLIB__H_
#define LSS_STDLIB__H_

void* lmalloc(unsigned long size);
void lfree(void* addr);

void* hmalloc(unsigned long size);
void hfree(void* addr);

#endif
