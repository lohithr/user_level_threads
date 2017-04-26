#include <unistd.h>

int init_mutex(void)
{
	return syscall(341);
}

int lock_mutex(int uid)
{
	return syscall(342,uid);
}

int unlock_mutex(int uid)
{
	return syscall(343,uid);
}

int destroy_mutex(int uid)
{
	return syscall(344,uid);
}

int uthread_create(int (*fn)(void *), void *arg)
{
	return syscall(345, fn, arg);
}

int uthread_join(void)
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