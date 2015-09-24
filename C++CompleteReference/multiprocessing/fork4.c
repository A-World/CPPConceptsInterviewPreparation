// Program to understand wait()
// wait () till child dies


#include<stdio.h>
#include<pthread.h>
#define MAX_BUF_SIZE 200
#define BUF_SIZE 	 100

void childProcess(char [], char[]);

int main()
{

	pid_t pid1,pid2, pid;
	int status;
	int i;
	char buf[BUF_SIZE];
	
	printf("*** Parent about to fork child 1 **** \n");

	if((pid1 = fork()) < 0 )
	{
		printf("*** Failed to fork child 1 **** \n");
	}
	else
	if (pid1 == 0) 
          ChildProcess("First", "   ");
	
	printf("*** Parent about to fork child 2 **** \n");

	if((pid2 = fork()) < 0 )
	{
		printf("*** Failed to fork child 2 **** \n");
	}
	else
	if (pid1 == 0) 
          ChildProcess("Second", "   ");
	
	sprintf(buf, "*** Parent enters waiting status .....\n");
     write(1, buf, strlen(buf));
     pid = wait(&status);
	 sprintf(buf, "*** Parent detects process %d was done ***\n", pid);
     write(1, buf, strlen(buf));
     pid = wait(&status);
     printf("*** Parent detects process %d is done ***\n", pid);
     printf("*** Parent exits ***\n");
     exit(0);
}

void  ChildProcess(char *number, char *space)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];

     pid = getpid();
     sprintf(buf, "%s%s child process starts (pid = %d)\n", 
             space, number, pid);
     write(1, buf, strlen(buf));
     for (i = 1; i <= MAX_BUF_SIZE; i++) {
          sprintf(buf, "%s%s child's output, value = %d\n", space, number, i); 
        //  write(1, buf, strlen(buf));
     }
     sprintf(buf, "%s%s child (pid = %d) is about to exit\n", 
             space, number, pid);
     write(1, buf, strlen(buf));     
     exit(0);
}
