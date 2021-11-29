#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {

   int fd[2];
   int p = pipe(fd);

   pid_t pid = fork();

   switch(pid){
      case -1:
         perror("Error en fork\n");
         return -1;
         break;

      case 0:
         dup2(fd[0],3);
         close(fd[0]);
         close(fd[1]);
         execlp(argv[3],argv[3], argv[4]);
         break;

      default:
         dup2(fd[1],1);
         close(fd[0]);
         close(fd[1]);
         execlp(argv[1],argv[1], argv[2]);
         break;
   }

   return 0;
}


