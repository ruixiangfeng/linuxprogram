//#include "mylib.h"
#include <stdio.h>

int main()
{
	int a = 0;
	printf("********************************\n");
    printf("0. 退出\n");
	printf("1. 创建新文件\n");
	printf("2. 写文件\n");
	printf("3. 读文件\n");
	printf("4. 修改文件权限\n");
	printf("5. 查看当前文件的权限修改文件权限\n");
	printf("********************************\n");
	printf("Please input your choice(0-6):\n");
    scanf("%d",&a);

    return 0;
}
