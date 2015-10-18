#ifndef LSS_SVC__H_
#define LSS_SVC__H_

// /lss/sys/callSvc.cpp
void callSvc(void (*func)(void*), void* args);

#endif