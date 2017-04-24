#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/kernel.h>

int main(void) {
	long ID1, ID2, ID3;

	ID2 = syscall(341);
	printf ("syscall(341)=%ld\n", ID2);
	ID1 = syscall(342,ID2);
	printf ("syscall(342)=%ld\n", ID1);
	ID1 = syscall(343,ID2);
	printf ("syscall(343)=%ld\n", ID1);
	ID1 = syscall(344,ID2);
	printf ("syscall(344)=%ld\n", ID1);
	ID1 = syscall(345,NULL,NULL);
	printf ("syscall(345)=%ld\n", ID1);
	
	return 0;
}
