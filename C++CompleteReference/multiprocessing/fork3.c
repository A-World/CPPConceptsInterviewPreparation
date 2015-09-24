#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#if 0
#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;

     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
}

#endif




#if 1
#define MAX_SIZE 200
#define BUF_SIZE 100
int main()
{

	pid_t	pid; // Or you can have int also
	int i;
	char buf[BUF_SIZE];
	
	fork();
	pid = getpid(); // Linux call to get process id.
	
	for(i = 0 ; i < MAX_SIZE; i ++)
	{
		sprintf(buf, "This is from PID = %d , value = %d \n",pid,i);
		write(1,buf,strlen(buf)); // what this write call do??
		// This write directly writes to console. 1 is for consol
	}
}


// I'm getting continous output no interleaving or interacting of threads.
// May be due to i'm using a virtual machine to run linux.
#endif



#if 0 
int main() 
{ 
	int parentID = getpid(); /* ID of this process */
//	char prgname[] = "/home/ashish/data/dev/test"; 
	
	//gets(prgname); /* read the name of program we want to start */
	printf("Before creating any program pid is %d  LINE %4d \n",parentID,__LINE__);

	int cid = fork();  // create new child process 
	printf("Before creating any program pid is %d  LINE %4d \n",parentID,__LINE__);
	printf("Before creating any program pid is %d  LINE %4d \n",parentID,__LINE__);
	
	if(cid == 0) 
	{ 
		/* I'm the child process */
		//execlp( prgname, prgname, 0); /* Load the program */
		/* If the program named prgname can be started, we never get 
		to this line, because the child program is replaced by prgname */
		printf("Child process \n");
	} 
	else 
	{ 
		/* I'm the parent process */
		//sleep (1); /* Give my child time to start. */
		//waitpid(cid, 0, 0); /* Wait for my child to terminate. */
		printf("Parent process\n");
	}
}

#endif