#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/mutex.h>
#include <linux/idr.h>	
#include <linux/slab.h>

asmlinkage long sys_init_mutex()
{
	struct mutex * ulock;
	int uid;

	printk(KERN_INFO "sys_init_mutex called.\n");

	if(current->locks_map == NULL)
	{
		current->locks_map = kmalloc(sizeof(struct idr), GFP_KERNEL);
		idr_init(current->locks_map);
	}

	ulock = kmalloc(sizeof(struct mutex),GFP_KERNEL);
	mutex_init(ulock);
	uid = idr_alloc(current->locks_map, ulock, 1, 100, GFP_KERNEL);
	return uid;
}

asmlinkage long sys_lock_mutex(int uid)
{
	struct mutex * umutex;

	printk(KERN_INFO "sys_lock_mutex called.\n");
	umutex = idr_find(current->locks_map, uid);
	if(!umutex)
		return -EINVAL; 
	mutex_lock(umutex);
	return 0;
}

asmlinkage long sys_unlock_mutex(int uid)
{
	struct mutex * umutex;

	printk(KERN_INFO "sys_unlock_mutex called.\n");
	umutex = idr_find(current->locks_map, uid);
	if(!umutex)
		return -EINVAL;
	mutex_unlock(umutex);
	return 0;
}

asmlinkage long sys_destroy_mutex(int uid)
{
	struct mutex * umutex;

	printk(KERN_INFO "sys_destroy_mutex called.\n");
	umutex = idr_find(current->locks_map, uid);
	if(!umutex)
		return -EINVAL;
	idr_remove(current->locks_map, uid);
	kfree(umutex);
	return 0;
}
