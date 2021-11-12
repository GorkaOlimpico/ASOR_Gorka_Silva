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

   dup2(fd,1);
   dup2(fd,2);

   printf("Se ha redirigido la salida del fichero\n", argv[1]);

   return 0;
}
