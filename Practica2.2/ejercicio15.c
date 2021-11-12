#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){

   int fd = open(argv[1], O_CREAT | O_RDWR, 0777);
   if (fd == -1){
      printf("Error al abrir el archivo\n");
      return -1;
   }

   if(lockf(fd, F_TEST, 0)==0){
      lockf(fd, F_LOCK, 0);
      sleep(30);
      lockf(fd, F_ULOCK,0);
   }
  
   return 0;
}


