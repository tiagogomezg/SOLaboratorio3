#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc, char *argv[]) {
  pid_t pid_h1, pid_h2;
  pid_h1 = fork();
  if(pid_h1 == 0) {
    // Proceso hijo el cual ejecuta el comando ls
    execl("/bin/noexisto","/bin/noexisto",NULL);
  }
  else {
    pid_h2 = fork();
    if(pid_h2 == 0) {     
      // Proceso hijo que ejecuta el comando date
      execl("/bin/ls","/bin/ls","-l",NULL);
    }
  }
  return 0;
}
