
#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>


#define  NOT_READY  -1
#define  FILLED     0
#define  TAKEN      1

struct Memory {
     int  status;
     int  data[4];
};



void  main(int  argc, char *argv[])
{
     key_t          ShmKEY;
     int            ShmID;
     struct Memory  *ShmPTR;

     ShmKEY = ftok(".", 'x');
     ShmID = shmget(ShmKEY, sizeof(struct Memory), IPC_CREAT | 0666);
     //ShmID = shmget(ShmKEY, sizeof(struct Memory), 0666);
     if (ShmID < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }
     printf("Server has received a shared memory of four integers...\n");

     ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
     if ((int) ShmPTR == -1) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     printf("Server has attached the shared memory...\n");

     ShmPTR->status  = NOT_READY;
     ShmPTR->data[0] = 0x48 * 0x484;
     ShmPTR->data[1] = 0x48 * 0x642;
     ShmPTR->data[2] = 0x48 * 0x341;
     ShmPTR->data[3] = 0x48 * 0x914;
     printf("Server has filled %d %d %d %d to shared memory...\n",
            ShmPTR->data[0], ShmPTR->data[1], 
            ShmPTR->data[2], ShmPTR->data[3]);
     ShmPTR->status = FILLED;

     printf("Please start the client in another window...\n");

     while (ShmPTR->status != TAKEN)
          sleep(1);

     printf("Server has detected the completion of its child...\n");
     shmdt((void *) ShmPTR);
     printf("Server has detached its shared memory...\n");
     shmctl(ShmID, IPC_RMID, NULL);
     printf("Server has removed its shared memory...\n");
     printf("Server exits...\n");
     exit(0);
}
