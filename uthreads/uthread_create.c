#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long sys_uthread_create(int (*fn)(void *), void __user *arg)
{
	long pid = 2;

	printk(KERN_INFO "sys_uthread_create called\n");
	// _do_fork( CLONE_F/S | CLONE_FILES | CLONE_SIGHAND | CLONE_VM,);
	return pid;
}