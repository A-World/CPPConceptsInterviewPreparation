#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

#if 0 
void ClientProgess(int []);
void main()
{
	int 	ShmID;
	int 	*ShmPTR;
	pid_t 	pid;
	int 	status;
	
	ShmID = shmget(IPC_PRIVATE, 4*sizeof(int),IPC_CREAT|0666);
	if(ShmID < 0 )
	{
			printf("Failed to allocate memory \n");
	}
	
	printf("Server has received a shared memory of four integers...\n");

	
	ShmPTR = (int *) shmat(ShmID, NULL, 0);
     if ((int) ShmPTR == -1) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     printf("Server has attached the shared memory...\n");

	 ShmPTR[0] = 0x45 * 0x87;
     ShmPTR[1] = 0x45 * 0x21;
     ShmPTR[2] = 0x45 * 0x782;
     ShmPTR[3] = 0x45 * 0x14;
	 
	 
	 printf("Server has filled %d %d %d %d in shared memory...\n",
            ShmPTR[0], ShmPTR[1], ShmPTR[2], ShmPTR[3]);

     printf("Server is about to fork a child process...\n");
     pid = fork();
     if (pid < 0) {
          printf("*** fork error (server) ***\n");
          exit(1);
     }
     else if (pid == 0) {
          ClientProcess(ShmPTR);
          exit(0);
     }

     pid = fork();
     if (pid < 0) {
          printf("*** fork error (server) ***\n");
          exit(1);
     }
     else if (pid == 0) {
          ClientProcess(ShmPTR);
          exit(0);
     }
     pid = fork();
     if (pid < 0) {
          printf("*** fork error (server) ***\n");
          exit(1);
     }
     else if (pid == 0) {
          ClientProcess(ShmPTR);
          exit(0);
     }

	 
	 wait(&status);
	 wait(&status);
	 wait(&status);
     printf("Server has detected the completion of its child...\n");
     shmdt((void *) ShmPTR);
     printf("Server has detached its shared memory...\n");
     shmctl(ShmID, IPC_RMID, NULL);
     printf("Server has removed its shared memory...\n");
     printf("Server exits...\n");
     exit(0);	 
}

void  ClientProcess(int  SharedMem[])
{
     printf("   %d    Client process started \n",getpid());
     printf("   %d    Client found %d %d %d %d in shared memory\n",getpid(),
                SharedMem[0], SharedMem[1], SharedMem[2], SharedMem[3]);
     printf("   %d    Client is about to exit\n",getpid());
}


#endif
// I try to use dynamically allocated memory pointer and try to share memory.


// Separate copy of memory is created.
void print_data(int *p)
{
	
	int i = 0;
	for(i = 0; i < 10; i++)
		printf(" %d    ", p[i]);
		printf("\n");

	for(i = 0; i < 10; i++)
		p[i] = 3*i;

}

int main()
{
	int i = 0;
	int *pi = malloc(sizeof(int) * 10 );
	for(i = 0; i < 10; i++)
		pi[i] = 2*i;
	int pid,status;	
	pid = fork();

	if(pid == 0 )
	{
		print_data(pi);
		print_data(pi);

		exit(0);
	}
	wait(&status);
	print_data(pi);
	print_data(pi);
	
}


































