#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <linux/mutex.h>

struct uthread_mutex
{
	struct mutex lock;
};

int main(void) {
	long ID1, ID2;
	struct uthread_mutex umutex;

	ID1 = syscall(341,&umutex);
	printf ("syscall(341)=%ld\n", ID1);
	ID1 = syscall(342,&umutex);
	printf ("syscall(342)=%ld\n", ID1);
	ID1 = syscall(343,&umutex);
	printf ("syscall(343)=%ld\n", ID1);
	ID1 = syscall(344,&umutex);
	printf ("syscall(344)=%ld\n", ID1);
	ID1 = syscall(345,NULL,NULL);
	printf ("syscall(345)=%ld\n", ID1);
	
	return 0;
}
