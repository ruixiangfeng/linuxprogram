#include "my.h"
#define NUM_THREADS 4
long unsigned totaltime;
struct info
{
	int no;
	int n;
};

void hello(void * t)
{
	int shh = 0, smi = 0, sss = 0, sms = 0,ehh = 0, emi = 0, ess = 0, ems = 0;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	pthread_t my_tid;
	struct info *y;
	int s=0;
	y = (struct info *)(t);
	for(int i=0;i<=y->n;i++)
		s+=i; 
	my_tid=pthread_self();
	printf("\tThread %d: my tid is %lx,Hello world\n",(int)y->no+1,my_tid);
	printf("\tsum 1 to %d is %d\n",y->n,s);
	gettimeofday(&end, NULL);
	totaltime = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec);
	//时
	shh = start.tv_sec/(60*60)%24;
	ehh = end.tv_sec/(60*60)%24;
    //分
    smi = start.tv_sec/60 - start.tv_sec/(60*60)*60;
	emi = end.tv_sec/60 - end.tv_sec/(60*60)*60;
    //秒
    sss = start.tv_sec - start.tv_sec/60*60;
	ess = end.tv_sec - end.tv_sec/60*60;
	//微秒
	sms = start.tv_usec;
	ems = end.tv_usec;
	printf("starttime: %02d:%02d:%02d.%06d\n",  shh, smi, sss, sms);
	printf("endtime: %02d:%02d:%02d.%06d\n",  ehh, emi, ess, ems);
	printf("time: %lu us\n", totaltime);
	pthread_exit(totaltime);
}

int main()
{
	pthread_t tid;
	struct info a[4];
	int rv,t,i,ptr[4];
	for(t=0;t<NUM_THREADS;t++)
	{
		
		a[t].no=t;
		a[t].n=100*(t+1);
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		pthread_join(tid,(void**)&ptr[t]);
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("Create thread %lx\n",tid);
	}
	for(i=0;i<NUM_THREADS;i++)
	{
		printf("t%d totaltime is %d\n",i,ptr[i]);
	}
	printf("Good bye!\n");
	pthread_exit(NULL);
}
