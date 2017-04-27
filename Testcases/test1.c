#include "uthread.h"
#include <stdio.h>


void inc_x(void *x_void_ptr)
{

	int *x_ptr = (int *)x_void_ptr;
	while(++(*x_ptr) < 100);
	printf("x increment finished: %d\n",*x_ptr);
	uthread_exit();

}

int main()
{

	int x = 0, y = 0,pid;
	printf("x: %d, y: %d\n", x, y);
	pid = uthread_create(&inc_x, &x);

	printf("pid: %d\n",pid);
	while(++y < 100);

	printf("y increment finished\n");
	
	uthread_wait();
	printf("x: %d, y: %d\n", x, y);

	return 0;

}