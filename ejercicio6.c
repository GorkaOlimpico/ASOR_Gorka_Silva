include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

   long arg;
   if ((arg = sysconf(1)) == -1){
      printf("Error: %s",  strerror(errno));
      return -1;
   }
   printf("Longitud maxima de los argumentos: %d\n", arg);

   long child;
   if ((child = sysconf(2)) == -1){
      printf("Error: %s",  strerror(errno));
      return -1;
   }
   printf("Numero maximo de hijos: %d\n", child);
   
   long open;
   if ((open = sysconf(6)) == -1){
      printf("Error: %s",  strerror(errno));
      return -1;
   }
   printf("Numero maximo de ficheros abiertos: %d\n", open);

  return 0;
}


