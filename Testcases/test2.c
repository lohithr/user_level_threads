#include "uthread.h"
#include <stdio.h>
#include <sys/wait.h>

int x;

void inc_x(void *x_void_ptr)
{
	int *x_ptr = (int *)x_void_ptr;
	int count = 0;

	if(lock_mutex(*x_ptr)){
		printf("error in lock_mutex\n" );;
	}

	while(++count < 100){
		x++;
	}

	printf("x increment finished: %d\n",x);

	if(unlock_mutex(*x_ptr)){
		printf("error in unlock_mutex\n" );
	}

	uthread_exit();
}

int main()
{
	int y = 0, pid1, pid2;
	int uid;

	uid = init_mutex();

	printf("x: %d, y: %d\n", x, y);

	pid1 = uthread_create(inc_x, &uid);
	pid2 = uthread_create(inc_x, &uid);
	uthread_wait();

	destroy_mutex(uid);
	printf("x: %d, y: %d\n", x, y);

	return 0;
}
