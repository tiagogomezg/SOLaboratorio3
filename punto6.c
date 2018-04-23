#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	pid_t pid_h;
	pid_t pid_n;
	pid_h = fork();
	if(pid_h==0){
		printf("Mundo");
		fflush( stdout );
		pid_n = fork();
		if(pid_n==0){
			printf("!");
		}
	}else{
		printf("Hola ");
	}
}
