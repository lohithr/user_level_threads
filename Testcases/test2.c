#include "uthread.h"
#include <stdio.h>

int x;

/* this function is run by the second thread */
int inc_x(void *x_void_ptr)
{

/* increment x to 100 */
int *x_ptr = (int *)x_void_ptr;
int count = 0;
if(lock_mutex(*x_ptr)){
	printf("error in lock_mutex\n" );;
}

while(++count < 100){
	x++;
}
printf("x increment finished: %d\n",x);
if(unlock_mutex(*x_ptr)){
	printf("error in unlock_mutex\n" );;
}

/* the function must return something - NULL will do */
uthread_exit();

}

int main()
{

int y = 0,pid1,pid2;
int uid;

uid = init_mutex();

/* show the initial values of x and y */
printf("x: %d, y: %d\n", x, y);

/* create a second thread which executes inc_x(&x) */
pid1 = uthread_create(inc_x, &uid);
pid2 = uthread_create(inc_x, &uid);
// printf("pid1: %d\n",pid1);
// printf("pid2: %d\n",pid2);



// /* increment y to 100 in the first thread */
// while(++y < 100);

// printf("y increment finished\n");

/* wait for the second thread to finish */
uthread_join();

destroy_mutex(uid);

/* show the results - x is now 100 thanks to the second thread */
printf("x: %d, y: %d\n", x, y);

return 0;

}