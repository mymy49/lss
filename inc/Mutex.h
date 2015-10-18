#ifndef LSS_MUTEX_H_
#define LSS_MUTEX_H_

// /lss/sys/Mutex.cpp
class Mutex
{
	volatile bool usingFlag;
	void (*switchContext)(void);
public:
	Mutex(void (*func)(void));
	void lock(void);
	void unlock(void);
};

#endif