#include <unistd.h>

typedef int Thread_id;
typedef int Mutex_id;

Mutex_id init_mutex(void)
{
	return syscall(341);
}

int lock_mutex(Mutex_id uid)
{
	return syscall(342, uid);
}

int unlock_mutex(Mutex_id uid)
{
	return syscall(343, uid);
}

int destroy_mutex(Mutex_id uid)
{
	return syscall(344, uid);
}

int uthread_create(void (*fn)(void *), void * arg)
{
	return syscall(345, fn, arg);
}

int uthread_wait(void)
{
	return syscall(346);
}

int uthread_exit(void)
{
	return syscall(347);
}

int uthread_setpriority(void)
{
	return syscall(348);
}

int uthread_getpriority(void)
{
	return syscall(349);
}

int uthread_setscheduler(void)
{
	return syscall(350);
}

int uthread_getscheduler(void)
{
	return syscall(351);
}
