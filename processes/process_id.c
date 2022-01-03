#include<stdio.h>
#include<unistd.h>

int main(void){
	pid_t parent, id;
	id = getpid();
	parent = getppid();
	printf("Process id: %d\n", id);
	printf("Parent id: %d\n", parent);
	getchar();
	return 0;

}
