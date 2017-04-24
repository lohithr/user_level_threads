#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/decompress/mm.h>

#define STACK_SZ 1024 * 64 

asmlinkage long sys_uthread_create()
{
	unsigned long stack_ptr;

	printk(KERN_INFO "sys_uthread_create called\n");

	stack_ptr = (unsigned long) malloc(STACK_SZ);

	return _do_fork(SIGCHLD | CLONE_FILES | CLONE_FS | CLONE_VM | CLONE_SIGHAND, stack_ptr, 0, NULL, NULL, 0);
}

