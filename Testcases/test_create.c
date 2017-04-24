#include "uthread.h"
#include <unistd.h>

int func(void * arg)
{
	// printf("%d\n", *((int *)arg));
	return 0;
}

int main()
{
	int i, j;
	j = 100;
	i = uthread_create(func, NULL);
	// printf("%d\n", i);
	return 0;
}
