#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
/*int main()
{
	printf("test:pid=%d,ppid=%d",getpid(),getppid());
}*/

int main(int argc,char* argv[],int i)
{
	printf("test:pid=%d,ppid=%d",getpid(),getppid());
	for(i=0;i<argc;i++)
		printf("%s\n",argv[i]);
}
