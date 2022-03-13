#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

extern char* *environ;
void print_env(){
	char **tmp = environ;
	while(*tmp){
		printf("%s\n", *tmp);
		tmp++;
	}
}
int main(){
	print_env();
	*environ = NULL;
	pid_t ret = fork();
	if(ret==0){
		printf("Environment in child:\n");
		print_env();
	}
	return 0;
}
