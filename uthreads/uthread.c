#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/slab.h>

#define STACK_SZ 2 * 1024 * 1024

asmlinkage long sys_uthread_create(void (*fn)(void *), void * arg)
{
	unsigned long stack_ptr;
	unsigned long * uthread_ptrs;

	printk(KERN_INFO "sys_uthread_create called.\n");

	if(current->uthreads == NULL)
	{
		current->uthreads = kmalloc(sizeof(struct list_head), GFP_KERNEL);
		INIT_LIST_HEAD(current->uthreads);
	}

	stack_ptr = sys_brk(0);
	stack_ptr = sys_brk(stack_ptr + STACK_SZ);

	uthread_ptrs = kmalloc(2 * sizeof(unsigned long), GFP_KERNEL);
	uthread_ptrs[0] = (unsigned long) fn;
	uthread_ptrs[1] = (unsigned long) arg;

	return _do_do_fork(SIGCHLD | CLONE_FILES | CLONE_FS | CLONE_VM | CLONE_SIGHAND, stack_ptr, STACK_SZ, NULL, NULL, 0, uthread_ptrs);
}

asmlinkage long sys_uthread_wait(void)
{
	struct childpid * cpid, * next;

	if(current->uthreads != NULL)
	{
		list_for_each_entry_safe(cpid, next, current->uthreads, list)
		{
			sys_wait4(cpid->pid, 0, 0, NULL);
			kfree(cpid);
		}

		kfree(current->uthreads);
		current->uthreads = NULL;
	}

	printk(KERN_INFO "sys_uthread_wait called.\n");

	return 0;
}

asmlinkage long sys_uthread_exit(void)
{
	printk(KERN_INFO "sys_uthread_exit called.\n");
	do_exit((0&0xff)<<8);
	return -1;
}
