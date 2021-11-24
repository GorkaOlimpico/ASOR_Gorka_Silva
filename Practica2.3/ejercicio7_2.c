#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char **argv) {

   if(system(argv[1]) == -1){
      perror("Error\n");
   }

   printf("El comando termino de ejecutarse\n");
   return 0;
}

