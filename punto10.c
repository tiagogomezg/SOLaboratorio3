#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <syscall.h>

int main() {
	pid_t  pid_2,pid_3,pid_n4,pid_n5;
	int status_2,status_3,status_n4,status_n5;
	pid_2 = fork();
	if ((pid_2) < 0) {
		perror("fork falló");
		exit(-1);
	}
	else if(pid_2 == 0){
		printf("HIJO1: Mi PID es %d\n", getpid());
		printf("HIJO1: El PID de mi padre es %d\n", getppid());
		printf("HIJO1: Fin!!\n");
		//sleep(30);
	}
	else{
		pid_3 = fork();
		if(pid_3 == 0){
			pid_n4 = fork();
			if ((pid_n4) < 0) {
				perror("fork falló");
				exit(-1);
			}
			else if(pid_n4 == 0){
				printf("NIETO1: Mi PID es %d\n", getpid());
				printf("NIETO1: El PID de mi padre es %d\n", getppid());
				printf("NIETO1: Fin!!\n");
				//sleep(30);
			}else{
				pid_n5 = fork();
				if ((pid_n5) < 0) {
				perror("fork falló");
				exit(-1);
				//sleep(30);
			}
			else if(pid_n5 == 0){
				printf("NIETO2: Mi PID es %d\n", getpid());
				printf("NIETO2: El PID de mi padre es %d\n", getppid());
				printf("NIETO2: Fin!!\n");
				//sleep(30);
			}else{
				wait(&status_n4);
				wait(&status_n5);
				printf("HIJO2: Mi PID es %d\n", getpid());
				printf("HIJO2: El PID de mi padre es %d\n", getppid());
				printf("HIJO2: Fin!!\n");
				//sleep(30);
			}
			}
		}
		else {
			wait(&status_2);
			wait(&status_3);
			execl("bin/pstree", "bin/pstree",getpid(), NULL);
			printf("PADRE: Mi PID es %d\n", getpid());
			printf("PADRE: El PID de mi padre es %d\n", getppid());
			printf("PADRE: Fin!!\n");
			//sleep(30);
			return(0);
		}
	}
	exit(0);
}
