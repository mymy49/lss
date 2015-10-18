
void callSvc(void (*func)(void*), void* args)
{
	asm volatile("svc 0");
}
