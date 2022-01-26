#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
void usage_error(int status){
	fprintf(stderr, "Usage:\n./program file number_of_bytes_to_read\n");
	exit(status);
}

int main(int argc, char* argv[]){
	if(argc!=3) usage_error(1);
	int fd = open(argv[1], O_RDONLY);
	if(fd==-1){
		perror(argv[1]);
		return 2;
	}
	int bytes = atoi(argv[2]);
	char* buffer = malloc(bytes);
	if(buffer == NULL){
		fprintf(stderr, "error when allocating memory\n");
		return 3;
	}
	int rd = read(fd, buffer, bytes);
	if(rd!=bytes){
		fprintf(stderr, "Can't read %d bytes from file\n", bytes);
		return 4;
	}
	for(int i=0;i<bytes;i++){
		printf("%x\n",buffer[i]);
	}
	close(fd);
	return 0;
}
