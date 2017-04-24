#include <unistd.h>
#include <stdio.h>

// #include <sys/.h>

int uthread_create(int (*fn)(void *), void *arg)
{
	int ret;
	ret = syscall(345);

	printf("%d\n", ret);

	// if(ret == 0)
	// {
	// 	fn(arg);
	// 	// exit(0);
	// 	syscall(60, 0);
	// }

	return ret;
}
