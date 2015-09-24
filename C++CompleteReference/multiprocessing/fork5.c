#include<stdio.h>
#include <pthread.h>



#define PRINT(...) sprintf(buf, "PID is [%5d]  : ", getpid()); write(1, buf, strlen(buf)); sprintf(buf, __VA_ARGS__); write(1, buf, strlen(buf));     



#if 0

#define MAX_BUF_SIZE 200
#define BUF_SIZE 	 100

void childProcess(char [], char[]);

int main()
{

	pid_t pid1,pid2, pid;
	int status;
	int i;
	char buf[BUF_SIZE];
	
	PRINT("*** Parent about to fork child 1 **** \n");

	if((pid1 = fork()) < 0 )
	{
		PRINT("*** Failed to fork child 1 **** \n");
	}
	else
	if (pid1 == 0) 
          ChildProcess("First", "   ");
	
	PRINT("*** Parent about to fork child 2 **** \n");

	if((pid2 = fork()) < 0 )
	{
		PRINT("*** Failed to fork child 2 **** \n");
	}
	else
	if (pid2 == 0) 
          ChildProcess("Second", "   ");
	
	 sprintf(buf, "PID is [%5d]  :  *** Parent enters waiting status .....\n",getpid());
     write(1, buf, strlen(buf));
     pid = wait(&status);
	 sprintf(buf, "PID is [%5d]  : *** Parent detects process %d was done ***\n",getpid(), pid);
     write(1, buf, strlen(buf));
     pid = wait(&status);
     PRINT("*** Parent detects process %d is done ***\n", pid);
     PRINT("*** Parent exits ***\n");
     exit(0);
}

void  ChildProcess(char *number, char *space)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];

     pid = getpid();
     sprintf(buf, "PID is [%5d]  : %s%s child process starts (pid = %d)\n", 
             getpid(),space, number, pid);
     write(1, buf, strlen(buf));
     for (i = 1; i <= MAX_BUF_SIZE; i++) {
          sprintf(buf, "PID is [%5d]  : %s%s child's output, value = %d\n",getpid(), space, number, i); 
        //  write(1, buf, strlen(buf));
     }
     sprintf(buf, "PID is [%5d]  : %s%s child (pid = %d) is about to exit\n",getpid(), 
             space, number, pid);
     write(1, buf, strlen(buf));     
//     exit(0);
}


#endif










#if 1

int glb  = 0 ;
int main()
{

	char buf[200];
 	PRINT("Start %d \n", glb++);
	fork();
 	PRINT("After Fork 1 %d \n",glb++);
	fork();
 	PRINT("After Fork 2 %d \n",glb++);
}


/*

PID is [ 9524]  : Start 0
PID is [ 9524]  : After Fork 1 1
PID is [ 9524]  : After Fork 2 2
PID is [ 9526]  : After Fork 2 2
PID is [ 9525]  : After Fork 1 1
PID is [ 9525]  : After Fork 2 2
PID is [ 9527]  : After Fork 2 2


*/

/*   Expected output matches with acutal output
PID is [ 8863]  : Start
PID is [ 8863]  : After Fork 1
PID is [ 8863]  : PID is [ 8865]  : PID is [ 8864]  : After Fork 2
After Fork 2
After Fork 1
PID is [ 8864]  : After Fork 2
PID is [ 8866]  : After Fork 2

*/

#endif