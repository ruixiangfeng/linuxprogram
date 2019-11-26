#include "my.h"
int count=0;
int main()
{
	pid_t p1,p2,p3;
	p1=fork();
	int s1,s2,s3,r1,r2,r3;

	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
			perror("pipe failed .\n");
			return -1;		
	} 

	if(p1<0)
	{
		perror("fork faileds.\n");
		return -1;
	}
	else if(p1==0)
	{
		count+=1;
		printf("child pid = %d,ppid = %d,count=%d\n",getpid(),getppid(),count);
		exit(0);
	}
	else
	{
		p2=fork();
		if(p2<0)
		{
			perror("fork faileds.\n");
			return -1;
		}
		else if(p2==0)
		{
			count+=1;
			printf("child pid = %d,ppid = %d,count=%d\n",getpid(),getppid(),count);
			exit(0);
		}
		else
		{
			p3=fork();
			if(p2<0)
			{
				perror("fork faileds.\n");
				return -1;
			}
			else if(p3==0)
			{
				count+=1;
				printf("child pid = %d,ppid = %d,count=%d\n",getpid(),getppid(),count);
				exit(0);
			}
			else
			{
				printf("parent sleeping\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);			printf("r1=%d,s1=%d,r2=%d,s2=%d,r2=%d,s2=%d",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));				
				printf("parent pid=%d,count=%d/n",getpid(),count);
				return 0;
			}
		}

	}

}
