#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int count = 0 ;
	while(count < 100){
		count++;
		int pid = fork();
		if(pid==0){
			//code for child
			
			exit(0);
		}
	}
	wait4();
}