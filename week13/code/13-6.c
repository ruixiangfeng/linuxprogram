#incude "my.h"
void fun()
{
	printf("call sig callback function!\n");
	printf("mask block.\n");
	signal(2,SIG_DFL);
}

int main()
{
	int i;
	
}
