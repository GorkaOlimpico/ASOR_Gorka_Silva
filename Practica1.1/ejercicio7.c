include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/utsname.h>


int main(){

   char path = '/';

   long link;

   if((link = pathconf(&path,1)) == -1){
      printf("Error: %s",  strerror(errno));
      return -1;
   }
   else{
       printf("Maximo numero de enlaces: %d\n", link);
   }

   long max;

   if((max = pathconf(&path,5)) == -1){
      printf("Error: %s",  strerror(errno));
      return -1;
   }
   else{
    printf("Tamaño maximo de la ruta: %d\n", max);
   }

   long name;

   if((name = pathconf(&path,4)) == -1){
      printf("Error: %s",  strerror(errno));
      return -1;
   }
   else{
      printf("Tamaño maximo del nombre de un fichero: %d\n", name);
   }
   
   return 0;
}





