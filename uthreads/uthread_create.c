#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long sys_uthread_create(int (*fn)(void *), void __user *arg)
{
	long pid = 2;

	printk(KERN_INFO "sys_uthread_create called\n");

	return pid;
}