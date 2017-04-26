#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/slab.h>

#define STACK_SZ 1024 * 64

asmlinkage long sys_uthread_create(int (*fn)(void *), void * arg)
{
	unsigned long stack_ptr;
	unsigned long * uthread_ptrs;

	stack_ptr = sys_brk(0);
	stack_ptr = sys_brk(stack_ptr + STACK_SZ);

	uthread_ptrs = kmalloc(2 * sizeof(unsigned long), GFP_KERNEL);
	uthread_ptrs[0] = (unsigned long) fn;
	uthread_ptrs[1] = (unsigned long) arg;

	return _do_do_fork(SIGCHLD | CLONE_FILES | CLONE_FS | CLONE_VM | CLONE_SIGHAND, stack_ptr, STACK_SZ, NULL, NULL, 0, uthread_ptrs);
}

asmlinkage long sys_uthread_wait(void)
{
	struct task_struct *child;
	
	read_lock(&tasklist_lock);

	list_for_each_entry(child,&(current->children),sibling){
		read_unlock(&tasklist_lock);
		sys_wait4(child->pid, 0, 0, NULL);
		read_lock(&tasklist_lock);
	}

	read_unlock(&tasklist_lock);
	
	return 0;
}

asmlinkage long sys_uthread_exit(void)
{
	do_exit((0&0xff)<<8);
	return 0;
}

asmlinkage long sys_uthread_setpriority(void)
{
	return 0;
}

asmlinkage long sys_uthread_getpriority(void)
{
	return 0;
}

asmlinkage long sys_uthread_setscheduler(void)
{
	return 0;
}

asmlinkage long sys_uthread_getscheduler(void)
{
	return 0;
}

