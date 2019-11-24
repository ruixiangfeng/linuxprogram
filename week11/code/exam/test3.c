#include "my.h"
int main()
{
	int pid,s;
	if((pid=fork()<0)
	{
		perror("failes to fork@\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("%d:child is running now\n",getpid());
		printf("%d:child is exit now\n",getpid());
		while(1);
		exit(120);
	}
	else
	{
		printf("%d:parent is waiting zombie now\n",getpid());
		while((pid = wait(&s))!=1)
		{
			printf("%d:parent is exiting now\n",getpid());
			
			if(WIFEXITED(S))
			{
				printf("child %d is exitingnormally,exit code=%d\n",pid,WEXITSTATUS(s));
			}
			else if//not 
			{
			
			}
		}
		
	}
	exit(0);
}
