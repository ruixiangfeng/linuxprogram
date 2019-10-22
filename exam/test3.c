#include <unistd.h>
#include <iostream>
#include <fcnt1.h>
#include <string>
#include <sys/stat.h>
using namespace std;

int main(){
	int fd;
	FILE *file;
	char *s="hello,world\n";
	if((fd=open("test.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1){
		count<<"Error open File"<<endl;
		return -1; 	
	
	}
	if((file=open("test2.txt","w+"))==NULL){
		count<<"Error open File"<<endl;
		return -1; 	
	
	}
	count<<"FIle has been Opened."<<endl;
	sleep(15);
    if(write(fd,s,strlen(s))<strlen(s)){
		count<<"Write Error"<<endl;
		return -1;
	}
	if(fwrite(s,sizeof(char),strlen(s),file)<strlen(s)){
		count<<"Write Error in 2."<<endl;
		return -1;
	}
	count<<"After write"<<endl;
	sleep(15);
	count<<"After sleep."<<endl;
	close(fd);
    return 0;

}
