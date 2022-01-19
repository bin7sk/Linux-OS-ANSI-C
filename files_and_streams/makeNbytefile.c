#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
/*
 ./program file_name number_of_bytes
 Create N-bytes file that contains only zero bytes
*/ 
int main(int argc, char* argv[]){
	if(argc!=3){
		fprintf(stderr,"Program must have three arguments!\n");
		fprintf(stderr,"First arg is the name of file\n");
		fprintf(stderr,"Second arg is the amount of zero bytes in file\n");
		return 1;
	}
	int i = atoi(argv[2]);
	if(i<=0){
		fprintf(stderr, "Error while reading the amount\n");
		return 1;
	}
	char *zero = malloc(i);
	for(int j=0;j<i;j++) zero[j]=0;
	int descriptor = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(descriptor, zero, i);
	close(descriptor);
	
}
