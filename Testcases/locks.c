#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/kernel.h>

int main(void) {
	long ID1, ID2;
	/*-----------------------------*/
	/* direct system call */
	/* SYS_getpid (func no. is 20) */
	/*-----------------------------*/
	ID1 = syscall(343);
	printf ("syscall(343)=%ld\n", ID1);
	/*-----------------------------*/
	/* "libc" wrapped system call */
	/* SYS_getpid (Func No. is 20) */
	/*-----------------------------*/
	// ID2 = getpid();
	// printf ("getpid()=%ld\n", ID2);
	return 0;
}
