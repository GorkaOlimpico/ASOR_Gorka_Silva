#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv) {

   pid_t pid = fork();

   if(pid== -1){
      perror("Error en fork\n");
   }
   else if (pid == 0){
      pid_t sid_hijo = setsid();
      printf("Proceso hijo\n");
      int fd = open("/tmp/daemon.out", O_CREAT | O_RDWR, 0777);
      int fd_error = open("/tmp/daemon.err", O_CREAT | O_RDWR, 0777);
      int fd_null = open("/dev/null", O_CREAT | O_RDWR, 0777);
      int fd2 = dup2(fd, 1);
      int fd3 = dup2(fd_error, 2);
      int fd4 = dup2(fd_null, 0);

      if(execvp(argv[1], argv + 1) == -1){
         perror("Error\n");
      }
   }
   else{
      printf("Termina el padre\n");
   }

   return 0;
}

