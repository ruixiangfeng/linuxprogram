#include <stdio.h>
int main(int argc,char *argv[]){
	//4
    setvbuf(stdout,NULL,_IONBF,0);
	printf("hello");

    //1
    //printf("hello\n");
	
    //3
    //fclose(stdout);


	while(1);
}
