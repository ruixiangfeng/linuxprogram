14-1.c
编译过程
gcc 14-1.c -o 14-1 -lpthread
运行结果
rlk@ubuntu:code$ ./14-1
main thread is ended! pid = 2052 tid = -639531264
thread pid =2052


14-2.c
线程的运行是不确定的
编译过程
gcc 14-2.c -o 14-2 -lpthread
运行结果
rlk@ubuntu:code$ ./14-2
Create thread 7f5e70b76700
	Thread 0: my tid is 7f5e70b76700,Hello world
Create thread 7f5e70375700
	Thread 1: my tid is 7f5e70375700,Hello world
Create thread 7f5e6fb74700
	Thread 2: my tid is 7f5e6fb74700,Hello world
Create thread 7f5e6f373700
Good bye!
	Thread 3: my tid is 7f5e6f373700,Hello world


14-2-2.c
编译过程
gcc 14-2-2.c -o 14-2-2 -lpthread
14-2的升级版
每个线程输出不同的和

14-3.c
编译过程
gcc 14-3.c -o 14-3 -lpthread
验证如何使用pthread_exit()以及pthread_join()第二个参数接收线程的返回值

test1.c
pthread_exit(NULL);
变化
for(i=0;i<NUM_THREADS;i++)
{
	pthread_join(tid,NULL);
}
运行结果
线程的运行是确定的

test2.c
在线程中打印开始时间和结束时间
Join第二个参数接收线程运行时间返回值并打印

test3.c
检查本机的函数可用的局部变量的最大的大小

test4.c
使数据通过pthread_exit以及pthread_join既能输入又能输出

test5.c
验证线程是否共享线程号

test5-1.c






