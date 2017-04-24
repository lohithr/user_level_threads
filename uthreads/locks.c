#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/mutex.h>
#include <linux/idr.h>	
#include <linux/slab.h>

asmlinkage long sys_init_mutex()
{
	struct mutex *ulock;
	int uid;
	printk(KERN_INFO "create mutex called.\n");
	ulock = kmalloc(sizeof(struct mutex),GFP_KERNEL);
	// do {
	// 	if(!idr_pre_get(&(current->locks_map), GFP_KERNEL))
	// 	{
	// 		return -ENOSPC;
	// 	}
	// 	ret = idr_get_new(&(current->locks_map), &ulock , &uid);
	// } while (ret == -EAGAIN);
	uid = idr_alloc(&(current->locks_map), &ulock , 1 , 100, GFP_KERNEL);


	return uid;	
}

asmlinkage long sys_lock_mutex(int uid)
{
	struct mutex *umutex;
	printk(KERN_INFO "sys_lock_mutex called.\n");
	umutex = idr_find(&(current->locks_map),uid);
	if(!umutex)
		return -EINVAL; 
	mutex_lock(umutex);
	return 0;
}

asmlinkage long sys_unlock_mutex(int uid)
{
	struct mutex *umutex;
	printk(KERN_INFO "sys_unlock_mutex called.\n");
	umutex = idr_find(&(current->locks_map),uid);
	if(!umutex)
		return -EINVAL;
	mutex_unlock(umutex);
	return 0;
}

asmlinkage long sys_destroy_mutex(int uid)
{
	struct mutex *umutex;
	printk(KERN_INFO "sys_unlock_mutex called.\n");
	umutex = idr_find(&(current->locks_map),uid);
	if(!umutex)
		return -EINVAL;
	idr_remove(&(current->locks_map),uid);
	mutex_destroy(umutex);
	// kfree(umutex);
	return 0;
}