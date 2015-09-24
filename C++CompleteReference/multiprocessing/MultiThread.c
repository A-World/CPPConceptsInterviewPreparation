#include"stdio.h"
#include"pthread.h"
void *runner(void * val)
{
	int i = 0;
	char *msg;
	msg = (char *)val;
	for(i = 0; i < 10; i ++)
	{
		sleep(1);
		printf("Thread is %s and no is %d \n",msg,i);
	}

	pthread_exit(0);
}

int main()
{
	pthread_t tid1;
	pthread_t tid2;
	
	char msg1[] = "tid1";
	char msg2[] = "tid2";

	pthread_create(&tid1,NULL,runner,(void*)msg1);
	pthread_create(&tid2,NULL,runner,(void*)msg2);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);	
}

