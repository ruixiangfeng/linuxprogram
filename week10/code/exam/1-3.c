#include "my.h"
int g =999;
int main()
{
	pid_t pid;
	int i = 888;
	static int k = 777;
	pid = vfork();
	int s;
	if(pid<0)
	{
		perror("vfork failed!\n");
		exit(-1);	
	}
	else if(pid == 0)
	{
		printf("child is running!\n");
		printf("child pid=%d:\n&g=%16p\n&i=%16p\n&k=%16p\n",getpid(),&g,&i,&k);
		//execl("./fork1","fork1",NULL);
		printf("child after execl\n0");
		_exit(12);
	}
	else
	{
		wait(&s);
		printf("parent is running!text code = %d\n",WEXITSTATUS(s));
		printf("parent will finish\n");
	}

}
