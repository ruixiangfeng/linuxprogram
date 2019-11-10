#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*void main()
{
	printf("call:pid=%d,ppid=%d",getpid(),getppid());
	system("/home/rlk/linuxprogram/week9/code/exam/test");
	printf("After calling");

}*/


void main()
{
	char* argv[4];
	argv[0] = "/home/rlk/linuxprogram/week9/code/exam/test";
	argv[1] = "hello";
	argv[2] = "world";
	argv[3] = NULL;
	printf("call:pid=%d,ppid=%d",getpid(),getppid());
	execv(argv[0],argv[1]);
    printf("After calling");
	
}
