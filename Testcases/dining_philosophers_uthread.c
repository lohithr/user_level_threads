#include <stdio.h>
#include <stdlib.h>
#include "uthread.h"

void func(void* temp);
int chopstick[5];

int main()
{
	int i,k;
	int threads[5];
	void *msg;
	for(i=0;i<5;i++)
	{
		chopstick[i]=init_mutex();
		if(chopstick[i] < 1 || chopstick[i] > 100)
		{
			printf("\n Mutex initialization failed");
			exit(1);
		}
	}
	for(i=0;i<5;i++)
	{
		threads[i] = i;
		k=uthread_create(&func,&threads[i]);
		if(!k)
		{
			printf("\n Thread creation error \n");
			exit(1);
		}
	}
	
	k=uthread_wait();
	if(k)
	{
		printf("\n uthread_wait error\n");
	}

	for(i=0;i<5;i++)
	{
		k=destroy_mutex(chopstick[i]);
		if(k)
		{
			printf("\n Mutex not Destroyed \n");
		}
	}
	return 0;
}

void func(void* temp)
{
	int n = *(int *)temp;
	printf("\n Philosopher %d is thinking ",n);
	// lock_mutex(chopstick[n]);
	// lock_mutex(chopstick[(n+1)%5]);
	printf("\n Philosopher %d is eating ",n);
	// int temp1=1,i;
	// for (i = 0; i < 50; ++i)
	// {
	// 	temp1*=(i+1);
	// }
	// unlock_mutex(chopstick[n]);
	// unlock_mutex(chopstick[(n+1)%5]);
	printf("\n Philosopher %d Finished eating ",n);
}