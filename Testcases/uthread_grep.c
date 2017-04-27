#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "uthread.h"

int temp(void* arg)
{
	int count1 = 1;
	int i;
	for (i = 0; i < 100; ++i)
	{
		count1*=i;
	}
	uthread_exit();
}

int main()
{
	int count = 0 ;
	while(count < 1000){
		count++;
		int pid = uthread_create(&temp,NULL);
	}
	uthread_wait();
}