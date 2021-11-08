#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(){
   char *s;
   int i;
   for (i = 0; i < 255; i++){
      printf("Error %d: %s\n", i, strerror(i));
   }
   return 0;
}
