#include "uthread.h"
#include <stdio.h>

/* this function is run by the second thread */
void inc_x(void *x_void_ptr)
{

/* increment x to 100 */
int *x_ptr = (int *)x_void_ptr;
while(++(*x_ptr) < 100);
printf("x increment finished: %d\n",*x_ptr);

/* the function must return something - NULL will do */
uthread_exit();

}

int main()
{

int x = 0, y = 0,pid;

/* show the initial values of x and y */
printf("x: %d, y: %d\n", x, y);

/* create a second thread which executes inc_x(&x) */
pid = uthread_create(&inc_x, &x);
printf("pid: %d\n",pid);

/* increment y to 100 in the first thread */
while(++y < 100);

printf("y increment finished\n");

/* wait for the second thread to finish */
waitpid(pid,0,0);
/* show the results - x is now 100 thanks to the second thread */
printf("x: %d, y: %d\n", x, y);

return 0;

}