#include <unistd.h>

int uthread_create(int (*fn)(void *), void *arg)
{
	return syscall(345, fn, arg);
}
