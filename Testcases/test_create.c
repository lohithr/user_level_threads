#include "uthread.h"
#include <stdio.h>
#include <stdlib.h>

int G[10];

int func(void * arg)
{
	int * P = (int *) arg;

	for (int i = 0; i < 10; ++i) printf("%d\n", P[i]);

	exit(0);
}

int main()
{
	int L[10];

	for (int i = 0; i < 10; ++i) G[i] = 300 + i;
	for (int i = 0; i < 10; ++i) L[i] = 300 + i;

	uthread_create(func, L);
	return 0;
}
