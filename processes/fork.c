#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(void){
	pid_t child_id = fork();
	if(child_id){
		printf("I am parent:\n");
		printf("My id:%d\n", getpid());
		printf("My child:%d\n", child_id);
		putchar('\n');
	}
	else if(!child_id){
		printf("I am child:\n");
		printf("My id: %d\n", getpid());
		printf("My parent id: %d\n", getppid());
	
	}
	else{
		fprintf(stderr, "Fork is not successful");
		return 1;
	}
	return 0;
}
