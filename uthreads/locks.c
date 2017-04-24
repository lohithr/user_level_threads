#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/mutex.h>

asmlinkage long sys_init_mutex(struct uthread_mutex * umutex)
{
	printk(KERN_INFO "create mutex called.\n");
	
	mutex_init(&(umutex->lock));
	return 0;	
}

asmlinkage long sys_lock_mutex(struct uthread_mutex * umutex)
{
	printk(KERN_INFO "sys_lock_mutex called.\n");
	mutex_lock(&(umutex->lock));
	return 0;
}

asmlinkage long sys_unlock_mutex(struct uthread_mutex * umutex)
{
	printk(KERN_INFO "sys_unlock_mutex called.\n");
	mutex_unlock(&(umutex->lock));
	return 0;
}

asmlinkage long sys_destroy_mutex(struct uthread_mutex * umutex)
{
	printk(KERN_INFO "sys_unlock_mutex called.\n");
	mutex_destroy(&(umutex->lock));
	return 0;
}