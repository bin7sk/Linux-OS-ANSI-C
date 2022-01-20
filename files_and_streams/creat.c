#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Usage: ./program file_name\n");
		return 1;
	}
	creat(argv[1], 0777);
	return 0;
}
