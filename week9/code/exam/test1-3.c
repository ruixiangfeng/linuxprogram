#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
int main()
{
	pid_t result;
	result=fork();/*调用fork函数，返回值存在变量result中*/
	int newret;
	if(result==-1) /*通过对result的值来判断fork函数的返回情况，这儿先进行出错处理*/
	{
		perror("创建子程序失败");
		exit;
	}
	else if(result==0)/*返回值为0代表子进程*/
	{
		printf("返回值是:%d,说明这是子进程！\n");
	}
}
