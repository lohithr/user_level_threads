#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int count1 = 0 ;
	while(count1 < 1000){
		count1++;
		int pid = fork();
		if(pid==0){
			//code for child
			int count = 1;
			int i;
			for (i = 0; i < 100; ++i)
			{
				count*=i;
			}
			exit(0);
		}
	}
	waitpid(-1,NULL,0);
}