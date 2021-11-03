#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main() {
   char *error;
  
   if(setuid(0)== -1){
      error = strerror(errno);
      printf("Codigo numerico: %d, Codigo cadena: %s", errno, error);
   }
   return 1;
}
