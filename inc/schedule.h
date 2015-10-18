#ifndef LSS_SCHEDULE__H_
#define LSS_SCHEDULE__H_

// /lss/sys/switchContext.cpp
void switchContext(void);

// /lss/sys/thread.cpp
signed long addThread(void (*func)(void), unsigned long size);

// /lss/sys/thread.cpp
void delThread(signed long num);

// /lss/sys/thread.cpp
void initThread(void);

// /lss/sys/lssTime.cpp
void delay(unsigned long delayTime);




#endif
