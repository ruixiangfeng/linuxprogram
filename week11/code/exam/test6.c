#include <stdio.h>
#include <time.h>
void int_daemon(void);
int main()
{                                                                                
	time_ t;
	init_daemon();
	while(1)
	{
		sleep(10);
		if((fp = fopen("test6.log","a"))>=0)
		{
			t= time(0);
			fprintf(fp,"守护进程还在进行，时间是：%s",asctime(localtime(&t)));
			fclose(fp);
		}
	}
}
