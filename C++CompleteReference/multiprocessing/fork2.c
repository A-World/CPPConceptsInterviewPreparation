#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>


int main()
{
	int pid = getpid();
	printf("LINE = [%3d]  PID for current process is %d \n",__LINE__,pid);
	pid = fork();
	printf("LINE = [%3d]  PID for current process is %d \n",__LINE__,pid);
	
	if(pid < 0 )
	{
		printf("LINE = [%3d]  New process not created but PID recieved is %d \n",__LINE__,pid);
	}
	if(pid = 0)
	{
		printf("LINE = [%3d]  New child process created and PID is %d \n",__LINE__,pid);
	}
	if(pid > 0)
	{
		printf("LINE = [%3d]  Inside the parent process with PID is %d \n",__LINE__,pid);	
	}
}
