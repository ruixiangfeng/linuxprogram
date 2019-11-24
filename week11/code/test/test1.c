#include "my.h"
int main()
{
	int status;
	pid_t pid1;
	pid_t pid2;
	FILE *fp;
	fp = fopen("out.bat","w+");
	char *arr="0123456789";
	pid1 = fork();
	pid2 = fork();
	if(pid1 < 0 || pid2 < 0)
	{
		perror("fork failed\n");
		return -1;
	}	
	
	else if(pid1 == 0)
	{
		char *arr1=getpid();
		printf("child1 is writing!pid = %d\n",getpid());
		write(fp,arr1,strlen(arr1);
		write(fp,arr,strlen(arr);
		return 0;
	}
	else if(pid2 == 0)
	{
		char *arr2=getpid();
		printf("child2 is writing!pid = %d\n",getpid());
		write(fp,arr2,strlen(arr2);
		write(fp,arr,strlen(arr);
		return 0;
	}
	
	else
	{
		printf("parent pid = %d\n",getpid());
		return 0;
		
	}
	
	close *fp;

}
