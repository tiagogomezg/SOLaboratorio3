#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[]){
	pid_t pid;
    int status;
    pid = fork(); // Creo el primer hijo
    if (pid== 0) { // Hijo 1
    	printf("SOY EL HIJO\n");
    	char a[50]= "./";
		strcat(a,argv[1]);
		printf("%s\n",a);
    	execl(a,a,NULL);
    }else {  // Padre
		wait(&status);
		printf("SOY EL PADRE\n");
	}
}