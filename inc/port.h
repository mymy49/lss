#ifndef LSS_PORT__H_
#define LSS_PORT__H_

// /lss/port/portTime.cpp
void portTime(void);

// /lss/sys/lssTime.cpp
void setFuncGetLssClock(unsigned long (*func)(void));

#endif
