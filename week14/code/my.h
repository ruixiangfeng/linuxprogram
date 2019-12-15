#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#define check_error(return_val,msg){	\
	if(return_val!=0){	\
		fprintf(stderr,"%s:%s\n",msg,strerror(return_val));\
		exit(-1);\
	}\
}
