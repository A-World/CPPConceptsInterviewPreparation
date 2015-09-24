#include <stdio.h>
#include <stdlib.h>
#define NFORKS 50000
#if 0
int main()
{

	pid_t p;
	printf("Inside main START \n");
	p = fork();
	printf("Inside main END\n");
	
}
#endif

int num = 0;
int main(int argc, char*argv[])
{
    int pid = 0 ;
    pid = fork();
    printf("Num values is %d LINE = [%3d] \n", num,__LINE__);
    if(pid == 0)
	{  
		printf("Inside the Child process LINE = [%3d] \n",__LINE__);
        num = 1;
    }
	else 
	if(pid > 0)
	{  
		printf("Inside the Parent process LINE = [%3d] \n",__LINE__);
        num = 2;
    }
    printf("Num values is %d LINE = [%3d]  \n", num,__LINE__);

}