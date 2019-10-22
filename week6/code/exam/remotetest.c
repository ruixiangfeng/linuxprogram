
#include "dylib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

#define UNUMBER 100

int main()
{
	int a[UNUMBER];

   

    void *hd;
	char *error;
    void(*f1)(),(*f4)();
	int(*f2)(),(*f3)();
	hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1=dlsym(hd,"show");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}

	f2=dlsym(hd,"max");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}

	f3=dlsym(hd,"sum");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	
	f4=dlsym(hd,"init");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}

    f4(a,UNUMBER);
	f1(a,UNUMBER);	  
    printf("sum=%d\n,max=%d\n",f3(a,UNUMBER),f2(a,UNUMBER));

	if(dlclose(hd)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	return 0;
}
