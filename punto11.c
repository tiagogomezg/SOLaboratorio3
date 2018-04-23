#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fact (int n);

int main () {
    pid_t pid_hijo1; 
    pid_t pid_hijo2; 
    pid_t pid_hijo3;
    int status_1,status_2,status_3;
    pid_hijo1 = fork(); // Creo el primer hijo
    if (pid_hijo1 == 0) { // Hijo 1
      for(int i=1; i<=10;i++){
        printf("HIJO 1: fact(%d) = %d \n", i, fact(i) );
      }
    } else {  // Padre
        pid_hijo2 = fork(); // Creo al segundo hijo
        if (pid_hijo2 == 0) { // Hijo 2
          for(int i=1; i<=10;i++){
            printf("HIJO 2: fact(%d) = %d \n", i, fact(i) );
          }
        } else {  // Padre
            pid_hijo3 = fork();  // Creo al tercer hijo
            if (pid_hijo3 == 0) { // Hijo 3
              for(int i=1; i<=10;i++){
                printf("HIJO 3: fact(%d) = %d \n", i, fact(i) );
              }
            } else {  // Padre
              wait(&status_1);
              wait(&status_2);
              wait(&status_3);
              printf("Soy el padre\n");
            }
        }
    }
    return 0;
}

int fact (int n){
  if (n<=1){
    return 1;
  }
  else{
    return (n*fact(n-1));
  }
}